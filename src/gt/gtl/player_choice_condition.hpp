#ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__
#define __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/player_choice_condition.hpp
 * @brief     Defines GT::GTL::PlayerChoiceCondition class.
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
 * @class PlayerChoiceCondition
 * @brief Condition used for selecting strategy for a Player.
 *
 * @author Mateusz Kubuszok
 */
class PlayerChoiceCondition final : public Condition {
    /**
     * @brief Param with Player's name.
     */
    const ObjectPtr player;
    /**
     * @brief Param with Player's choice.
     */
    const ObjectPtr strategy;

public:
    /**
     * @brief Initiates Condition with a Player's name and choice.
     *
     * @param Param with Player's name
     * @param Param with Player's choice
     */
    PlayerChoiceCondition(
        const ObjectPtr player,
        const ObjectPtr strategy
    );

    /**
     * @brief Returns Condition applicable to Route.
     *
     * @param             Context
     * @return            Condition applicable to Route
     * @throw InvalidType thrown when either player or strategy are not IdentifierParams
     */
    virtual Routines::ConditionPtr getCondition(
        const Context& context
    ) const override;

    /**
     * @brief Returns Message about Condition.
     *
     * @return Condition's Message
     */
    virtual Message toString() const override;
}; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_CHOICE_CONDITION_HPP__ */
