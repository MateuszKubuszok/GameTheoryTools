#ifndef __GT_GTL_ERROR_FACTORY_HPP__
#define __GT_GTL_ERROR_FACTORY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Error instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class ErrorFactory {
    SINGLETON_DECLARATION(ErrorFactory)

public:
    /**
     * @brief Returns the instance of a ErrorFactory.
     *
     * @return ErrorFactory instance
     */
    static ErrorFactory& getInstance();

    /**
     * @brief Creates ErrorCondition.
     *
     * @param errorMessage message describing error
     * @result             ErrorCondition
     */
    ConditionPtr createCondition(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorCoordinate.
     *
     * @param errorMessage message describing error
     * @result             ErrorCoordinate
     */
    CoordinatePtr createCoordinate(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorDefinition.
     *
     * @param errorMessage message describing error
     * @result             ErrorDefinition
     */
    DefinitionPtr createDefinition(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorDetails.
     *
     * @param errorMessage message describing error
     * @result             ErrorDetails
     */
    DetailsPtr createDetails(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorGame.
     *
     * @param errorMessage message describing error
     * @result             ErrorGame
     */
    GamePtr createGame(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorObject.
     *
     * @param errorMessage message describing error
     * @result             ErrorObject
     */
    ObjectPtr createObject(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorParam.
     *
     * @param errorMessage message describing error
     * @result             ErrorParam
     */
    ParamPtr createParam(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorPlayer.
     *
     * @param errorMessage message describing error
     * @result             ErrorPlayer
     */
    PlayerPtr createPlayer(
        Message errorMessage
    );

    /**
     * @brief Creates ErrorQuery.
     *
     * @param errorMessage message describing error
     * @result             ErrorQuery
     */
    QueryPtr createQuery(
        Message errorMessage
    );
private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    ErrorFactory();

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param object to copy
     */
    ErrorFactory(
        const ErrorFactory& errorFactory
    );

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~ErrorFactory();
}; /* END class ErrorFactory */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_ERROR_FACTORY_HPP__ */
