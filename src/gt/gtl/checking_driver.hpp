#ifndef __GT_GTL_CHECKING_DRIVER_HPP__
#define __GT_GTL_CHECKING_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Implementation used for executing only checking actions.
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 */
class CheckingDriver : public Driver {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~CheckingDriver() {}

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
}; /* END class CheckingDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_CHECKING_DRIVER_HPP__ */
