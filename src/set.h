/* Set - Set of unique values, without any particular order
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
 *
 * This file is part of Conix.
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

#ifndef CONIX_SET_H
#define CONIX_SET_H

#include "attrs.h"
#include "bool.h"

#define set_foreach(self, item, body) \
    { \
        set_first(self); \
        while (set_exists(self)) { \
            item = set_next(self); \
            body; \
        } \
    }

typedef struct t_Set Set;
typedef int (*Compare)(void*, void*);
typedef void (*Destroy)(void*);

extern Set* set_create(void);
extern void set_destroy(Set* self, Destroy destroy);

extern NONNULL(1) bool set_exists(Set* self);
extern NONNULL(1) void set_first(Set* self);

extern NONNULL(1) void* set_next(Set* self);
extern NONNULL(1) void set_put(Set* self, void* value, Compare compare);

#endif // CONIX_SET_H
