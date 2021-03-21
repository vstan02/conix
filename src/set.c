/* Set - Set of unique values
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

#include <stdlib.h>

#include "set.h"

static void set_resize(Set*);
static void set_push(Set*, size_t, value_t);

extern void set_init(Set* set, compare_t compare, destroy_t destroy) {
    set->length = set->size = 0;
    set->values = NULL;
    set->compare = compare;
    set->destroy = destroy;
}

extern void set_free(Set* set) {
    foreach(i, 0, set->length)
        set->destroy(set->values[i]);
    free(set->values);
}

extern void set_put(Set* set, value_t value) {
    foreach(i, 0, set->length) {
        int difference = set->compare(value, set->values[i]);
        if (difference > 0) continue;
        return difference
            ? set_push(set, i, value)
            : (set->values[i] = value);
    }
    set_push(set, set->length, value);
}

static void set_push(Set* set, size_t index, value_t value) {
    if (set->length == set->size) set_resize(set);
    for (size_t i = set->length; i > index; --index)
        set->values[i] = set->values[i - 1];
    ++set->length;
    set->values[index] = value;
}

static void set_resize(Set* set) {
    set->size = set->size < 8 ? 8 : set->size * 2;
    set->values = realloc(set->values, set->size);
    if (set->values == NULL) exit(1);
}
