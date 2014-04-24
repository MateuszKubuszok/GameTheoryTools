#ifndef GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP_INCLUDED
#define GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/property_undefined_routine.hpp
 * @brief     Defines GT::Routines::PropertyUndefinedRoutine class.
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
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class PropertyUndefinedRoutine
 * @brief Routune returning "Property not defined for this kind of Game" Message.
 *
 * @author Mateusz Kubuszok
 *
 * @see Condition
 */
class PropertyUndefinedRoutine final : public Routine {
public:
    /**
     * @brief Returns "Property not defined for this kind of Game" Message.
     *
     * @param game       Game definition
     * @param conditions Conditions for this Routine
     * @return           Result for fiven Game and Conditions
     */
    virtual ResultPtr findResultFor(
        const GamePtr       game,
        const ConditionsPtr conditions
    ) const override;

    /**
     * @brief Returns Routine's Message.
     *
     * @return Routine's Message
     */
    virtual Message toString() const override;
}; /* END class PropertyUndefinedRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_PROPERTY_UNDEFINED_ROUTINE_HPP_INCLUDED */
