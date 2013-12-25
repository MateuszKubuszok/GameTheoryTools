#ifndef __GT_GTL_INFORMATION_SET_CHOICE_CONDITION_HPP__
#define __GT_GTL_INFORMATION_SET_CHOICE_CONDITION_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/information_set_choice_condition.hpp
 * @brief     Defines GT::GTL::InformationSetChoiceCondition class.
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
 * @class InformationSetChoiceCondition
 * @brief Condition used for selecting strategy for an information set.
 *
 * @author Mateusz Kubuszok
 */
class InformationSetChoiceCondition final : public Condition {
    /**
     * @brief Param with Player's name.
     */
    const ObjectPtr player;
    /**
     * @brief Param with Player's information set.
     */
    const ObjectPtr informationSet;
    /**
     * @brief Param with Player's choice.
     */
    const ObjectPtr strategy;

public:
    /**
     * @brief Initiates Condition with a Player's name and choice.
     *
     * @param player         Param with Player's name
     * @param informationSet Param with Player's informationSet
     * @param strategy       Param with Player's choice
     */
    InformationSetChoiceCondition(
        const ObjectPtr player,
        const ObjectPtr informationSet,
        const ObjectPtr strategy
    );

    /**
     * @brief Returns Condition applicable to Routine.
     *
     * @param context     Context
     * @return            Condition applicable to Routine
     * @throw InvalidType thrown when either player, informationSet or strategy are not IdentifierParams
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
}; /* END class InformationSetChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_INFORMATION_SET_CHOICE_CONDITION_HPP__ */
