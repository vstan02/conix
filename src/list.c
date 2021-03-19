/* List - Simple linked list
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

#include "list.h"

static void list_node_free(ListNode*, destroy_t);

extern void list_init(List* list, destroy_t destroy) {
    list->head = NULL;
    list->destroy = destroy;
}

extern void list_free(List* list) {
    list_node_free(list->head, list->destroy);
}

extern void list_push(List* list, value_t data) {
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    node->data = data;
    node->next = list->head;
    list->head = node;
}

static void list_node_free(ListNode* node, destroy_t destroy) {
    if (node) {
        destroy(node->data);
        list_node_free(node->next, destroy);
        free(node);
    }
}
