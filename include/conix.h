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

typedef struct t_Conix Conix;
struct t_Conix {
    void* conix_private;
};

void conix_init(Conix* self, const char* title);
Conix* conix_create(const char* title);

void conix_reset(Conix* self);
void conix_destroy(Conix* self);

#endif // CONIX_CONIX_H
