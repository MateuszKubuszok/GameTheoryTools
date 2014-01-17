#ifndef __GT_VERSION_HPP__
#define __GT_VERSION_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/version.hpp
 * @brief     Declares library's version number.
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

/**
 * @brief GT major version number.
 */
#define GT_VERSION_MAJOR   0
/**
 * @brief GT minor version number.
 */
#define GT_VERSION_MINOR   4
/**
 * @brief GT release version number.
 */
#define GT_VERSION_RELEASE 0
/**
 * @brief GT version number.
 *
 * @code
   GT_VERSION_MAJOR   == GT_VERSION / 10000;
   GT_VERSION_MINOR   == GT_VERSION / 100 % 100;
   GT_VERSION_RELEASE == GT_VERSION % 1000;
   @endcode
 */
#define GT_VERSION         GT_VERSION_MAJOR * 10000 + GT_VERSION_MINOR * 100 + GT_VERSION_RELEASE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_VERSION_HPP__ */
