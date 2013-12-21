#ifndef __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__
#define __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/player_choice_condition.hpp
 * @brief     Defines GT::Routines::PlayerChoiceCondition class.
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
 * @class PlayerChoiceCondition
 * @brief Condition that configures Routine to allow only one choice from some Player.
 *
 * @author Mateusz Kubuszok
 *
 * @see SelectableStrategiesRoutine
 */
class PlayerChoiceCondition final : public Condition {
    /**
     * @brief Player's name.
     */
    IdentifierPtr player;
    /**
     * @brief Chosen strategy.
     */
    IdentifierPtr strategy;

public:
    /**
     * @brief Initiates Condition with Player's name and chosen strategy.
     *
     * @param player   Player that chooses strategy
     * @param strategy chosen strategy
     */
    PlayerChoiceCondition(
        IdentifierPtr player,
        IdentifierPtr strategy
    );

    /**
     * @brief Configureg given Routine.
     *
     * @param routine          Routine to configure
     * @throw InvalidCondition thrown when Condition is invalid
     */
    virtual void configureRoutine(
        RoutinePtr routine
    ) const override;

    /**
     * @brief Returns Condition's Message.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override;
}; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_PLAYER_CHOICE_CONDITION_ROUTINE_HPP__ */
