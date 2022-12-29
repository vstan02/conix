/* Handlers test - Tests for the collection of cli handlers
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

#include <glib.h>

#include "test.h"
#include "handlers.h"

static void test_handlers_main(void);

extern void add_handlers_tests(void) {
	g_test_add_func(TEST_HANDLERS_PATH, test_handlers_main);
}

static void test_handlers_main(void) {
	handlers_t handlers;
	handler_t items[] = {
		{ "1", "First item", NULL },
		{ "2", "Second item", NULL },
		{ "3", "Third item", NULL }
	};

	handlers_init(&handlers);

	foreach(i, 0, 3) {
		handlers_put(&handlers, items[i]);
	}

	handler_t* result = handlers_get(&handlers, "45");
	g_assert_null(result);

	foreach(i, 0, 3) {
		result = handlers_get(&handlers, items[i].id);

		g_assert_cmpstr(result->id, ==, items[i].id);
		g_assert_cmpstr(result->payload, ==, items[i].payload);
		g_assert_null(result->handle);
	}

	handlers_free(&handlers);
}
