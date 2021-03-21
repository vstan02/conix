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

#include <glib.h>

#include "test.h"
#include "info.h"

static void cmp_next(Info*, InfoItem);

static void test_info_main(void);

extern void add_info_tests(void) {
    g_test_add_func(TEST_INFO_PATH, test_info_main);
}

static void test_info_main(void) {
    Info info;
    InfoItem items[] = {
        { "first", "First item" },
        { "second", "Second item" },
        { "third", "Third item" }
    };

    info_init(&info);

    info_put(&info, items[0]);
    info_put(&info, items[1]);
    info_put(&info, items[2]);

    cmp_next(&info, items[0]);
    cmp_next(&info, items[1]);
    cmp_next(&info, items[2]);

    info_free(&info);
}

static void cmp_next(Info* info, InfoItem item) {
    static size_t i = 0;
    if (i < info->length) {
        InfoItem current = info->values[i++];
        g_assert_cmpstr(current.name, ==, item.name);
        g_assert_cmpstr(current.description, ==, item.description);
    }
}
