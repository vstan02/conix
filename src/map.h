/* Map - Hash map
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

#ifndef CONIX_MAP_H
#define CONIX_MAP_H

#include "attrs.h"

typedef struct t_Map Map;

extern Map* map_create(void);
extern void map_destroy(Map* self);

extern NONNULL(1) void* map_get(Map* self, const char* key);
extern NONNULL(1) void map_put(Map* self, const char* key, void* value);

#endif // CONIX_MAP_H
