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

#include <stddef.h>

#include "info.h"

#define HANDLER_STORE_SIZE 10

typedef void (*handle_t)(void*);
typedef struct t_Option Option;
typedef struct t_Options Options;
typedef struct t_Handlers Handlers;

struct t_Options {
    Info info;
    size_t max_size;
    Handlers* store[HANDLER_STORE_SIZE];
};

struct t_Option {
    const char* name;
    const char* description;
    handle_t handle;
    void* payload;
};

struct t_Handlers {
    const char* id;
    void* payload;
    handle_t handle;
    Handlers* next;
};

extern void options_init(Options* options);
extern void options_free(Options* options);

extern void options_print(Options* options);

extern void options_add(Options* options, Option option);

#endif // CONIX_OPTIONS_H
