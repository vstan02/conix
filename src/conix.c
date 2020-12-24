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
#include <malloc.h>

#include "conix.h"
#include "private.h"
#include "module.h"

PRIVATE_DATA {
    int argc;
    const char** argv;
};

static void conix_print_args(Conix* self) {
    printf("%i\n", PRIVATE(self)->argc);
    for (size_t index = 0; index < PRIVATE(self)->argc; ++index)
        printf("%s\n", PRIVATE(self)->argv[index]);
}

void conix_run(Conix* self) {
    conix_print_args(self);
}

CONSTRUCTOR(conix, Conix, PARAMS(argc, argv), int argc, const char** argv) {
    PRIVATE_INIT(self);
    PRIVATE(self)->argc = argc;
    PRIVATE(self)->argv = argv;
}

DESTRUCTOR(conix, Conix) {
    PRIVATE_RESET(self);
}
