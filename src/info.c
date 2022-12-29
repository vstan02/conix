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

#define last_name(info) \
	info->values[info->length - 1].name

#define reallocate(type, array, size) \
	(type*) realloc(array, size * sizeof(type))

static void push(info_t*, size_t, info_item_t);

extern void info_init(info_t* info) {
	info->length = info->size = 0;
	info->values = NULL;
}

extern void info_free(info_t* info) {
	if (info->values == NULL) return;
	info_foreach(*info, item, {
		free((char*) item.name);
		free((char*) item.description);
	});
	free(info->values);
}

extern void info_put(info_t* info, info_item_t value) {
	if (info->values == NULL || strcmp(value.name, last_name(info)) > 0) {
		return push(info, info->length, value);
	}

	info_foreach(*info, current, {
		int diff = strcmp(value.name, current.name);
		if (diff > 0) continue;
		if (diff < 0) return push(info, _index, value);

		free((char*) current.description);
		info->values[_index].description = strdup(value.description);
		return;
	});
}

static void push(info_t* info, size_t index, info_item_t value) {
	if (info->length == info->size) {
		info->size = info->size ? info->size * 2 : BASE_SIZE;
		info->values = reallocate(info_item_t, info->values, info->size);
		if (info->values == NULL) exit(EXIT_FAILURE);
	}

	for (size_t i = info->length; i > index; --i) {
		info->values[i] = info->values[i - 1];
	}

	++info->length;
	info->values[index] = (info_item_t) {
		.name = strdup(value.name),
		.description = strdup(value.description)
	};
}
