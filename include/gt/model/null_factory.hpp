#ifndef __GT_MODEL_NULL_FACTORY_HPP__
#define __GT_MODEL_NULL_FACTORY_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for creation of Null instances for Model classes.
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
     * @brief Creates null Identifier.
     *
     * @result null Identifier
     */
    IdentifierPtr createIdentifier();

    /**
     * @brief Creates null Identifiers.
     *
     * @result null Identifiers
     */
    IdentifiersPtr createIdentifiers();

    /**
     * @brief Creates null Message.
     *
     * @result null Message
     */
    MessagePtr createMessage();

    /**
     * @brief Creates null Messages.
     *
     * @result null Messages
     */
    MessagesPtr createMessages();

    /**
     * @brief Creates NullNumber.
     *
     * @result NullNumber
     */
    NumberPtr createNumber();

    /**
     * @brief Creates Null Numbers.
     *
     * @result Null Numbers
     */
    NumbersPtr createNumbers();

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer();

    /**
     * @brief Creates NullPlayers.
     *
     * @result Player
     */
    PlayersPtr createPlayers();

    /**
     * @brief Creates NullData.
     *
     * @result NullData
     */
    DataPtr createData();

    /**
     * @brief Creates NullDataAccessor.
     *
     * @result NullDataAccessor
     */
    DataAccessorPtr createDataAccessor();

    /**
     * @brief Creates NullDataPiece.
     *
     * @result NullDataPiece
     */
    DataPiecePtr createDataPiece();

    /**
     * @brief Creates NullDataBuilder.
     *
     * @result NullDataBuilder
     */
    DataBuilderPtr createDataBuilder();

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame();

    /**
     * @brief Creates NullGameBuilder.
     *
     * @result NullGameBuilder
     */
    GameBuilderPtr createGameBuilder();

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult();

    /**
     * @brief Creates NullResultBuilder.
     *
     * @result NullResultBuilder
     */
    ResultBuilderPtr createResultBuilder();

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

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_NULL_FACTORY_HPP__ */
