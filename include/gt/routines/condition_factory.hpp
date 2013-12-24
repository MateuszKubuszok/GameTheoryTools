#ifndef __GT_ROUTINES_CONDITION_FACTORY_HPP__
#define __GT_ROUTINES_CONDITION_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/condition_factory.hpp
 * @brief     Defines GT::Routines::ConditionFactory class.
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
 * @class ConditionFactory
 * @brief Used for creation of Null instances for Routines classes.
 *
 * @author Mateusz Kubuszok
 */
class ConditionFactory final {
public:
    /**
     * @brief Returns the instance of a ConditionFactory.
     *
     * @return ConditionFactory instance
     */
    static ConditionFactory& getInstance();

    /**
     * @brief Creates Condition of information set's choice.
     *
     * @param player         Player's name
     * @param informationSet information set's name
     * @param strategy       chosen strategy
     * @result Condition
     */
    ConditionPtr createInformationSetChoiceCondition(
        const IdentifierPtr player,
        const IdentifierPtr informationSet,
        const IdentifierPtr strategy
    ) const;

    /**
     * @brief Creates Condition of information set's allowed range.
     *
     * @param player         Player's name
     * @param informationSet information set's name
     * @param strategies     allowed strategies
     * @result Condition
     */
    ConditionPtr createInformationSetRangeCondition(
        const IdentifierPtr  player,
        const IdentifierPtr  informationSet,
        const IdentifiersPtr strategies
    ) const;

    /**
     * @brief Creates Condition of Player's choice.
     *
     * @param player   Player's name
     * @param strategy chosen strategy
     * @result Condition
     */
    ConditionPtr createPlayerChoiceCondition(
        const IdentifierPtr player,
        const IdentifierPtr strategy
    ) const;

    /**
     * @brief Creates Condition of Player's allowed strategies.
     *
     * @param player     Player's name
     * @param strategies allowed strategies
     * @result Condition
     */
    ConditionPtr createPlayerRangeCondition(
        const IdentifierPtr  player,
        const IdentifiersPtr strategies
    ) const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ConditionFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param conditionFactory object to copy
     */
    ConditionFactory(
        const ConditionFactory& conditionFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ConditionFactory();
}; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_CONDITION_FACTORY_HPP__ */
