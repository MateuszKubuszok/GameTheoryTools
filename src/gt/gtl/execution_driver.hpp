#ifndef __GT_GTL_EXECUTION_DRIVER_HPP__
#define __GT_GTL_EXECUTION_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for executing both checking and actual actions.
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 */
class ExecutionDriver : public Driver {
    CheckingDriver checkingDriver;
    ContextPtr     context;

    std::ostream* outputStream;

    ExecutionCoordinateDriver              coordinate;
    CollectionsDriver<GT::GTL::Coordinate> coordinates;
    ExecutionConditionDriver               condition;
    CollectionsDriver<GT::GTL::Condition>  conditions;
    ExecutionGameDriver                    game;
    CollectionsDriver<GT::Identifier>      identifiers;
    CollectionsDriver<GT::GTL::Object>     objects;
    CollectionsDriver<GT::GTL::Param>      params;
    ExecutionValueDriver                   value;
    ExecutionStatementDriver               statement;

public:
    /**
     * @brief Initiates ExecutionDriver with a output stream.
     *
     * @param outputStream output stream
     * @param errorStream  error stream
     */
    ExecutionDriver(
        std::ostream* outputStream,
        std::ostream* errorStream
    );

    /**
     * @brief Driver for Coordinate.
     *
     * @return CoordinateDriver
     */
    virtual CoordinateDriver& forCoordinate();

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates();

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition();

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions();

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame();

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers();

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects();

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams();

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue();

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement();

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        ResultPtr result
    );

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        InputLocation& location,
        const Message& message
    );

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        ValidableSymbol& symbol
    );

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class ExecutionDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_EXECUTION_DRIVER_HPP__ */
