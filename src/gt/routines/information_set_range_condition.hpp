#ifndef __GT_ROUTINES_INFORMATION_SET_RANGE_CONDITION_HPP__
#define __GT_ROUTINES_INFORMATION_SET_RANGE_CONDITION_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/information_set_range_condition.hpp
 * @brief     Defines GT::Routines::InformationSetRangeCondition class.
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
 * @class InformationSetRangeCondition
 * @brief Condition that configures Routine to allow only one choice from some Player's information set.
 *
 * @author Mateusz Kubuszok
 *
 * @see InformationSetChoiceRoutineConfig
 */
class InformationSetRangeCondition final : public Condition {
    /**
     * @brief Player's name.
     */
    const IdentifierPtr player;
    /**
     * @brief Information set's name.
     */
    const IdentifierPtr informationSet;
    /**
     * @brief Chosen strategy.
     */
    const IdentifiersPtr strategies;

public:
    /**
     * @brief Initiates Condition with Player's and information set's names and range of strategies.
     *
     * @param player         Player that chooses strategy
     * @param informationSet information set
     * @param strategy       range of strategies
     */
    InformationSetRangeCondition(
        const IdentifierPtr  player,
        const IdentifierPtr  informationSet,
        const IdentifiersPtr strategy
    );

    /**
     * @brief Configureg given RoutineConfig.
     *
     * @param routineConfig    RoutineConfig to set up
     * @throw InvalidCondition thrown when Condition is invalid
     */
    virtual void configureRoutine(
        RoutineConfigPtr routineConfig
    ) const override;

    /**
     * @brief Returns Condition's Message.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override;
}; /* END class InformationSetRangeCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_INFORMATION_SET_RANGE_CONDITION_HPP__ */
