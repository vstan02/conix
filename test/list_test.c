/* List test - Tests for simple linked list
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
#include "list.h"

static void destroy(value_t);
static void cmp_next(ListNode**, const char*);

static void test_list_main(void);

extern void add_list_tests(void) {
    g_test_add_func(TEST_LIST_PATH, test_list_main);
}

static void test_list_main(void) {
    List list;
    list_init(&list, destroy);

    list_push(&list, "123");
    list_push(&list, "234");
    list_push(&list, "345");

    ListNode* node = list.head;
    cmp_next(&node, "345");
    cmp_next(&node, "234");
    cmp_next(&node, "123");

    list_free(&list);
}

static void cmp_next(ListNode** node, const char* value) {
    if (*node != NULL) {
        g_assert_cmpstr((*node)->data, ==, value);
        *node = (*node)->next;
    }
}

static void destroy(value_t data) {}
