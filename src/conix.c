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

struct t_CnxCli {
    size_t argc;
    const char** argv;
    CnxApp app;
    Options options;
};

extern CnxCli* cnx_cli_init(CnxApp app, size_t argc, const char** argv) {
    CnxCli* cli = (CnxCli*) malloc(sizeof(CnxCli));
    cli->app = app;
    cli->argc = argc;
    cli->argv = argv;
    options_init(&cli->options);
    return cli;
}

extern void cnx_cli_free(CnxCli* cli) {
    if (cli) {
        options_free(&cli->options);
        free(cli);
    }
}

extern void cnx_cli_run(CnxCli* cli) {
    options_add(&cli->options, (Option) {
        .name = "-h, --help", .description = "Display this information"
    });
    options_add(&cli->options, (Option) {
        .name = "-v, --version", .description = "Display version information"
    });
    options_add(&cli->options, (Option) {
        .name = "-a, --about", .description = "Display other information"
    });

    printf("Usage: %s [options]\n\n", cli->app.name);
    options_print(&cli->options);
}
