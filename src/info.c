/* Info - Information about cli options
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
#include <string.h>

#include "info.h"

static void info_resize(Info*);
static void info_push(Info*, size_t, InfoItem);
static void info_set(Info*, size_t, InfoItem);

extern void info_init(Info* info) {
    info->length = 0;
    info->size = 4;
    info->values = calloc(info->size, sizeof(InfoItem));
}

extern void info_free(Info* info) {
    info_foreach(*info, item, {
        free((void*) item.name);
        free((void*) item.description);
    });
    free(info->values);
}

extern void info_put(Info* info, InfoItem value) {
    info_foreach(*info, current, {
        int difference = strcmp(value.name, current.name);
        if (difference > 0) continue;
        if (difference < 0) return info_push(info, _index, value);

        InfoItem* item = info->values + _index;
        free((void*) item->description);
        item->description = str_copy(value.description);
        return;
    });
    info_push(info, info->length, value);
}

static void info_push(Info* info, size_t index, InfoItem value) {
    if (info->length == info->size) info_resize(info);
    for (size_t i = info->length; i > index; --index)
        info->values[i] = info->values[i - 1];

    ++info->length;
    info_set(info, index, value);
}

static void info_resize(Info* info) {
    info->size = info->size * 2;
    info->values = realloc(info->values, info->size * sizeof(InfoItem));
    if (info->values == NULL) exit(EXIT_FAILURE);
}

static void info_set(Info* info, size_t index, InfoItem value) {
    InfoItem* item = info->values + index;
    free((void*) item->name);
    free((void*) item->description);

    item->name = str_copy(value.name);
    item->description = str_copy(value.description);
}
