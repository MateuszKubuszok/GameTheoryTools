#ifndef GT_GTL_IDENTIFIER_PARAM_HPP_INCLUDED
#define GT_GTL_IDENTIFIER_PARAM_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/identifier_param.hpp
 * @brief     Defines GT::GTL::IdentifierParam class.
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
 * @class IdentifierParam
 * @brief Param containing reference to other Param.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class IdentifierParam final : public Param {
    /**
     * @brief Identifier that this Param points to.
     */
    const Identifier identifier;

public:
    /**
     * @brief Initiates Param with Identifier.
     *
     * @param id identifier
     */
    explicit IdentifierParam(
        const Identifier& id
    );

    /**
     * @brief Returns Identifier.
     *
     * @return Identifier
     */
    const Identifier& getIdentifier() const;

    /**
     * @brief Returns Object for Context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Object
     * @throw CyclicIdentifiers  thrown when Identfiers create the cycle
     * @throw NotDefinedParam    thrown when Param cannot find value inside Context
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns Number for context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Number
     * @throw CyclicIdentifiers  thrown when Identfiers create the cycle
     * @throw NotDefinedParam    thrown when Param cannot find value inside Context
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns serialized Message for an IdentifierParam.
     *
     * @return serialization result
     */
    virtual Message serialize() const override;

    /**
     * @brief IdentifierParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class IdentifierParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef GT_GTL_IDENTIFIER_PARAM_HPP_INCLUDED */
