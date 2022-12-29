/* Info test - Tests for information about cli options
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
#include <string.h>

#include "test.h"
#include "info.h"

static void test_order_of_items(void);
static void test_containing_of_strange_items(void);
static void test_descriptions(void);
static void test_copying_of_items(void);
static void test_length(void);

static const char* get_desc(const info_t*, const char*);

extern void add_info_tests(void) {
	g_test_add_func(TEST_INFO_PATH "/should_have_correct_length", test_length);
	g_test_add_func(TEST_INFO_PATH "/should_contain_items_in_correct_order", test_order_of_items);
	g_test_add_func(TEST_INFO_PATH "/should_copy_the_name_and_description", test_copying_of_items);
	g_test_add_func(TEST_INFO_PATH "/should_not_contain_strange_items", test_containing_of_strange_items);
	g_test_add_func(TEST_INFO_PATH "/should_contain_correct_descriptions", test_descriptions);
}

static void test_order_of_items(void) {
	info_t info;
	info_init(&info);

	size_t size = 3;
	info_item_t items[] = {
		{ "third", "Third description" },
		{ "second", "Second description" },
		{ "first", "First description" }
	};

	foreach(index, 0, size) {
		info_put(&info, items[index]);
	}
	info_foreach(info, item, {
		g_assert_cmpstr(item.name, ==, items[--size].name);
	});

	info_free(&info);
}

static void test_copying_of_items(void) {
	info_t info;
	info_init(&info);

	char desc[] = "Test description";
	info_put(&info, (info_item_t) { "test", desc });

	char* old_desc = strdup(desc);
	desc[2] = 'x';
	g_assert_cmpstr(get_desc(&info, "test"), !=, desc);
	g_assert_cmpstr(get_desc(&info, "test"), ==, old_desc);

	info_free(&info);
}

static void test_descriptions(void) {
	info_t info;
	info_init(&info);

	size_t size = 3;
	info_item_t items[] = {
		{ "third", "Third description" },
		{ "second", "Second description" },
		{ "first", "First description" }
	};

	foreach(index, 0, size) {
		info_put(&info, items[index]);
	}
	info_foreach(info, item, {
		g_assert_cmpstr(item.description, ==, items[--size].description);
	});

	size = info.length;
	items[1] = (info_item_t) { "second", "Second description" };
	info_put(&info, items[1]);
	info_foreach(info, item, {
		g_assert_cmpstr(item.description, ==, items[--size].description);
	});

	info_free(&info);
}

static void test_containing_of_strange_items(void) {
	info_t info;
	info_init(&info);

	g_assert_null(get_desc(&info, "first"));
	g_assert_null(get_desc(&info, "second"));
	g_assert_null(get_desc(&info, "third"));

	info_put(&info, (info_item_t) { "first", "First item" });
	info_put(&info, (info_item_t) { "second", "Second description" });
	info_put(&info, (info_item_t) { "third", "Third description" });

	g_assert_null(get_desc(&info, "test"));
	g_assert_null(get_desc(&info, "First"));
	g_assert_null(get_desc(&info, "First description"));

	info_free(&info);
}

static void test_length(void) {
	info_t info;
	info_init(&info);

	g_assert_cmpint(info.length, ==, 0);

	info_put(&info, (info_item_t) { "first", "First item" });
	info_put(&info, (info_item_t) { "second", "Second description" });
	info_put(&info, (info_item_t) { "third", "Third description" });
	g_assert_cmpint(info.length, ==, 3);

	info_put(&info, (info_item_t) { "first", "Another second description" });
	info_put(&info, (info_item_t) { "third", "Another third description" });
	g_assert_cmpint(info.length, ==, 3);

	info_free(&info);
}

static const char* get_desc(const info_t* info, const char* id) {
	info_foreach(*info, item, {
		if (!strcmp(item.name, id)) {
			return item.description;
		}
	});
	return NULL;
}
