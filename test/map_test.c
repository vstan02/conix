/* Map test - Tests for hash map
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
#include "map.h"

static void test_map_map(void);
static void test_map_put_get(void);

void test_map(void) {
    g_test_add_func(TEST_MAP_PATH "/map", test_map_map);
    g_test_add_func(TEST_MAP_PATH "/put & get", test_map_put_get);
}

static void test_map_map(void) {
    Map* map = map_create();
    g_assert_nonnull(map);
    map_destroy(map);
}

static void test_map_put_get(void) {
    Map* map = map_create();
    map_put(map, "1", "434");
    map_put(map, "2", "349");
    map_put(map, "3", "555");
    g_assert_cmpstr(map_get(map, "2"), ==, "349");
    g_assert_cmpstr(map_get(map, "1"), ==, "434");
    g_assert_cmpstr(map_get(map, "3"), ==, "555");
    g_assert_null(map_get(map, "test"));
    map_destroy(map);
}
