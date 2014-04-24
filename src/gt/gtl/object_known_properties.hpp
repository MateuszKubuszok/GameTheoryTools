#ifndef GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP_INCLUDED
#define GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/object_known_properties.hpp
 * @brief     Defines GT::GTL::ObjectKnownProperties class.
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
 * @class ObjectKnownProperties
 * @brief Describes Object's known properties.
 *
 * @author Mateusz Kubuszok
 *
 * @see Object
 */
class ObjectKnownProperties final : public ObjectProperty {
    /**
     * @brief Described Object.
     */
    const Object* object;

public:
    /**
     * @brief Initiates ObjectProperty with Object it's describing.
     *
     * @param describedObject described Object
     */
    explicit ObjectKnownProperties(
        const Object* describedObject
    );

    /**
     * @brief Returns ObjectProperty's description.
     *
     * @return description
     */
    virtual ResultPtr getDescription() const override;

    /**
     * @brief Finds Object's known propertes.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class ObjectKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP_INCLUDED */
