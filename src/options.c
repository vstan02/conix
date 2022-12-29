/* Options - A collection of cli options
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

#include <stdio.h>
#include <string.h>

#include "options.h"

#define NOT_FOUND "*"

extern void options_init(options_t* options, void* payload) {
	options->max_size = 0;
	options->payload = payload;

	info_init(&options->info);
	handlers_init(&options->handlers);
}

extern void options_free(options_t* options) {
	info_free(&options->info);
	handlers_free(&options->handlers);
}

extern void options_add(options_t* options, option_t option) {
	if (strcmp(NOT_FOUND, option.name) != 0) {
		size_t size = strlen(option.name);
		if (size > options->max_size) {
			options->max_size = size;
		}

		info_put(&options->info, (info_item_t) {
			.name = option.name,
			.description = option.description
		});
	}

	tokenize(option.name, ", ", token, {
		handlers_put(&options->handlers, (handler_t) {
			.id = token,
			.handle = option.handle,
			.payload = option.payload
		});
	});
}

extern void options_run(options_t* options, const char* option) {
	handler_t* result = handlers_get(&options->handlers, option);
	if (result != NULL) {
		return result->handle(options->payload, result->payload);
	}

	result = handlers_get(&options->handlers, NOT_FOUND);
	if (result != NULL) {
		return result->handle(options->payload, result->payload);
	}
}

extern void options_print(options_t* options) {
	int size = -(int)(options->max_size + 1);
	printf("Options:\n");
	info_foreach(options->info, info, {
		printf("    %*s  %s\n", size, info.name, info.description);
	});
}
