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

#define destroyer(func) ((void (*)(void*)) func)
#define tokenize(target, delimit, token, body) \
    { \
        char* token = strtok(conix_str_copy(target), delimit); \
        while (token) { \
            body; \
            token = strtok(NULL, delimit); \
        } \
    }

typedef struct t_ConixInfo ConixInfo;

struct t_Conix {
    const char* name;
    int argc;
    const char** argv;
    Map* options;
    List* info;
    size_t max_size;
    ConixHandler* def_handler;
};

struct t_ConixInfo {
    const char* name;
    const char* description;
};

static char* conix_str_copy(const char*);
static ConixInfo* conix_info_create(const char*, const char*);

static void conix_help(Conix* self);

extern Conix* conix_create(const char* app, int argc, const char** argv) {
    Conix* self = (Conix*) malloc(sizeof(Conix));
    self->name = app;
    self->argc = argc;
    self->argv = argv;
    self->max_size = 0;
    self->options = map_create();
    self->info = list_create();
    self->def_handler = conix_handler_create((void (*)(void*)) conix_help, self);

    conix_add_option(self, (ConixOption) {
        .name = "-h, --help",
        .description = "Display this information",
        .handler = self->def_handler
    });
    return self;
}

extern void conix_destroy(Conix* self) {
    if (self) {
        map_destroy(self->options);
        list_destroy(self->info, destroyer(conix_info_create));
        free(self);
    }
}

extern void conix_run(Conix* self) {
    if (self) {
        if (self->argc > 1) {
            ConixHandler* handler = (ConixHandler*) map_get(self->options, self->argv[1]);
            return handler != NULL
                ? handler->handle(handler->payload)
                : self->def_handler->handle(self->def_handler->payload);
        }
        self->def_handler->handle(self->def_handler->payload);
    }
}

extern void conix_set_default(Conix* self, ConixHandler* handler) {
    if (self) {
        self->def_handler = handler;
    }
}

extern void conix_add_option(Conix* self, ConixOption option) {
    if (self) {
        size_t size = strlen(option.name);
        if (size > self->max_size) {
            self->max_size = size;
        }

        list_push(self->info, conix_info_create(option.name, option.description));
        tokenize(option.name, OPTION_DELIMIT, id, {
            map_put(self->options, id, option.handler);
        })
    }
}

extern void conix_add_options(Conix* self, size_t count, ConixOption* options) {
    for (size_t index = 0; index < count; ++index) {
        conix_add_option(self, options[index]);
    }
}

extern ConixHandler* conix_handler_create(void (*handle)(void*), void* payload) {
    ConixHandler* handler = (ConixHandler*) malloc(sizeof(ConixHandler));
    handler->handle = handle;
    handler->payload = payload;
    return handler;
}

static char* conix_str_copy(const char* string) {
    size_t size = strlen(string) + 1;
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

static void conix_info_destroy(ConixInfo* info) {
    if (info) {
        free((void*) info->name);
        free((void*) info->description);
        free(info);
    }
}

static void conix_help(Conix* self) {
    printf("Usage: %s [option]\nOptions:\n", self->name);
    list_foreach(self->info, ConixInfo* item, {
        printf(" %*s %s\n", -(int)(self->max_size + 3), item->name, item->description);
    })
}
