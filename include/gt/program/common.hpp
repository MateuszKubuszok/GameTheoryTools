#ifndef GT_PROGRAM_COMMON_HPP_INCLUDED
#define GT_PROGRAM_COMMON_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/program/common.hpp
 * @brief     Declares classes for GT::Program module.
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

/* Includes GTL headers  */
#include "gt/gtl/common.hpp"

namespace GT {
namespace Program {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @namespace GT::Program
 * @brief     Contains classes related to creating GTL executable.
 *
 * Contains classes responible for executing process of running Parser with some parameters.
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* Program controllers declarations */

class ProgramController;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Program */
} /* END namespace GT */

/* Includes Program controllers headers */

#include "gt/program/helpers.hpp"

#include "gt/program/program_controller.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef GT_PROGRAM_COMMON_HPP_INCLUDED */
