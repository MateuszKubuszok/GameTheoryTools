#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/driver.hpp
 * @brief     Defines GT::GTL::Driver interface.
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
 * @class Driver
 * @brief Used for executing actions called by Parser.
 *
 * @author Mateusz Kubuszok
 */
class Driver : public virtual Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Driver() {}

    /**
     * @brief Driver for Coordinate.
     *
     * @return CoordinateDriver
     */
    virtual CoordinateDriver& forCoordinate() const = 0;

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates() const = 0;

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition() const = 0;

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions() const = 0;

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame() const = 0;

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers() const = 0;

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects() const = 0;

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams() const = 0;

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue() const = 0;

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement() const = 0;

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        const ResultPtr result
    ) const = 0;

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        const InputLocation& location,
        const Message&       message
    ) const = 0;

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        const ValidableSymbol& symbol
    ) const = 0;

    /**
     * @brief Executes file.
     *
     * It uses currently used output and error stream to display result but read input from file.
     *
     * Operations are perfored on spawned Context so after all operations parental Context is instact.
     *
     * @param location location of file load call
     * @param fileName name of executed file
     *
     * @see #load(const Identifier&)
     */
    virtual void execute(
        const InputLocation& location,
        const Identifier&    fileName
    ) const = 0;

    /**
     * @brief Loads file.
     *
     * It uses currently used output and error stream to display result but read input from file.
     *
     * Operations are performed in current Context so all changes will be persisted.
     *
     * @param location location of file load call
     * @param fileName name of loaded file
     *
     * @see #execute(const Identifier&)
     */
    virtual void load(
        const InputLocation& location,
        const Identifier&    fileName
    ) = 0;

    /**
     * @brief Saves all Params available in current Context (and it's parents) to file.
     *
     * @param location location of file load call
     * @param fileName name of saved file
     */
    virtual void save(
        const InputLocation& location,
        const Identifier&    fileName
    ) const = 0;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() const override = 0;
}; /* END class Driver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullDriver
 * @brief Null Driver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDriver final : public Driver {
    CoordinateDriverPtr              coordinate;
    CollectionsDriverPtr<Coordinate> coordinates;
    ConditionDriverPtr               condition;
    CollectionsDriverPtr<Condition>  conditions;
    GameDriverPtr                    game;
    CollectionsDriverPtr<Identifier> identifiers;
    CollectionsDriverPtr<Object>     objects;
    CollectionsDriverPtr<Param>      params;
    ValueDriverPtr                   value;
    StatementDriverPtr               statement;

public:
    NullDriver() :
        coordinate(NullFactory::getInstance().createCoordinateDriver()),
        coordinates(NullFactory::getInstance().createCoordinatesDriver()),
        condition(NullFactory::getInstance().createConditionDriver()),
        conditions(NullFactory::getInstance().createConditionsDriver()),
        game(NullFactory::getInstance().createGameDriver()),
        identifiers(NullFactory::getInstance().createIdentifiersDriver()),
        objects(NullFactory::getInstance().createObjectsDriver()),
        params(NullFactory::getInstance().createParamsDriver()),
        value(NullFactory::getInstance().createValueDriver()),
        statement(NullFactory::getInstance().createStatementDriver())
        {}

    virtual CoordinateDriver& forCoordinate() const override {
        return *coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() const override {
        return *coordinates;
    }

    virtual ConditionDriver& forCondition() const override {
        return *condition;
    }

    virtual CollectionsDriver<Condition>& forConditions() const override {
        return *conditions;
    }

    virtual GameDriver& forGame() const override {
        return *game;
    }

    virtual CollectionsDriver<Identifier>& forIdentifiers() const override {
        return *identifiers;
    }

    virtual CollectionsDriver<Object>& forObjects() const override {
        return *objects;
    }

    virtual CollectionsDriver<Param>& forParams() const override {
        return *params;
    }

    virtual ValueDriver& forValue() const override {
        return *value;
    }

    virtual StatementDriver& forStatement() const override {
        return *statement;
    }

    virtual void showResult(
        const ResultPtr
    ) const override {}

    virtual void showError(
        const InputLocation&,
        const Message&
    ) const override {}

    virtual void showError(
        const ValidableSymbol&
    ) const override {}

    virtual void execute(
        const InputLocation&,
        const Identifier&
    ) const {}

    virtual void load(
        const InputLocation&,
        const Identifier&
    ) {}

    virtual void save(
        const InputLocation&,
        const Identifier&
    ) const {}

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
