#ifndef __GT_GTL_NULL_FACTORY_HPP__
#define __GT_GTL_NULL_FACTORY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory {
    /**
     * @brief Contains pointer to a NullFactory instance.
     */
    static NullFactory* volatile instance;

public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return ExceptionFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionPtr createCondition();

    /**
     * @brief Creates NullCondition.
     *
     * @result NullCondition
     */
    ConditionsPtr createConditions();

    /**
     * @brief Creates NullContext.
     *
     * @result NullContext
     */
    ContextPtr createContext();

    /**
     * @brief Creates NullCoordinate.
     *
     * @result NullCoordinate
     */
    CoordinatePtr createCoordinate();

    /**
     * @brief Creates NullCoordinates.
     *
     * @result NullCoordinates
     */
    CoordinatesPtr createCoordinates();
    
    /**
     * @brief Creates NullDefinition.
     *
     * @result NullDefinition
     */
    DefinitionPtr createDefinition();

    /**
     * @brief Creates NullDetails.
     *
     * @result NullDetails
     */
    DetailsPtr createDetails();

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame();

    /**
     * @brief Creates NullObject.
     *
     * @result NullObject
     */
    ObjectPtr createObject();

    /**
     * @brief Creates NullObjects.
     *
     * @result NullObjects
     */
    ObjectsPtr createObjects();

    /**
     * @brief Creates NullParam.
     *
     * @result NullParam
     */
    ParamPtr createParam();

    /**
     * @brief Creates NullParams.
     *
     * @result NullParams
     */
    ParamsPtr createParams();

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer();

    /**
     * @brief Creates NullPositions.
     *
     * @result NullPositions
     */
    PositionsPtr createPositions();

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult();

    /**
     * @brief Creates NullQuery.
     *
     * @result NullQuery
     */
    QueryPtr createQuery();

    /**
     * @brief Creates NullDriver.
     *
     * @result NullDriver
     */
    DriverPtr createDriver();

    /**
     * @brief Creates NullConditionDriver.
     *
     * @result NullConditionDriver
     */
    ConditionDriverPtr createConditionDriver();

    /**
     * @brief Creates NullCoordinateDriver.
     *
     * @result NullCooridnateDriver
     */
    CoordinateDriverPtr createCoordinateDriver();

    /**
     * @brief Creates NullGameDriver.
     *
     * @result NullGameDriver
     */
    GameDriverPtr createGameDriver();

    /**
     * @brief Creates NullValueDriver.
     *
     * @result NullValueDriver
     */
    ValueDriverPtr createValueDriver();

    /**
     * @brief Creates NullStatementDriver.
     *
     * @result NullStatementDriver
     */
    StatementDriverPtr createStatementDriver();

    /**
     * @brief Creates NullCollectionsDriver<Coordinate>.
     *
     * @result NullCollectionsDriver<Coordinate>
     */
    CollectionsDriverPtr<Coordinate> createCoordinatesDriver();
    
    /**
     * @brief Creates NullCollectionsDriver<Condition>.
     *
     * @result NullCollectionsDriver<Condition>
     */
    CollectionsDriverPtr<Condition> createConditionsDriver();
    
    /**
     * @brief Creates NullCollectionsDriver<Identifier>.
     *
     * @result NullCollectionsDriver<Identifier>
     */
    CollectionsDriverPtr<Identifier> createIdentifiersDriver();

    /**
     * @brief Creates NullCollectionsDriver<Object>.
     *
     * @result NullCollectionsDriver<Object>
     */
    CollectionsDriverPtr<Object> createObjectsDriver();

    /**
     * @brief Creates NullCollectionsDriver<Param>.
     *
     * @result NullCollectionsDriver<Param>
     */
    CollectionsDriverPtr<Param> createParamsDriver();

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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_NULL_FACTORY_HPP__ */
