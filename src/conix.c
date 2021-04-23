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

#include <malloc.h>

#include "conix.h"
#include "options.h"

#define DEFAULT_OPTION "--default"

struct t_CnxCli {
    CnxApp app;
    Options options;
};

static void help(CnxCli*);
static void version(CnxCli*);

extern CnxCli* cnx_cli_init(CnxApp app) {
    CnxCli* cli = (CnxCli*) malloc(sizeof(CnxCli));
    cli->app = app;
    options_init(&cli->options);

    cnx_cli_add(cli, 3, (CnxOption[]) {
        { "-h, --help", "Display this information", (handle_t)help, cli },
        { "-v, --version", "Display version information", (handle_t)version, cli },
        { "*", NULL, (handle_t)help, cli }
    });

    return cli;
}

extern void cnx_cli_free(CnxCli* cli) {
    if (cli != NULL) {
        options_free(&cli->options);
        free(cli);
    }
}

extern void cnx_cli_run(CnxCli* cli, size_t argc, const char* argv[]) {
    options_run(&cli->options, argc > 1 ? argv[1] : DEFAULT_OPTION);
}

extern void cnx_cli_add(CnxCli* cli, size_t count, CnxOption options[]) {
    foreach(i, 0, count) {
        options_add(&cli->options, (Option) {
            .name = options[i].name,
            .description = options[i].description,
            .payload = options[i].payload,
            .handle = options[i].handle
        });
    }
}

static void help(CnxCli* cli) {
    printf("Usage: %s [options]\n\n", cli->app.name);
    options_print(&cli->options);
}

static void version(CnxCli* cli) {
    printf("%s v%s\n", cli->app.name, cli->app.version);
}
