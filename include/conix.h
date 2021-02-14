/* Conix - Command line interface building library
 * Copyright (C) 2020 Stan Vlad <vstan02@protonmail.com>
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

#ifndef CONIX_CONIX_H
#define CONIX_CONIX_H

#include "stddef.h"

typedef struct t_Conix Conix;
typedef struct t_ConixApp ConixApp;
typedef struct t_ConixOption ConixOption;
typedef struct t_ConixHandler ConixHandler;

struct t_ConixApp {
    const char* name;
    const char* version;
};

struct t_ConixOption {
    const char* name;
    const char* description;
    ConixHandler* handler;
};

struct t_ConixHandler {
    void (*handle)(void*);
    void* payload;
};

extern Conix* conix_create(ConixApp app, int argc, const char** argv);
extern void conix_destroy(Conix* self);

extern void conix_run(Conix* self);

extern void conix_add_option(Conix* self, ConixOption option);
extern void conix_add_options(Conix* self, size_t count, ConixOption* options);

extern ConixHandler* conix_handler_create(void (*handle)(void*), void* payload);

#endif // CONIX_CONIX_H
