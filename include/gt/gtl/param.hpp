#ifndef __GT_GTL_PARAM_HPP__
#define __GT_GTL_PARAM_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/param.hpp
 * @brief     Defines GT::GTL::Param abstract class.
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

using boost::container::set;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Param
 * @brief Abstract class that defines interface for Params.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Definition
 * @see ParamFactory
 */
class Param : public Object {
public:
    /**
     * @brief Contains visited Identifiers to prevent cycles.
     */
    typedef set<Identifier> VisitedIdentifiers;

    /**
     * @brief Default constructor.
     */
    Param();

    /**
     * @brief Finds referred Objects' property and returns it as a Result.
     *
     * Returns Result for referred Object if there is any and it has required property.
     *
     * @param context           Context with values
     * @param propertyName      property's name
     * @return                  Result for sought property
     * @throw CyclicIdentifiers thrown when there is Param with cyclic references
     * @throw InvalidProperty   thrown when property is not available for an Object
     */
    virtual ResultPtr findProperty(
        const Context&    context,
        const Identifier& propertyName
    ) const override;

    /**
     * @brief Finds referred Objects' property for giver conditions and returns it as a Result.
     *
     * Returns Result for referred Object if there is any and it has required property.
     *
     * @param context           Context with values
     * @param conditions        Conditions to consider
     * @return                  Result for sought property
     * @throw CyclicIdentifiers thrown when there is Param with cyclic references
     * @throw InvalidProperty   thrown when property is not available for an Object
     */
    virtual ResultPtr findPropertyWithConditions(
        const Context&    context,
        const Identifier& propertyName,
        const Conditions& conditions
    ) const override;

    /**
     * @brief Returns Object for Context.
     *
     * @param context               Context with values
     * @return                      Object
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Object
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context& context
    ) const;

    /**
     * @brief Returns Object for Context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Object
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Object
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const = 0;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @return                      Number
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Number
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context& context
    ) const;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Number
     * @throw CyclicIdentifiers     thrown when Identfiers create the cycle
     * @throw InvalidContentRequest thrown when Param does not contain Number
     * @throw NotDefinedParam       thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const = 0;

    /**
     * @brief Explicit cast to Param type.
     *
     * @return Param
     */
    virtual operator const Param&() const override;

protected:
    /**
     * @brief Checks whether visited Identifiers contain current one.
     *
     * @param visitedIdentifiers already cisited Identifiers
     * @param currentIdentifier  currently visited Identifier
     * @throw CyclicIdentifiers  thrown when Identifiers create the cycle
     */
    void checkVisitedIdentifiers(
        const VisitedIdentifiers& visitedIdentifiers,
        const Identifier&         currentIdentifier
    ) const;
}; /* END class Param */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullParam
 * @brief Null Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullParam final : public Param {
public:
    virtual const ObjectPtr getObject(
        const Context&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const ObjectPtr getObject(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const NumberPtr getNumber(
        const Context&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual const NumberPtr getNumber(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullParam");
    }
}; /* END class NullParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorParam
 * @brief Error Param for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorParam final : public Param {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorParam(
        const Message errorMessage
    ) :
        message(errorMessage)
        {}

    virtual const ObjectPtr getObject(
        const Context&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const ObjectPtr getObject(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return NullFactory::getInstance().createObject();
    }

    virtual const NumberPtr getNumber(
        const Context&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual const NumberPtr getNumber(
        const Context&,
        VisitedIdentifiers&
    ) const override {
        return Model::NullFactory::getInstance().createNumber();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* __GT_GTL_PARAM_HPP__ */
