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
#include <string.h>

#include "conix.h"
#include "map.h"
#include "list.h"

#define OPTION_DELIMIT ", "

typedef struct t_ConixInfo ConixInfo;

struct t_Conix {
    int argc;
    const char** argv;
    Map* options;
    List* info;
};

struct t_ConixInfo {
    const char* name;
    const char* description;
};

static char* conix_str_copy(const char*);
static ConixInfo* conix_info_create(const char*, const char*);

extern Conix* conix_create(int argc, const char** argv) {
    Conix* self = (Conix*) malloc(sizeof(Conix));
    self->argc = argc;
    self->argv = argv;
    self->options = map_create();
    self->info = list_create();
    return self;
}

extern void conix_destroy(Conix* self) {
    if (self) {
        map_destroy(self->options);
        list_destroy(self->info);
        free(self);
    }
}

extern void conix_run(Conix* self) {}

extern void conix_add_option(Conix* self, ConixOption option) {
    list_push(self->info, conix_info_create(option.name, option.description));

    char* id = strtok(conix_str_copy(option.name), OPTION_DELIMIT);
    while (id) {
        map_put(self->options, id, option.handler);
        id = strtok(NULL, OPTION_DELIMIT);
    }
}

static char* conix_str_copy(const char* string) {
    size_t size = strlen(string);
    char* result = malloc(size * sizeof(char));
    strcpy(result, string);
    return result;
}

static ConixInfo* conix_info_create(const char* name, const char* description) {
    ConixInfo* info = (ConixInfo*) malloc(sizeof(ConixInfo));
    info->name = conix_str_copy(name);
    info->description = conix_str_copy(description);
    return info;
}
