/* Handlers - A collection of cli handlers
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

#ifndef CONIX_HANDLERS_H
#define CONIX_HANDLERS_H

#include "common.h"

#define HANDLER_STORES 10

typedef struct handler handler_t;
typedef struct handlers handlers_t;
typedef struct handler_store handler_store_t;

struct handler {
  const char* id;
  void* payload;
  handle_t handle;
};

struct handlers {
  handler_store_t* stores[HANDLER_STORES];
};

extern void handlers_init(handlers_t* handlers);
extern void handlers_free(handlers_t* handlers);

extern void handlers_put(handlers_t* handlers, handler_t handler);
extern handler_t* handlers_get(handlers_t* handlers, const char* id);

#endif // CONIX_HANDLERS_H
