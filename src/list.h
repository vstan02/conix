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

#ifndef CONIX_LIST_H
#define CONIX_LIST_H

#include <stddef.h>

#include "bool.h"
#include "attrs.h"

typedef struct t_List List;

extern List* list_create(void);
extern void list_destroy(List* self);

extern NONNULL(1) bool list_exists(List* self);
extern NONNULL(1) void* list_get(List* self);

extern NONNULL(1) void list_head(List* self);
extern NONNULL(1) void list_next(List* self);

extern NONNULL(1) void list_push(List* self, void* data);

#define list_foreach(self, item, body) \
    { \
        list_head(self); \
        while (list_exists(self)) { \
            item = list_get(self); \
            body; \
            list_next(self); \
        } \
    }

#endif // CONIX_LIST_H
