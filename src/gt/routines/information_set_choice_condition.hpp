#ifndef GT_ROUTINES_INFORMATION_SET_CHOICE_CONDITION_HPP_INCLUDED
#define GT_ROUTINES_INFORMATION_SET_CHOICE_CONDITION_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/information_set_choice_condition.hpp
 * @brief     Defines GT::Routines::InformationSetChoiceCondition class.
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
 * @class InformationSetChoiceCondition
 * @brief Condition that configures Routine to allow only one choice from some Player's information set.
 *
 * @author Mateusz Kubuszok
 *
 * @see InformationSetChoiceRoutineConfig
 */
class InformationSetChoiceCondition final : public Condition {
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
    const IdentifierPtr strategy;

public:
    /**
     * @brief Initiates Condition with Player's and information set's names and chosen strategy.
     *
     * @param player         Player that chooses strategy
     * @param informationSet information set
     * @param strategy       chosen strategy
     */
    InformationSetChoiceCondition(
        const IdentifierPtr player,
        const IdentifierPtr informationSet,
        const IdentifierPtr strategy
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
}; /* END class InformationSetChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef GT_ROUTINES_INFORMATION_SET_CHOICE_CONDITION_HPP_INCLUDED */
