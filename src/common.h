/* Common - Common types and macros
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

#ifndef CONIX_COMMON_H
#define CONIX_COMMON_H

#include <stddef.h>
#include <string.h>

#define foreach(index, from, to) \
  for (size_t index = from; index < to; ++index)

#define tokenize(string, delimit, token, body) \
  do { \
    char* token = strtok(strdup(string), delimit); \
    while (token != NULL) { \
      body; \
      token = strtok(NULL, delimit); \
    } \
  } while (0)

typedef void (*handle_t)(void*, void*);

#endif // CONIX_COMMON_H
