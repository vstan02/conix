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

#define BASE_SIZE 4

#define info_last(info) \
    info->values[info->length - 1]

static void info_push(Info*, size_t, InfoItem);

extern void info_init(Info* info) {
    info->length = info->size = 0;
    info->values = NULL;
}

extern void info_free(Info* info) {
    if (info->values == NULL) return;
    info_foreach(*info, item, {
        free((char*) item.name);
        free((char*) item.description);
    });
    free(info->values);
}

extern void info_put(Info* info, InfoItem value) {
    if (info->values == NULL || strcmp(value.name, info_last(info).name) > 0) {
        return info_push(info, info->length, value);
    }

    info_foreach(*info, current, {
        int diff = strcmp(value.name, current.name);
        if (diff > 0) continue;
        if (diff < 0) return info_push(info, _index, value);

        free((char*) current.description);
        current.description = str_copy(value.description);
        return;
    });
}

static void info_push(Info* info, size_t index, InfoItem value) {
    if (info->length == info->size) {
        info->size = info->size ? info->size * 2 : BASE_SIZE;
        info->values = (InfoItem*) realloc(info->values, info->size * sizeof(InfoItem));
        if (info->values == NULL) exit(EXIT_FAILURE);
    }

    for (size_t i = info->length; i > index; --i) {
        info->values[i] = info->values[i - 1];
    }

    ++info->length;
    info->values[index] = (InfoItem) {
        .name = str_copy(value.name),
        .description = str_copy(value.description)
    };
}
