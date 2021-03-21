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

#ifndef CONIX_INFO_H
#define CONIX_INFO_H

#include "common.h"

#define info_foreach(info, item, body) \
    do { \
        foreach(_index, 0, (info).length) { \
            InfoItem item = (info).values[_index]; \
            body; \
        } \
    } while(0)

typedef struct t_Info Info;
typedef struct t_InfoItem InfoItem;

struct t_Info {
    size_t size;
    size_t length;
    InfoItem* values;
};

struct t_InfoItem {
    const char* name;
    const char* description;
};

extern void info_init(Info* info);
extern void info_free(Info* info);

extern void info_put(Info* info, InfoItem item);

#endif // CONIX_INFO_H
