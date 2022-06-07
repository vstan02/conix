/* Handlers - A collection of cli handlers
 * Copyright (C) 2021-2022 Stan Vlad <vstan02@protonmail.com>
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

#include "handlers.h"

struct handler_store {
    handler_t data;
    handler_store_t* next;
};

static size_t hash(const char*);

extern void handlers_init(handlers_t* handlers) {
    foreach(i, 0, HANDLER_STORES) {
        handlers->stores[i] = NULL;
    }
}

extern void handlers_free(handlers_t* handlers) {
    foreach(i, 0, HANDLER_STORES) {
        handler_store_t* store = handlers->stores[i];
        while (store != NULL) {
            handler_store_t* current = store;
            store = store->next;
            free(current);
        }
    }
}

extern void handlers_put(handlers_t* handlers, handler_t handler) {
    handler_store_t* store = (handler_store_t*) malloc(sizeof(handler_store_t));
    store->data = handler;

    size_t index = hash(handler.id);
    store->next = handlers->stores[index];
    handlers->stores[index] = store;
}

extern handler_t* handlers_get(handlers_t* handlers, const char* id) {
    handler_store_t* store = handlers->stores[hash(id)];
    while (store != NULL) {
        if (!strcmp(store->data.id, id)) {
            return &store->data;
        }
        store = store->next;
    }
    return NULL;
}

static size_t hash(const char* string) {
    size_t result = 0;
    while (*string) result += *(string++);
    return result % HANDLER_STORES;
}
