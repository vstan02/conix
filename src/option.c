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

#include <malloc.h>

#include "option.h"
#include "private.h"

PRIVATE_DATA {};

void option_init(Option* self) {
    PRIVATE_INIT(self);
}

Option* option_create(void) {
    Option* self = (Option*) malloc(sizeof(Option));
    option_init(self);
    return self;
}

void option_reset(Option* self) {
    PRIVATE_RESET(self);
}

void option_destroy(Option* self) {
    if (self) {
        option_reset(self);
        free(self);
    }
}
