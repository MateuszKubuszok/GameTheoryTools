#ifndef GT_GTL_VALUE_DRIVER_HPP_INCLUDED
#define GT_GTL_VALUE_DRIVER_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/value_driver.hpp
 * @brief     Defines GT::GTL::ValueDriver interface.
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
 * @class ValueDriver
 * @brief Used for handling values via Driver.
 *
 * @author Mateusz Kubuszok
 */
class ValueDriver : public virtual Root {
public:
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
    ) const = 0;

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
    ) const = 0;

    /**
     * @brief Converts passed Game to Object.
     *
     * @param game Game to convert
     * @return     Object
     */
    virtual ObjectPtr* toObject(
        const GamePtr* game
    ) const = 0;

    /**
     * @brief Converts passed Player to Object.
     *
     * @param player Player to convert
     * @return       Object
     */
    virtual ObjectPtr* toObject(
        const PlayerPtr* player
    ) const = 0;

    /**
     * @brief Converts passed Param to Object.
     *
     * @param param Param to convert
     * @return      Object
     */
    virtual ObjectPtr* toObject(
        const ParamPtr* param
    ) const = 0;

    /**
     * @brief ValueDriver message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class ValueDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullValueDriver
 * @brief Null ValueDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullValueDriver final : public ValueDriver {
public:
    NullValueDriver() :
        ValueDriver()
        {}

    virtual ParamPtr* get(
        const InputLocation& inputLocation,
        const IdentifierPtr*
    ) const override {
        return new ParamPtr(
            setupLocation<Param>(
                NullFactory::getInstance().createParam(),
                inputLocation
            )
        );
    }

    virtual ParamPtr* get(
        const GT::GTL::InputLocation& inputLocation,
        const NumberPtr*
    ) const override {
        return new ParamPtr(
            setupLocation<Param>(
                NullFactory::getInstance().createParam(),
                inputLocation
            )
        );
    }

    virtual ObjectPtr* toObject(
        const GamePtr* game
    ) const override {
        return new ObjectPtr(
            setupLocation<Object>(
                NullFactory::getInstance().createObject(),
                *(*game)->getInputLocation()
            )
        );
    }

    virtual ObjectPtr* toObject(
        const PlayerPtr* player
    ) const override {
        return new ObjectPtr(
            setupLocation<Object>(
                NullFactory::getInstance().createObject(),
                *(*player)->getInputLocation()
            )
        );
    }

    virtual ObjectPtr* toObject(
        const ParamPtr* param
    ) const override {
        return new ObjectPtr(
            setupLocation<Object>(
                NullFactory::getInstance().createObject(),
                *(*param)->getInputLocation()
            )
        );
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullValueDriver");
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef GT_GTL_VALUE_DRIVER_HPP_INCLUDED */
