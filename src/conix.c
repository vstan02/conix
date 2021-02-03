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

#include <malloc.h>

#include "conix.h"

struct t_Conix {
    int argc;
    const char** argv;
};

extern Conix* conix_create(int argc, const char** argv) {
    Conix* self = (Conix*) malloc(sizeof(Conix));
    self->argc = argc;
    self->argv = argv;
    return self;
}

extern void conix_destroy(Conix* self) {
    if (self) free(self);
}

extern void conix_run(Conix* self) {}

extern void conix_add_option(Conix* self, ConixOption option) {}
