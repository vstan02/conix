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

#include <string.h>

#include "option.h"
#include "private.h"
#include "module.h"
#include "list.h"
#include "string.h"

PRIVATE_DATA {
    List* id_list;
    Callback handler;
};

static void option_parse_name(Option* self, const char* name) {
    char delim[] = ", ";
    uint8_t size = strlen(name);
    char target[size];
    strcpy(target, name);

    char* token = strtok(target, delim);
    while (token) {
        list_push(PRIVATE(self)->id_list, string_create(token));
        token = strtok(NULL, delim);
    }
}

bool option_search(Option* self, const char* id) {
    List* id_list = PRIVATE(self)->id_list;
    list_to_first(id_list);
    while (list_exists(id_list)) {
        String* item = (String*) list_get(id_list);
        if (string_compare(item, id)) return true;
        list_to_next(id_list);
    }
    return false;
}

void option_handle(Option* self) {
    if (self) PRIVATE(self)->handler();
}

CONSTRUCTOR(option, Option, PARAMS(name, handler), const char* name, Callback handler) {
    PRIVATE_INIT(self);
    PRIVATE(self)->id_list = list_create();
    PRIVATE(self)->handler = handler;
    option_parse_name(self, name);
}

DESTRUCTOR(option, Option) {
    list_destroy(PRIVATE(self)->id_list);
    PRIVATE_RESET(self);
}
