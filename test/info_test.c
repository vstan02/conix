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

#include "test.h"
#include "info.h"

static void test_info_main(void);

extern void add_info_tests(void) {
    g_test_add_func(TEST_INFO_PATH, test_info_main);
}

static void test_info_main(void) {
    info_t info;
    info_item_t items[] = {
        { "3", "Third item" },
        { "2", "Second item" },
        { "1", "First item" }
    };

    info_init(&info);

    foreach(i, 0, 3) {
        info_put(&info, items[i]);
    }

    size_t index = info.length;
    info_foreach(info, item, {
        --index;
        g_assert_cmpstr(item.name, ==, items[index].name);
        g_assert_cmpstr(item.description, ==, items[index].description);
    });

    info_free(&info);
}
