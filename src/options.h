/* Options - A collection of cli options
 * Copyright (C) 2021 Stan Vlad <vstan02@protonmail.com>
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

#ifndef CONIX_OPTIONS_H
#define CONIX_OPTIONS_H

#include "info.h"
#include "handlers.h"

typedef struct option option_t;
typedef struct options options_t;

struct options {
    info_t info;
    handlers_t handlers;
    size_t max_size;
};

struct option {
    const char* name;
    const char* description;
    handle_t handle;
    void* payload;
};

extern void options_init(options_t* options);
extern void options_free(options_t* options);

extern void options_print(options_t* options);

extern void options_add(options_t* options, option_t option);
extern void options_run(options_t* options, const char* option);

#endif // CONIX_OPTIONS_H
