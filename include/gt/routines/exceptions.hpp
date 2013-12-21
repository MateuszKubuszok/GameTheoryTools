#ifndef __GT_ROUTINES_EXCEPTIONS_HPP__
#define __GT_ROUTINES_EXCEPTIONS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/exceptions.hpp
 * @brief     Defines GT::Routines exceptions.
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
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidCondition
 * @brief Intened to be thrown when Condition is in some way invalid.
 *
 * @author Mateusz Kubuszok
 */
class InvalidCondition final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidCondition(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidGameType
 * @brief Intened to be thrown when passed Game is not allowed for such Routine.
 *
 * @author Mateusz Kubuszok
 */
class InvalidGameType final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidGameType(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidGameType */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidPlayerChoice
 * @brief Intened to be thrown when non existing Player or strategy is chosen.
 *
 * @author Mateusz Kubuszok
 */
class InvalidPlayerChoice final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidPlayerChoice(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidPlayerChoice */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class IncompletePayoffInformation
 * @brief Intened to be thrown when payoff for some player is not set.
 *
 * @author Mateusz Kubuszok
 */
class IncompletePayoffInformation final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit IncompletePayoffInformation(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class IncompletePayoffInformation */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_EXCEPTIONS_HPP__ */
