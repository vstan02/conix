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

#ifndef CONIX_STRING_H
#define CONIX_STRING_H

#include <inttypes.h>
#include <stdbool.h>

typedef struct t_String String;
struct t_String {
    void* private;
};

bool string_compare(String* self, const char* target);

uint8_t string_get_size(String* self);
const char* string_get_content(String* self);

void string_init(String* self, const char* content);
String* string_create(const char* content);

void string_reset(String* self);
void string_destroy(String* self);

#endif // CONIX_STRING_H
