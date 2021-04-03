/* Handlers - A collection of cli handlers
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

#include "handlers.h"

struct t_HandlerStore {
    Handler data;
    HandlerStore* next;
};

static size_t hash(const char*);

extern void handlers_init(Handlers* handlers) {
    foreach(i, 0, HANDLER_STORES) {
        handlers->stores[i] = NULL;
    }
}

extern void handlers_free(Handlers* handlers) {
    foreach(i, 0, HANDLER_STORES) {
        HandlerStore* store = handlers->stores[i];
        while (store != NULL) {
            HandlerStore* current = store;
            store = store->next;
            free(current);
        }
    }
}

extern void handlers_put(Handlers* handlers, Handler handler) {
    HandlerStore* store = (HandlerStore*) malloc(sizeof(HandlerStore));
    store->data = handler;

    size_t index = hash(handler.id);
    store->next = handlers->stores[index];
    handlers->stores[index] = store;
}

static size_t hash(const char* string) {
    size_t result = 0;
    while (*string) result += *(string++);
    return result % HANDLER_STORES;
}
