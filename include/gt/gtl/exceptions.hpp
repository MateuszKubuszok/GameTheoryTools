#ifndef __GT_GTL_EXCEPTIONS_HPP__
#define __GT_GTL_EXCEPTIONS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/exceptions.hpp
 * @brief     Defines GT::GTL exceptions.
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
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class CyclicIdentifiers
 * @brief Intened to be thrown when Params create the cycle.
 *
 * @author Mateusz Kubuszok
 */
class CyclicIdentifiers final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit CyclicIdentifiers(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class CyclicIdentifiers */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidContentRequest
 * @brief Intened to be thrown when attempting to access content in invalid way.
 *
 * By invalid it should be understand e.g. accessing Object for ValueParam, or Value for ObjectParam.
 *
 * @author Mateusz Kubuszok
 */
class InvalidContentRequest final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidContentRequest(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidContentRequest */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidProperty
 * @brief Intened to be thrown when accessing non-existing Objects' property.
 *
 * @author Mateusz Kubuszok
 */
class InvalidProperty final : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidProperty(const Message& message) :
        std::invalid_argument(message)
        {}
}; /* END class InvalidProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class InvalidType
 * @brief Intened to be thrown when casting Object to invalid type.
 *
 * @author Mateusz Kubuszok
 */
class InvalidType final : public std::runtime_error {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit InvalidType(const Message& message) :
        std::runtime_error(message)
        {}
}; /* END class InvalidType */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NotDefinedParam
 * @brief Intened to be thrown when attempting to access not defined Param.
 *
 * By invalid it should be understand e.g. accessing Object for ValueParam, or Value for ObjectParam.
 *
 * @author Mateusz Kubuszok
 */
class NotDefinedParam final : public std::invalid_argument {
public:
    /**
     * @brief Constructor initialized with Message.
     *
     * @param message initializing Message
     */
    explicit NotDefinedParam(const Message& message) :
        std::invalid_argument(message)
        {}
}; /* END class NotDefinedParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXCEPTIONS_HPP__ */
