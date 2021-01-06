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

#ifndef CONIX_OPTION_H
#define CONIX_OPTION_H

#include <stdbool.h>

typedef struct t_Option Option;
typedef void (*Callback)(void);

struct t_Option {
    void* private;
};

bool option_search(Option* self, const char* id);
void option_handle(Option* self);

void option_init(Option* self, const char* name, Callback handler);
Option* option_create(const char* name, Callback handler);

void option_reset(Option* self);
void option_destroy(Option* self);

#endif // CONIX_OPTION_H
