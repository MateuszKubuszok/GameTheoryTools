#ifndef __GT_GTL_CHECKING_VALUE_DRIVER_HPP__
#define __GT_GTL_CHECKING_VALUE_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/checking_value_driver.hpp
 * @brief     Defines GT::GTL::CheckingValueDriver class.
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
 * @class CheckingValueDriver
 * @brief Implementation used for handling values via CheckingDriver.
 *
 * Performs only syntax/type checking on Values' tokens.
 *
 * @author Mateusz Kubuszok
 *
 * @see CheckingDriver
 * @see ValueDriver
 */
class CheckingValueDriver final : public ValueDriver {
    /**
     * @brief Implementation of a main Driver.
     */
    Driver* driver;

public:
    /**
     * @brief Initiates CheckingValueDriver with its parent.
     *
     * @param parentDriver parent Driver
     */
    explicit CheckingValueDriver(
        Driver* parentDriver
    );

    /**
     * @brief Creates Param by its name.
     *
     * @param inputLocation input location of created Param
     * @param identifier    Param's Identifier
     * @return              Param
     */
    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const IdentifierPtr* identifier
    ) const override;

    /**
     * @brief Creates Param by its value.
     *
     * @param inputLocation input location of created Param
     * @param number        Param's value
     * @return              Param
     */
    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const NumberPtr*     number
    ) const override;

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        const GamePtr* game
    ) const override;

    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        const PlayerPtr* player
    ) const override;

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        const ParamPtr* param
    ) const override;

    /**
     * @brief CheckingValueDriver message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CheckingValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_VALUE_DRIVER_HPP__ */
