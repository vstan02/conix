/* Conix - Command line interface building library
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
 *
 * This file is part of Conix.
 *
 * Conix is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdio.h>

#include "conix.h"
#include "private.h"
#include "module.h"
#include "option.h"
#include "list.h"

PRIVATE_DATA {
    int argc;
    const char** argv;
    List* options;
    Option* def;
};

static void conix_print_args(Conix* self) {
    printf("%i\n", PRIVATE(self)->argc);
    for (size_t index = 0; index < PRIVATE(self)->argc; ++index)
        printf("%s\n", PRIVATE(self)->argv[index]);
}

static void conix_default() {
    printf("I don't know what to do!");
}

void conix_add_option(Conix* self, const char* name, Function handle) {
    if (self) {
        list_push(PRIVATE(self)->options, option_create(name, handle));
    }
}

void conix_run(Conix* self) {
    if (self && PRIVATE(self)->argc > 1) {
        List* options = PRIVATE(self)->options;
        bool found = false;
        list_to_first(options);
        while (list_exists(options)) {
            Option* option = (Option*) list_get(options);
            if (option_search(option, PRIVATE(self)->argv[1])) {
                option_handle(option);
                found = true;
                break;
            }
            list_to_next(options);
        }
        if (!found) {
            option_handle(PRIVATE(self)->def);
        }
    }
}

CONSTRUCTOR(conix, Conix, PARAMS(argc, argv), int argc, const char** argv) {
    PRIVATE_INIT(self);
    PRIVATE(self)->argc = argc;
    PRIVATE(self)->argv = argv;
    PRIVATE(self)->options = list_create();
    PRIVATE(self)->def = option_create("", conix_default);
}

DESTRUCTOR(conix, Conix) {
    option_destroy(PRIVATE(self)->def);
    list_destroy(PRIVATE(self)->options);
    PRIVATE_RESET(self);
}
