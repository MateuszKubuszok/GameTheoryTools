/**
 * @file      gt/routines/inner_common.cpp
 * @brief     Defines inner functions for GT::Routines module.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::atexit;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void freeGLPK() {
    glp_free_env();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

LPProblemPtr createLPProblem() {
    static bool initialized = false;
    if (!initialized) {
        atexit(freeGLPK);
        initialized = true;
    }

    return LPProblemPtr(glp_create_prob(), glp_delete_prob);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
