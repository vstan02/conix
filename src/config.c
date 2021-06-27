/* Config - A parser for Conix config files
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
#include <stdlib.h>
#include <string.h>

#include "config.h"

#define NAME_SIZE 10
#define VERSION_SIZE 15

static void parse(config_t*, FILE*);
static char* read_field(FILE*, const char*, size_t);

extern config_t config_parse(const char* path) {
    FILE* file = fopen(path, "r");
    if (file == NULL) {
        fputs("Conix - Invalid config file.", stderr);
        exit(0);
    }

    config_t result;
    parse(&result, file);

    fclose(file);
    return result;
}

static void parse(config_t* config, FILE* file) {
    size_t size;

    config->name = (char*) calloc(NAME_SIZE, 1);
    config->version = (char*) calloc(VERSION_SIZE, 1);

    fscanf(file, "name = \"%s version = \"%s", config->name, config->version);
    size = strlen(config->name);
    config->name[size - 1] = '\0';

    size = strlen(config->version);
    config->version[size - 1] = '\0';
}
