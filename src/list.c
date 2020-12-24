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

#include "list.h"
#include "private.h"
#include "module.h"

PRIVATE_DATA {
    ListNode* first;
    ListNode* current;
    int8_t length;
};

static ListNode* list_create_node(void* data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = NULL;
    return node;
}

static void list_destroy_node(ListNode* node) {
    if (node) {
        list_destroy_node(node->next);
        free(node);
    }
}

static void list_set_nodes(List* self, ListNode* node) {
    PRIVATE(self)->first = PRIVATE(self)->current = node;
}

int8_t list_get_size(List* self) {
    return self ? PRIVATE(self)->length : 0;
}

bool list_is_empty(List* self) {
    return !list_get_size(self);
}

bool list_exists(List* self) {
    return self && PRIVATE(self)->current;
}

void* list_get(List* self) {
    return list_get_size(self) ? PRIVATE(self)->current->data : NULL;
}

void list_to_next(List* self) {
    if (PRIVATE(self)->current) {
        PRIVATE(self)->current = PRIVATE(self)->current->next;
    }
}

void list_push(List* self, void* value) {
    if (self) {
        ListNode* node = list_create_node(value);
        if (list_is_empty(self)) {
            list_set_nodes(self, node);
        } else {
            node->next = PRIVATE(self)->first;
            PRIVATE(self)->first->next = node;
            PRIVATE(self)->first = node;
        }
        ++PRIVATE(self)->length;
    }
}

CONSTRUCTOR(list, List, PARAMS()) {
    PRIVATE_INIT(self);
    PRIVATE(self)->length = 0;
    list_set_nodes(self, NULL);
}

DESTRUCTOR(list, List) {
    list_destroy_node(PRIVATE(self)->first);
    PRIVATE_RESET(self);
}
