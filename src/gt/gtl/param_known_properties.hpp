#ifndef __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__
#define __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/param_known_properties.hpp
 * @brief     Defines GT::Model::ParamKnownProperties class.
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
 * @class ParamKnownProperties
 * @brief Describes referred Object's known properties.
 *
 * @author Mateusz Kubuszok
 *
 * @see Param
 */
class ParamKnownProperties final : public ObjectProperty {
    /**
     * @brief Described Param.
     */
    const Param* param;

public:
    /**
     * @brief Initiates Property with Param it's describing.
     *
     * @param describedParam described Param
     */
    explicit ParamKnownProperties(
        const Param* describedParam
    );

    /**
     * @brief Finds Param's known propertes.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class ParamKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_KNOWN_PROPERTIES_HPP__ */
