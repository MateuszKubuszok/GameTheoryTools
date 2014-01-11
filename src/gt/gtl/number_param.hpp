#ifndef __GT_GTL_NUMBER_PARAM_HPP__
#define __GT_GTL_NUMBER_PARAM_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/number_param.hpp
 * @brief     Defines GT::GTL::NumberParam class.
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
 * @class NumberParam
 * @brief Param containing Number value.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Param
 * @see ParamFactory
 */
class NumberParam final : public Param {
    /**
     * @brief Number stored by this Param.
     */
    const NumberPtr value;

public:
    /**
     * @brief Initiates Param with Number.
     *
     * @param number Number
     */
    explicit NumberParam(
        const NumberPtr number
    );

    /**
     * @brief Returns Object for Context.
     *
     * @param context               Context with values
     * @param visitedIdentifiers    already visited Identifiers
     * @return                      Object
     * @throw InvalidContentRequest thrown always for this implementation
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
     */
    virtual const NumberPtr getNumber(
        const Context&      context,
        VisitedIdentifiers& visitedIdentifiers
    ) const override;

    /**
     * @brief Returns serialized Message for a NumberParam.
     *
     * @return serialization result
     */
    virtual Message serialize() const override;

    /**
     * @brief NumberParam's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class NumberParam */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_NUMBER_PARAM_HPP__ */
