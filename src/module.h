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

#ifndef XCALC_MODULE_H
#define XCALC_MODULE_H

#define PARAMS(args...) (self, ##args)

#define CONSTRUCTOR(module, class, params, args...) \
    class* module##_create(args) { \
        class* self = (class*) malloc(sizeof(class)); \
        module##_init params; \
        return self; \
    } \
    void module##_init(class* self, ##args)

#define DESTRUCTOR(module, class) \
    void module##_destroy(class* self) { \
        if (self) { \
            module##_reset(self); \
            free(self); \
        } \
    } \
    void module##_reset(class* self)

#endif // XCALC_MODULE_H
