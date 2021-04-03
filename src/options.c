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

#include <stdio.h>
#include <string.h>

#include "options.h"

extern void options_init(Options* options) {
    options->max_size = 0;
    info_init(&options->info);
    handlers_init(&options->handlers);
}

extern void options_free(Options* options) {
    info_free(&options->info);
    handlers_free(&options->handlers);
}

extern void options_add(Options* options, Option option) {
    size_t size = strlen(option.name);
    if (size > options->max_size) {
        options->max_size = size;
    }

    info_put(&options->info, (InfoItem) {
        .name = option.name,
        .description = option.description
    });

    tokenize(option.name, ", ", token, {
        handlers_put(&options->handlers, (Handler) {
            .id = token,
            .handle = option.handle,
            .payload = option.payload
        });
    });
}

extern void options_print(Options* options) {
    int size = -(int)(options->max_size + 3);
    printf("Options:\n");
    info_foreach(options->info, info, {
        printf("\t%*s %s\n", size, info.name, info.description);
    });
}
