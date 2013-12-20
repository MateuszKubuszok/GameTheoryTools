#ifndef __GT_GTL_ERROR_FACTORY_HPP__
#define __GT_GTL_ERROR_FACTORY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Error instances for GTL classes.
 *
 * @author Mateusz Kubuszok
 */
class ErrorFactory {
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
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorCoordinate.
     *
     * @param errorMessage message describing error
     * @result             ErrorCoordinate
     */
    CoordinatePtr createCoordinate(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorDefinition.
     *
     * @param errorMessage message describing error
     * @result             ErrorDefinition
     */
    DefinitionPtr createDefinition(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorDetails.
     *
     * @param errorMessage message describing error
     * @result             ErrorDetails
     */
    DetailsPtr createDetails(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorGame.
     *
     * @param errorMessage message describing error
     * @result             ErrorGame
     */
    GamePtr createGame(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorObject.
     *
     * @param errorMessage message describing error
     * @result             ErrorObject
     */
    ObjectPtr createObject(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorParam.
     *
     * @param errorMessage message describing error
     * @result             ErrorParam
     */
    ParamPtr createParam(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorPlayer.
     *
     * @param errorMessage message describing error
     * @result             ErrorPlayer
     */
    PlayerPtr createPlayer(
        const Message errorMessage
    ) const;

    /**
     * @brief Creates ErrorQuery.
     *
     * @param errorMessage message describing error
     * @result             ErrorQuery
     */
    QueryPtr createQuery(
        const Message errorMessage
    ) const;

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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_ERROR_FACTORY_HPP__ */
