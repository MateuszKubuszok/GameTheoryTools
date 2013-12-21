#ifndef __GT_GTL_OBJECT_PROPERTY_HPP__
#define __GT_GTL_OBJECT_PROPERTY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/object_property.hpp
 * @brief     Defines GT::Model::ObjectProperty interface.
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
 * @class ObjectProperty
 * @brief Root of all Object's properties that can be registered.
 *
 * @author Mateusz Kubuszok
 */
class ObjectProperty {
public:
    /**
     * @brief Finds results for given Conditions.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const = 0;
}; /* END class ObjectProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_OBJECT_PROPERTY_HPP__ */
