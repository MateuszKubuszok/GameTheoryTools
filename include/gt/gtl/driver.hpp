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
    CoordinateDriver              coordinate;
    CollectionsDriver<Coordinate> coordinates;
    ConditionDriver               condition;
    CollectionsDriver<Condition>  conditions;
    GameDriver                    game;
    CollectionsDriver<Identifier> identifiers;
    CollectionsDriver<Object>     objects;
    CollectionsDriver<Param>      params;
    ValueDriver                   value;
    StatementDriver               statement;

public:
    /**
     * @brief Default constructor.
     */
    Driver();

    /**
     * @brief Default destructor.
     */
    virtual ~Driver();

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
     * @brief Displays error.
     *
     * @param message Message to display
     */
    virtual void showError(
        const Message& message
    );

    /**
     * @brief Driver's Message.
     *
     * @return message
     */
    virtual Message toString();
}; /* END class Driver */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Driver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullDriver : public Driver {
    NullCoordinateDriver              coordinate;
    NullCollectionsDriver<Coordinate> coordinates;
    NullConditionDriver               condition;
    NullCollectionsDriver<Condition>  conditions;
    NullGameDriver                    game;
    NullCollectionsDriver<Identifier> identifiers;
    NullCollectionsDriver<Object>     objects;
    NullCollectionsDriver<Param>      params;
    NullValueDriver                   value;
    NullStatementDriver               statement;

public:
    NullDriver() :
        Driver()
        {}

    virtual CoordinateDriver& forCoordinate() {
        return coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() {
        return coordinates;
    }

    virtual ConditionDriver& forCondition() {
        return condition;
    }
    
    virtual CollectionsDriver<Condition>& forConditions() {
        return conditions;
    }

    virtual GameDriver& forGame() {
        return game;
    }
    
    virtual CollectionsDriver<Identifier>& forIdentifiers() {
        return identifiers;
    }
    
    virtual CollectionsDriver<Object>& forObjects() {
        return objects;
    }
    
    virtual CollectionsDriver<Param>& forParams() {
        return params;
    }

    virtual ValueDriver& forValue() {
        return value;
    }

    virtual StatementDriver& forStatement() {
        return statement;
    }

    virtual void showError(
        const Message& message
    ) {}

    virtual Message toString() {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
