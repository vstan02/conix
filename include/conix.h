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

typedef struct t_CnxCli CnxCli;
typedef struct t_CnxApp CnxApp;
typedef struct t_CnxOption CnxOption;

struct t_CnxApp {
    const char* name;
    const char* version;
};

struct t_CnxOption {
    const char* name;
    const char* description;
    void (*handle)(void*);
    void* payload;
};

extern CnxCli* cnx_cli_init(CnxApp app);
extern void cnx_cli_free(CnxCli* cli);

extern void cnx_cli_run(CnxCli* cli, size_t argc, const char* argv[]);

extern void cnx_cli_add(CnxCli* cli, size_t count, CnxOption options[]);

#endif // CONIX_CONIX_H
