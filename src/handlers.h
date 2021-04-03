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

typedef struct t_Handler Handler;
typedef struct t_Handlers Handlers;
typedef struct t_HandlerStore HandlerStore;

struct t_Handler {
    const char* id;
    void* payload;
    handle_t handle;
};

struct t_Handlers {
    HandlerStore* stores[HANDLER_STORES];
};

extern void handlers_init(Handlers* handlers);
extern void handlers_free(Handlers* handlers);

extern void handlers_put(Handlers* handlers, Handler handler);

#endif // CONIX_HANDLERS_H
