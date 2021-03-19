/* Set test - Tests for set
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
#include "set.h"

static void destroy(value_t);
static void cmp_next(Set*, const char*);

static void test_set_main(void);

extern void add_set_tests(void) {
    g_test_add_func(TEST_SET_PATH, test_set_main);
}

static void test_set_main(void) {
    Set set;
    set_init(&set, (compare_t)strcmp, destroy);

    set_put(&set, "123");
    set_put(&set, "234");
    set_put(&set, "345");

    cmp_next(&set, "123");
    cmp_next(&set, "234");
    cmp_next(&set, "345");

    set_free(&set);
}

static void cmp_next(Set* set, const char* value) {
    static size_t i = 0;
    if (i < set->length) {
        g_assert_cmpstr(set->values[i++], ==, value);
    }
}

static void destroy(value_t data) {}
