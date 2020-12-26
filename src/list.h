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

#ifndef CONIX_LIST_H
#define CONIX_LIST_H

#include <inttypes.h>
#include <stdbool.h>

typedef struct t_List List;
typedef struct t_ListNode ListNode;

struct t_ListNode {
    void* data;
    ListNode* next;
};

struct t_List {
    void* private;
};

int8_t list_get_size(List* self);
bool list_is_empty(List* self);

bool list_exists(List* self);
void* list_get(List* self);

void list_to_first(List* self);
void list_to_next(List* self);

void list_push(List* self, void* value);

void list_init(List* self);
List* list_create(void);

void list_reset(List* self);
void list_destroy(List* self);

#endif // CONIX_LIST_H
