#ifndef __GT_GTL_CONDITION_FACTORY_HPP__
#define __GT_GTL_CONDITION_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/condition_factory.hpp
 * @brief     Defines GT::GTL::ConditionFactory class.
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
 * @class ConditionFactory
 * @brief Used for creation of Conditions for GT model.
 *
 * @author Mateusz Kubuszok
 */
class ConditionFactory final {
public:
    /**
     * @brief Returns the instance of a ResultFactory.
     *
     * @return ConditionFactory instance
     */
    static ConditionFactory& getInstance();

    /**
     * @brief Creates Condition for a Player choosing strategy beforehand.
     *
     * @param player   player Object
     * @param strategy strategy Object
     * @result         Condition for a Player
     */
    ConditionPtr createPlayerChoiceCondition(
        const ObjectPtr player,
        const ObjectPtr strategy
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

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CONDITION_FACTORY_HPP__ */
