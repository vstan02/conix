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

#ifndef CONIX_LIST_H
#define CONIX_LIST_H

#include "common.h"

#define list_foreach(list, item, body) \
    do { \
        ListNode* _current = list.head; \
        while (_current != NULL) { \
            item = _current->data; \
            body; \
        } \
    } while(0)

typedef struct t_List List;
typedef struct t_ListNode ListNode;

struct t_ListNode {
    value_t data;
    ListNode* next;
};

struct t_List {
    ListNode* head;
    destroy_t destroy;
};

extern void list_init(List* list, destroy_t destroy);
extern void list_free(List* list);

extern void list_push(List* list, value_t data);

#endif // CONIX_LIST_H
