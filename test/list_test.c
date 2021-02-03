/* List test - Tests for simple linked list
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
 *
 * This file is part of xCalc.
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

#include <glib.h>

#include "test.h"
#include "list.h"

static void test_list_list(void);
static void test_list_exists(void);
static void test_list_push(void);
static void test_list_get(void);

void test_list(void) {
    g_test_add_func(TEST_LIST_PATH "/list", test_list_list);
    g_test_add_func(TEST_LIST_PATH "/get", test_list_get);
    g_test_add_func(TEST_LIST_PATH "/exists", test_list_exists);
    g_test_add_func(TEST_LIST_PATH "/push", test_list_push);
}

static void test_list_list(void) {
    List* list = list_create();
    g_assert_nonnull(list);
    list_destroy(list);
}

static void test_list_exists(void) {
    List* list = list_create();
    list_head(list);
    g_assert_false(list_exists(list));
    list_destroy(list);
}

static void test_list_push(void) {
    List* list = list_create();
    list_push(list, "123");
    list_push(list, "234");

    list_head(list);
    g_assert_true(list_exists(list));
    list_destroy(list);
}

static void test_list_get(void) {
    List* list = list_create();
    list_push(list, "123");
    list_push(list, "234");
    list_push(list, "345");

    list_head(list);
    g_assert_cmpstr(list_get(list), ==, "345");
    list_next(list);
    g_assert_cmpstr(list_get(list), ==, "234");
    list_next(list);
    g_assert_cmpstr(list_get(list), ==, "123");
    list_destroy(list);
}
