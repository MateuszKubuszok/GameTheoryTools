#ifndef __GT_GTL_EXCEPTION_FACTORY_HPP__
#define __GT_GTL_EXCEPTION_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/exception_factory.hpp
 * @brief     Defines GT::GTL::ExceptionFactory class.
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
 * @class ExceptionFactory
 * @brief Used for creation of exception instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class ExceptionFactory final {
public:
    /**
     * @brief Returns the instance of an ExceptionFactory.
     *
     * @return ExceptionFactory instance
     */
    static ExceptionFactory& getInstance();

    /**
     * @brief Thrown when Identfiers create the cycle.
     *
     * @param visitedIdentifiers already visited Identifiers
     * @param currentIdentifier  current Identifier
     * @return                   CyclicIdentifiers exception to throw
     */
    CyclicIdentifiers cyclicIdentifiersFound(
        const Param::VisitedIdentifiers& visitedIdentifiers,
        const Identifier&                currentIdentifier
    ) const;

    /**
     * @brief Thrown when attepting to obtain nonexisting property from Object.
     *
     * @param propertyName invalid property name
     * @return             InvalidProperty exception to throw
     */
    InvalidProperty invalidObjectProperty(
        const Identifier& propertyName
    ) const;

    /**
     * @brief Thrown when attepting to obtain cast Object to invalid type.
     *
     * @param expectedType expected type of an Object
     * @return             InvalidType exception to throw
     */
    InvalidType invalidObjectType(
        const Identifier& expectedType
    ) const;

    /**
     * @brief Thrown when attepting to obtain not defined Param.
     *
     * @param paramName invalid Param name
     * @return          NotDefinedParam exception to throw
     */
    NotDefinedParam notDefinedParam(
        const Identifier& paramName
    ) const;

    /**
     * @brief Thrown when attemting to obtain Number from ObjectParam.
     *
     * @return InvalidContentRequest exception to throw
     */
    InvalidContentRequest requiredUnavailableNumberFromParam() const;

    /**
     * @brief Thrown when attemting to obtain Object from NumberParam.
     *
     * @return InvalidContentRequest exception to throw
     */
    InvalidContentRequest requiredUnavailableObjectFromParam() const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ExceptionFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param exceptionFactory object to copy
     */
    ExceptionFactory(
        const ExceptionFactory& exceptionFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ExceptionFactory() = default;
}; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXCEPTION_FACTORY_HPP__ */
