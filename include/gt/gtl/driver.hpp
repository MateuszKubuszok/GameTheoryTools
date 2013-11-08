#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
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
    virtual CoordinateDriver& forCoordinate() = 0;

    /**
     * @brief Driver for Coordinates.
     *
     * @return CollectionDriver for Coordinates
     */
    virtual CollectionsDriver<Coordinate>& forCoordinates() = 0;

    /**
     * @brief Driver for Condition.
     *
     * @return ConditionDriver
     */
    virtual ConditionDriver& forCondition() = 0;

    /**
     * @brief Driver for Conditions.
     *
     * @return CollectionDriver for Conditions
     */
    virtual CollectionsDriver<Condition>& forConditions() = 0;

    /**
     * @brief Driver for Game.
     *
     * @return GameDriver
     */
    virtual GameDriver& forGame() = 0;

    /**
     * @brief Driver for Identifiers.
     *
     * @return CollectionDriver for Identifiers
     */
    virtual CollectionsDriver<Identifier>& forIdentifiers() = 0;

    /**
     * @brief Driver for Objects.
     *
     * @return CollectionDriver for Objects
     */
    virtual CollectionsDriver<Object>& forObjects() = 0;

    /**
     * @brief Driver for Params.
     *
     * @return CollectionDriver for Params
     */
    virtual CollectionsDriver<Param>& forParams() = 0;

    /**
     * @brief Driver for value.
     *
     * @return ValueDriver
     */
    virtual ValueDriver& forValue() = 0;

    /**
     * @brief Driver for Statement.
     *
     * @return StatementDriver
     */
    virtual StatementDriver& forStatement() = 0;

    /**
     * @brief Displays results.
     *
     * @param result Result to show
     */
    virtual void showResult(
        ResultPtr result
    ) = 0;

    /**
     * @brief Displays error.
     *
     * @param location error's location
     * @param message  Message to display
     */
    virtual void showError(
        InputLocation& location,
        const Message& message
    ) = 0;

    /**
     * @brief Displays error.
     *
     * @param symbol invalid symbol to display
     */
    virtual void showError(
        ValidableSymbol& symbol
    ) = 0;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Driver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Driver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDriver : public Driver {
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

    virtual CoordinateDriver& forCoordinate() override {
        return *coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() override {
        return *coordinates;
    }

    virtual ConditionDriver& forCondition() override {
        return *condition;
    }

    virtual CollectionsDriver<Condition>& forConditions() override {
        return *conditions;
    }

    virtual GameDriver& forGame() override {
        return *game;
    }

    virtual CollectionsDriver<Identifier>& forIdentifiers() override {
        return *identifiers;
    }

    virtual CollectionsDriver<Object>& forObjects() override {
        return *objects;
    }

    virtual CollectionsDriver<Param>& forParams() override {
        return *params;
    }

    virtual ValueDriver& forValue() override {
        return *value;
    }

    virtual StatementDriver& forStatement() override {
        return *statement;
    }

    virtual void showResult(
        ResultPtr
    ) override {}

    virtual void showError(
        InputLocation&,
        const Message&
    ) override {}

    virtual void showError(
        ValidableSymbol&
    ) override {}

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
