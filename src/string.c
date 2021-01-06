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

#include "private.h"
#include "module.h"
#include "string.h"

PRIVATE_DATA {
    uint8_t length;
    char* content;
};

bool string_compare(String* self, const char* target) {
    return !strcmp(PRIVATE(self)->content, target);
}

uint8_t string_get_size(String* self) {
    return self ? PRIVATE(self)->length : 0;
}

const char* string_get_content(String* self) {
    return self ? PRIVATE(self)->content : NULL;
}

CONSTRUCTOR(string, String, PARAMS(content), const char* content) {
    PRIVATE_INIT(self);
    PRIVATE(self)->length = strlen(content);
    PRIVATE(self)->content = (char*) malloc(PRIVATE(self)->length);
    strcpy(PRIVATE(self)->content, content);
}

DESTRUCTOR(string, String) {
    free(PRIVATE(self)->content);
    PRIVATE_RESET(self);
}
