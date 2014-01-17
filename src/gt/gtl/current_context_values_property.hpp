#ifndef __GT_GTL_CURRENT_CONTEXT_VALUE_PROPERTY_HPP__
#define __GT_GTL_CURRENT_CONTEXT_VALUE_PROPERTY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/current_context_values_property.hpp
 * @brief     Defines GT::Model::CurrentContextValuesProperty class.
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
 * @class CurrentContextValuesProperty
 * @brief Describes CurrentContext's values.
 *
 * @author Mateusz Kubuszok
 *
 * @see CurrentContext
 */
class CurrentContextValuesProperty final : public ObjectProperty {
    /**
     * @brief Described Object.
     */
    const Context* context;

public:
    /**
     * @brief Initiates ObjectProperty with Object it's describing.
     *
     * @param describedObject described Object
     */
    explicit CurrentContextValuesProperty(
        const Context* describedContext
    );

    /**
     * @brief Returns ObjectProperty's description.
     *
     * @return description
     */
    virtual ResultPtr getDescription() const override;

    /**
     * @brief Finds CurrentContext's declared values.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class CurrentContextValuesProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_CURRENT_CONTEXT_VALUE_PROPERTY_HPP__ */
