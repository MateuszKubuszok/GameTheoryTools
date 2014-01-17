#ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__
#define __GT_GTL_PARAM_VALUE_PROPERTY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/param_value_property.hpp
 * @brief     Defines GT::GTL::ParamValueProperty class.
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
 * @class ParamValueProperty
 * @brief Describes Param's value.
 *
 * @author Mateusz Kubuszok
 *
 * @see Param
 */
class ParamValueProperty final : public ObjectProperty {
    /**
     * @brief Described Param.
     */
    const Param* param;

public:
    /**
     * @brief Initiates ObjectProperty with Param it's describing.
     *
     * @param describedParam described Param
     */
    explicit ParamValueProperty(
        const Param* describedParam
    );

    /**
     * @brief Returns ObjectProperty's description.
     *
     * @return description
     */
    virtual ResultPtr getDescription() const override;

    /**
     * @brief Finds Params's value.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class ParamValueProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__ */
