#ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__
#define __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/execution_condition_driver.hpp
 * @brief     Defines GT::GTL::ExecutionConditionDriver class.
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
 * @class ExecutionConditionDriver
 * @brief Implementation used for handling Conditions via ExecutionDriver.
 *
 * Performs actual execution of instructions for Conditions.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExecutionDriver
 * @see ConditionDriver
 */
class ExecutionConditionDriver final : public ConditionDriver {
    /**
     * @brief Driver for error handling.
     */
    CheckingConditionDriver checkingConditionDriver;
    /**
     * @brief Implementation of a main Driver.
     */
    Driver*                 driver;

public:
    /**
     * @brief Initiates ExecutionConditionDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit ExecutionConditionDriver(
        Driver* parentDriver
    );

    /**
     * @brief Create Condition for Player choosing strategy.
     *
     * @param inputLocation input location of created Condition
     * @param player        Player's name
     * @param strategy      chosen strategy
     * @return              Condition
     */
    virtual ConditionPtr* playerChoosed(
        const InputLocation& inputLocation,
        const ObjectPtr*     playerPtr,
        const ObjectPtr*     strategyPtr
    ) const override;

    /**
     * @brief ExecutionConditionDriver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionConditionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_CONDITION_DRIVER_HPP__ */
