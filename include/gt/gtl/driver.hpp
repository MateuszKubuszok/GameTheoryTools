#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for executing actions called Parser.
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
     * @brief Displays error.
     *
     * @param message Message to display
     */
    virtual void showError(
        const Message& message
    ) = 0;

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Driver */

////////////////////////////////////////////////////////////////////////////////

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

    virtual CoordinateDriver& forCoordinate() {
        return *coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() {
        return *coordinates;
    }

    virtual ConditionDriver& forCondition() {
        return *condition;
    }
    
    virtual CollectionsDriver<Condition>& forConditions() {
        return *conditions;
    }

    virtual GameDriver& forGame() {
        return *game;
    }
    
    virtual CollectionsDriver<Identifier>& forIdentifiers() {
        return *identifiers;
    }
    
    virtual CollectionsDriver<Object>& forObjects() {
        return *objects;
    }
    
    virtual CollectionsDriver<Param>& forParams() {
        return *params;
    }

    virtual ValueDriver& forValue() {
        return *value;
    }

    virtual StatementDriver& forStatement() {
        return *statement;
    }

    virtual void showError(
        const Message&
    ) {}

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
