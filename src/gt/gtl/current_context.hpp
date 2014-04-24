#ifndef GT_GTL_CURRENT_CONTEXT_HPP_INCLUDED
#define GT_GTL_CURRENT_CONTEXT_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/current_context.hpp
 * @brief     Defines GT::GTL::CurrentContext class.
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
 * @class CurrentContext
 * @brief Abstract class that defines interface for Params.
 *
 * @author Mateusz Kubuszok
 *
 * @see Context
 * @see Definition
 * @see ParamFactory
 */
class CurrentContext : public Object {
public:
    /**
     * @brief Initiates instance with a Context.
     */
    explicit CurrentContext(
        const Context* context
    );
}; /* END class CurrentContext */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* GT_GTL_CURRENT_CONTEXT_HPP_INCLUDED */
