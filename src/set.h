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

#ifndef CONIX_SET_H
#define CONIX_SET_H

#include "common.h"

#define set_foreach(set, item, body) \
    do { \
        size_t _index = 0; \
        while (_index < set.length) { \
            item = set.values[_index] \
            body; \
        } \
    } while(0)

typedef struct t_Set Set;

struct t_Set {
    size_t size;
    size_t length;
    value_t* values;

    compare_t compare;
    destroy_t destroy;
};

extern void set_init(Set* set, compare_t compare, destroy_t destroy);
extern void set_free(Set* set);

extern void set_put(Set* set, value_t data);

#endif // CONIX_SET_H
