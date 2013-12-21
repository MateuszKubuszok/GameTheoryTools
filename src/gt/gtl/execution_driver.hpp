#ifndef __GT_GTL_EXECUTION_DRIVER_HPP__
#define __GT_GTL_EXECUTION_DRIVER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/execution_driver.hpp
 * @brief     Defines GT::GTL::ExecutionDriver class.
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
 * @class ExecutionDriver
 * @brief Implementation used for executing both checking and actual actions.
 *
 * Performs actual execution of instructions from input stream.
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 */
class ExecutionDriver final : public Driver {
    /**
     * @brief CheckingDriver for error handling.
     */
    mutable CheckingDriver checkingDriver;

    /**
     * @brief Contains Context.
     */
    mutable ContextPtr     context;

    /**
     * @brief Driver for Coordinates.
     */
    mutable ExecutionCoordinateDriver              coordinate;
    /**
     * @brief Driver for Coordinates' collections.
     */
    mutable CollectionsDriver<GT::GTL::Coordinate> coordinates;
    /**
     * @brief Driver for Conditions.
     */
    mutable ExecutionConditionDriver               condition;
    /**
     * @brief Driver for Conditions' collections.
     */
    mutable CollectionsDriver<GT::GTL::Condition>  conditions;
    /**
     * @brief Driver for Games.
     */
    mutable ExecutionGameDriver                    game;
    /**
     * @brief Driver for Identifiers' collections.
     */
    mutable CollectionsDriver<GT::Identifier>      identifiers;
    /**
     * @brief Driver for Objects' collections.
     */
    mutable CollectionsDriver<GT::GTL::Object>     objects;
    /**
     * @brief Driver for Params' collections.
     */
    mutable CollectionsDriver<GT::GTL::Param>      params;
    /**
     * @brief Driver for values.
     */
    mutable ExecutionValueDriver                   value;
    /**
     * @brief Driver for statements.
     */
    mutable ExecutionStatementDriver               statement;

    /**
     * @brief Output stream for displaying results.
     */
    mutable OutputStream* outputStream;

public:
    /**
     * @brief Initiates ExecutionDriver with a output stream.
     *
     * @param outputStream output stream
     * @param errorStream  error stream
     */
    ExecutionDriver(
        OutputStream* outputStream,
        OutputStream* errorStream
    );

    /**
     * @brief Destructor.
     */
    virtual ~ExecutionDriver();

    /**
     * @brief Driver for Coordinate.
     *
     * @return CoordinateDriver
     */
    virtual CoordinateDriver& forCoordinate() const override;

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates() const override;

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition() const override;

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions() const override;

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame() const override;

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers() const override;

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects() const override;

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams() const override;

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue() const override;

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement() const override;

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        const ResultPtr result
    ) const override;

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        const InputLocation& location,
        const Message&       message
    ) const override;

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        const ValidableSymbol& symbol
    ) const override;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class ExecutionDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_DRIVER_HPP__ */
