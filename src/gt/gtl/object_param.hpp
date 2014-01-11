#ifndef __GT_GTL_OBJECT_PARAM_HPP__
#define __GT_GTL_OBJECT_PARAM_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/object_param.hpp
 * @brief     Defines GT::GTL::ObjectParam class.
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
 * @class ObjectParam
 * @brief Param containing Object value.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class ObjectParam final : public Param {
    /**
     * @brief Value stored by this Param.
     */
    const ObjectPtr value;

public:
    /**
     * @brief Initiates Param with Object.
     *
     * @param object Object
     */
    explicit ObjectParam(
        const ObjectPtr object
    );

    /**
     * @brief Returns Object for Context.
     *
     * @param context            Context with values
     * @param visitedIdentifiers already visited Identifiers
     * @return                   Object
     */
    virtual const ObjectPtr getObject(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns Number for context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Number
     * @throw InvalidContentRequest thrown always for this implementation
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns serialized Message for a ObjectParam.
     *
     * @return serialization result
     */
    virtual Message serialize() const override;

    /**
     * @brief ObjectParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ObjectParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_PARAM_HPP__ */
