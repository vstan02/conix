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
#define DEFAULT_OPTION "--default"

#define destroyer(function) ((void (*)(void*)) function)

#define handler(function, payload) \
    conix_handler_create((void (*)(void*)) function, payload)

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
    ConixApp app;
    int argc;
    const char** argv;
    Map* options;
    List* info;
    size_t max_size;
};

struct t_ConixInfo {
    const char* name;
    const char* description;
};

static char* conix_str_copy(const char*);
static ConixInfo* conix_info_create(const char*, const char*);
static void conix_info_destroy(ConixInfo*);

static void conix_help(Conix* self);
static void conix_version(Conix* self);
static void conix_not_found(Conix* self);

extern Conix* conix_create(ConixApp app, int argc, const char** argv) {
    Conix* self = (Conix*) malloc(sizeof(Conix));
    self->app = app;
    self->argc = argc;
    self->argv = argv;
    self->max_size = 0;
    self->options = map_create();
    self->info = list_create();
    conix_add_options(self, 2, (ConixOption[]) {
        { "-h, --help", "Display this information", handler(conix_help, self) },
        { "-v, --version", "Display version information", handler(conix_version, self) },
    });
    return self;
}

extern void conix_destroy(Conix* self) {
    if (self) {
        map_destroy(self->options);
        list_destroy(self->info, destroyer(conix_info_destroy));
        free(self);
    }
}

extern void conix_run(Conix* self) {
    if (self) {
        const char* option = self->argc > 1 ? self->argv[1] : DEFAULT_OPTION;
        ConixHandler* handler = (ConixHandler*) map_get(self->options, option);
        return handler != NULL
            ? handler->handle(handler->payload)
            : conix_not_found(self);
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
    printf("Usage: %s [option]\nOptions:\n", self->app.name);
    list_foreach(self->info, ConixInfo* item, {
        printf(" %*s %s\n", -(int)(self->max_size + 3), item->name, item->description);
    })
}

static void conix_version(Conix* self) {
    printf("%s v%s\n", self->app.name, self->app.version);
}

static void conix_not_found(Conix* self) {
    ConixHandler* handler = (ConixHandler*) map_get(self->options, "*");
    if (handler) {
        return handler->handle(handler->payload);
    }
    printf("%s: Invalid option!\n", self->app.name);
}
