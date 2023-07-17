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
      info_item_t item = (info).values[_index]; \
      body; \
    } \
  } while (0)

typedef struct info info_t;
typedef struct info_item info_item_t;

struct info {
  size_t size;
  size_t length;
  info_item_t* values;
};

struct info_item {
  const char* name;
  const char* description;
};

extern void info_init(info_t* info);
extern void info_free(info_t* info);

extern void info_put(info_t* info, info_item_t item);

#endif // CONIX_INFO_H
