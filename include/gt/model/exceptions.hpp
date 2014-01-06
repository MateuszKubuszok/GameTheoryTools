#ifndef __GT_MODEL_EXCEPTIONS_HPP__
#define __GT_MODEL_EXCEPTIONS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/exceptions.hpp
 * @brief     Defines GT::Model exceptions.
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

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class IllegalInnerState
 * @brief Intened to be thrown when inner state of an object is not allowed.
 *
 * @author Mateusz Kubuszok
 */
class IllegalInnerState final : public std::domain_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit IllegalInnerState(
        const Message& message
    ) :
        std::domain_error(message)
        {}
}; /* END class IllegalInnerState */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidCoordinate
 * @brief Intened to be thrown when coordinates to some value are invalid.
 *
 * @author Mateusz Kubuszok
 */
class InvalidCoordinate final : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidCoordinate(
        const Message& message
    ) :
        std::invalid_argument(message)
        {}
}; /* END class InvalidCoordinate */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_EXCEPTIONS_HPP__ */
