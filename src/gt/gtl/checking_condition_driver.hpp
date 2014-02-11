#ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__
#define __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/checking_condition_driver.hpp
 * @brief     Defines GT::GTL::CheckingConditionDriver class.
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
 * @class CheckingConditionDriver
 * @brief Implementation used for handling Conditions via CheckingDriver.
 *
 * Performs only syntax/type checking on Conditions' tokens.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see ConditionDriver
 */
class CheckingConditionDriver final : public ConditionDriver {
public:
    /**
     * @brief Create condition for Player choosing strategy in information set.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr         Player's name
     * @param informationSetPtr Player's information set
     * @param strategyPtr       chosen strategy
     * @return                  Condition
     */
    virtual ConditionPtr* informationSetChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     informationSetPtr,
        const ObjectPtr*     strategyPtr
    ) const override;

    /**
     * @brief Create condition for Player limiting allowed strategies in information set.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr         Player's name
     * @param informationSetPtr Player's information set
     * @param strategiesPtr     allowed strategies
     * @return                  Condition
     */
    virtual ConditionPtr* informationSetWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     informationSetPtr,
        const ObjectsPtr*    strategiesPtr
    ) const override;

    /**
     * @brief Create condition for Player choosing strategy.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr     Player's name
     * @param strategyPtr   chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const override;

    /**
     * @brief Create condition for Player limiting allowed strategies.
     *
     * @param inputLocation input location of a created Condition
     * @param playerPtr     Player's name
     * @param strategiesPtr allowed strategies
     * @return              Condition
     */
    virtual ConditionPtr* playerWithin(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectsPtr*    strategiesPtr
    ) const override;

    /**
     * @brief CheckingConditionDriver's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Whether Object is Player or Param.
     *
     * @param object Object to check
     * @return       true if Object is either Object or Param
     */
    bool isPlayerOrParam(
        const Object& object
    ) const;

    /**
     * @brief Whether Object stores Identifier.
     *
     * @param object Object to check
     * @return       true if Object stores Identifier
     */
    bool hasIdentifier(
        const Object& object
    ) const;
}; /* END class CheckingConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_CONDITION_DRIVER_HPP__ */
