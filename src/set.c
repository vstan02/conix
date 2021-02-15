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

#include <malloc.h>

#include "set.h"

#define SIZE_STEP 5

#define foreach(index, size) \
    for (size_t index = 0; index < size; ++index)

#define set_resize(target, size) \
    { \
        size = size + SIZE_STEP; \
        target = realloc(target, size * sizeof(void*)); \
    }

struct t_Set {
    int size;
    int length;
    int current;
    void** target;
};

static void set_push(Set*, int, void*);

extern Set* set_create(void) {
    Set* self = (Set*) malloc(sizeof(Set));
    self->size = SIZE_STEP;
    self->length = 0;
    self->current = -1;
    self->target = malloc(SIZE_STEP * sizeof(void*));
    return self;
}

extern void set_destroy(Set* self, Destroy destroy) {
    if (self) {
        foreach(index, self->length)
            destroy(self->target[index]);
        free(self->target);
        free(self);
    }
}

extern bool set_exists(Set* self) {
    return self->current < self->length;
}

extern void set_first(Set* self) {
    self->current = 0;
}

extern void* set_next(Set* self) {
    return self->current < self->length
        ? self->target[self->current++] : NULL;
}

extern void set_put(Set* self, void* value, Compare compare) {
    foreach(i, self->length) {
        int result = compare(value, self->target[i]);
        if (!result) {
            self->target[i] = value;
            return;
        } else if (result < 0) {
            return set_push(self, i, value);
        }
    }
    return set_push(self, self->length, value);
}

static void set_push(Set* self, int index, void* value) {
    if (self->length == self->size)
        set_resize(self->target, self->size)
    for (int i = self->length; i > index; --i)
        self->target[i] = self->target[i - 1];

    ++self->length;
    self->target[index] = value;
}
