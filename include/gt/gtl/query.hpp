#ifndef __GT_GTL_QUERY_HPP__
#define __GT_GTL_QUERY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/query.hpp
 * @brief     Defines GT::GTL::Query class.
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
 * @class Query
 * @brief Defines Query.
 *
 * Each Query is created within Parser with:
 *
 * @code
 * FIND [propertiesNames]
 * FOR  [objects]
 * [WITH condition1[, condition2[, ...]]]
 * @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see StatementDriver
 * @see Condition
 * @see Parser
 */
class Query : public virtual ValidableSymbol {
    /**
     * @brief Names of properties that Oject will be queried for.
     */
    const IdentifiersPtr propertiesNames;

    /**
     * @brief Objects that will be queried.
     */
    const ObjectsPtr     objects;

    /**
     * @brief Conditions of Query.
     */
    const ConditionsPtr  conditions;

public:
    /**
     * @brief Initiates Query with properties, Objects and Conditions.
     *
     * @param propertiesName properties for which Cbjects will be queried,
     * @param objects        Objects to query for properties
     * @param conditions     Conditions for queries
     */
    Query(
        const IdentifiersPtr propertiesName,
        const ObjectsPtr     objects,
        const ConditionsPtr  conditions
    );

    /**
     * @brief Execute Query in a defined Context.
     *
     * @param context Context with definitions
     */
    virtual ResultPtr execute(
        const Context& context
    ) const;

    /**
     * @brief Returns Query's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class Query */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullQuery
 * @brief Null Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullQuery final : public Query {
public:
    NullQuery() :
        Query(
            Model::NullFactory::getInstance().createIdentifiers(),
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createConditions()
        )
        {}

    virtual ResultPtr execute(
        const Context&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullQuery");
    }
}; /* END class NullQuery */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorQuery
 * @brief Error Query for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorQuery final : public Query {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorQuery(
        const Message errorMessage
    ) :
        Query(
            Model::NullFactory::getInstance().createIdentifiers(),
            NullFactory::getInstance().createObjects(),
            NullFactory::getInstance().createConditions()
        ),
        message(errorMessage)
        {}

    virtual ResultPtr execute(
        const Context&
    ) const override {
        return NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorQuery */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_QUERY_HPP__ */
