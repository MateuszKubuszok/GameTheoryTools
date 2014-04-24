#ifndef GT_ROUTINES_NULL_FACTORY_HPP_INCLUDED
#define GT_ROUTINES_NULL_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/null_factory.hpp
 * @brief     Defines GT::Routines::NullFactory class.
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
 * @class NullFactory
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory final {
public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return NullFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionPtr createCondition() const;

    /**
     * @brief Creates NullConditions.
     *
     * @result NullConditions
     */
    ConditionsPtr createConditions() const;

    /**
     * @brief Creates NullRoutine.
     *
     * @result NullRoutine
     */
    RoutinePtr createRoutine() const;

    /**
     * @brief Creates NullRoutines.
     *
     * @result NullRoutines
     */
    RoutinesPtr createRoutines() const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param nullFactory object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory() = default;
}; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef GT_ROUTINES_NULL_FACTORY_HPP_INCLUDED */
