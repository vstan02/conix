/* List - Simple linked list
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

#include "list.h"

typedef struct t_ListNode ListNode;

struct t_List {
    ListNode* current;
    ListNode* head;
};

struct t_ListNode {
    void* data;
    ListNode* next;
};

static void list_node_destroy(ListNode*);

extern List* list_create(void) {
    List* self = (List*) malloc(sizeof(List));
    self->current = self->head = NULL;
    return self;
}

extern void list_destroy(List* self) {
    if (self) {
        list_node_destroy(self->current);
        free(self);
    }
}

extern bool list_exists(List* self) {
    return (_Bool) self->current;
}

extern void* list_get(List* self) {
    return self->current ? self->current->data : NULL;
}

extern void list_head(List* self) {
    self->current = self->head;
}

extern void list_next(List* self) {
    if (self->current) {
        self->current = self->current->next;
    }
}

extern void list_push(List* self, void* data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = self->head;
    self->head = node;
}

static void list_node_destroy(ListNode* node) {
    if (node) {
        list_node_destroy(node->next);
        free(node);
    }
}
