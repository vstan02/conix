/* Conix - Command line interface building library
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

#ifndef CONIX_CONIX_H
#define CONIX_CONIX_H

#include <stddef.h>

typedef struct cnx_cli cnx_cli_t;
typedef struct cnx_app cnx_app_t;
typedef struct cnx_ctx cnx_ctx_t;
typedef struct cnx_option cnx_option_t;
typedef void(*cnx_handle_t)(cnx_ctx_t*, void*);

struct cnx_app {
    const char* name;
    const char* version;
};

struct cnx_ctx {
    cnx_app_t app;
    size_t argc;
    const char** argv;
};

struct cnx_option {
    const char* name;
    const char* description;
    cnx_handle_t handle;
    void* payload;
};

extern cnx_cli_t* cnx_cli_init(cnx_app_t app);
extern void cnx_cli_free(cnx_cli_t* cli);

extern void cnx_cli_run(cnx_cli_t* cli, size_t argc, const char* argv[]);

extern void cnx_cli_add(cnx_cli_t* cli, size_t count, cnx_option_t options[]);

#endif // CONIX_CONIX_H
