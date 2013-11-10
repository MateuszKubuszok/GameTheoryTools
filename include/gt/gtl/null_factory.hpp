#ifndef __GT_GTL_NULL_FACTORY_HPP__
#define __GT_GTL_NULL_FACTORY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory {
    SINGLETON_DECLARATION(NullFactory)

public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return NullFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionPtr createCondition() const;

    /**
     * @brief Creates NullConditions.
     *
     * @result NullConditions
     */
    ConditionsPtr createConditions() const;

    /**
     * @brief Creates NullContext.
     *
     * @result NullContext
     */
    ContextPtr createContext() const;

    /**
     * @brief Creates NullCoordinate.
     *
     * @result NullCoordinate
     */
    CoordinatePtr createCoordinate() const;

    /**
     * @brief Creates NullCoordinates.
     *
     * @result NullCoordinates
     */
    CoordinatesPtr createCoordinates() const;

    /**
     * @brief Creates NullDefinition.
     *
     * @result NullDefinition
     */
    DefinitionPtr createDefinition() const;

    /**
     * @brief Creates NullDetails.
     *
     * @result NullDetails
     */
    DetailsPtr createDetails() const;

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame() const;

    /**
     * @brief Creates NullObject.
     *
     * @result NullObject
     */
    ObjectPtr createObject() const;

    /**
     * @brief Creates NullObjects.
     *
     * @result NullObjects
     */
    ObjectsPtr createObjects() const;

    /**
     * @brief Creates NullParam.
     *
     * @result NullParam
     */
    ParamPtr createParam() const;

    /**
     * @brief Creates NullParams.
     *
     * @result NullParams
     */
    ParamsPtr createParams() const;

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer() const;

    /**
     * @brief Creates NullPositions.
     *
     * @result NullPositions
     */
    PositionsPtr createPositions() const;

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult() const;

    /**
     * @brief Creates NullQuery.
     *
     * @result NullQuery
     */
    QueryPtr createQuery() const;

    /**
     * @brief Creates NullDriver.
     *
     * @result NullDriver
     */
    DriverPtr createDriver() const;

    /**
     * @brief Creates NullConditionDriver.
     *
     * @result NullConditionDriver
     */
    ConditionDriverPtr createConditionDriver() const;

    /**
     * @brief Creates NullCoordinateDriver.
     *
     * @result NullCooridnateDriver
     */
    CoordinateDriverPtr createCoordinateDriver() const;

    /**
     * @brief Creates NullGameDriver.
     *
     * @result NullGameDriver
     */
    GameDriverPtr createGameDriver() const;

    /**
     * @brief Creates NullValueDriver.
     *
     * @result NullValueDriver
     */
    ValueDriverPtr createValueDriver() const;

    /**
     * @brief Creates NullStatementDriver.
     *
     * @result NullStatementDriver
     */
    StatementDriverPtr createStatementDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Coordinate>.
     *
     * @result NullCollectionsDriver<Coordinate>
     */
    CollectionsDriverPtr<Coordinate> createCoordinatesDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Condition>.
     *
     * @result NullCollectionsDriver<Condition>
     */
    CollectionsDriverPtr<Condition> createConditionsDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Identifier>.
     *
     * @result NullCollectionsDriver<Identifier>
     */
    CollectionsDriverPtr<Identifier> createIdentifiersDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Object>.
     *
     * @result NullCollectionsDriver<Object>
     */
    CollectionsDriverPtr<Object> createObjectsDriver() const;

    /**
     * @brief Creates NullCollectionsDriver<Param>.
     *
     * @result NullCollectionsDriver<Param>
     */
    CollectionsDriverPtr<Param> createParamsDriver() const;

    /**
     * @brief Creates null InputLocation.
     *
     * @return InputLocation
     */
    InputLocationPtr createInputLocation() const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory();
}; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_NULL_FACTORY_HPP__ */
