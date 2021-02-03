/* Map - Hash map
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
 *
 * This file is part of xCalc.
 *
 * xCalc is free software: you can redistribute it and/or modify
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

#include "map.h"
#include "list.h"

#define STORE_SIZE 10

typedef struct t_MapItem MapItem;

struct t_Map {
    List* store[STORE_SIZE];
};

struct t_MapItem {
    void* value;
    const char* key;
};

static size_t map_hash(const char*);
static MapItem* map_item_create(const char*, void*);

extern Map* map_create(void) {
    return (Map*) malloc(sizeof(Map));
}

extern void map_destroy(Map* self) {
    if (self) free(self);
}

extern void* map_get(Map* self, const char* key) {
    List* list = self->store[map_hash(key)];
    if (!list) return NULL;
    list_foreach(list, MapItem* item, {
        if (!strcmp(item->key, key)) {
            return item->value;
        }
    })
    return NULL;
}

extern void map_put(Map* self, const char* key, void* value) {
    size_t id = map_hash(key);
    MapItem* target = map_item_create(key, value);
    if (!self->store[id]) {
        self->store[id] = list_create();
    }
    list_push(self->store[id], target);
}

static size_t map_hash(const char* target) {
    return strlen(target) % STORE_SIZE;
}

static MapItem* map_item_create(const char* key, void* value) {
    MapItem* item = (MapItem*) malloc(sizeof(MapItem));
    item->key = key;
    item->value = value;
    return item;
}
