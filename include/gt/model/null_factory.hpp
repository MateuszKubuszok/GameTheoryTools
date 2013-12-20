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
    IdentifierPtr createIdentifier() const;

    /**
     * @brief Creates null Identifiers.
     *
     * @result null Identifiers
     */
    IdentifiersPtr createIdentifiers() const;

    /**
     * @brief Creates null Message.
     *
     * @result null Message
     */
    MessagePtr createMessage() const;

    /**
     * @brief Creates null Messages.
     *
     * @result null Messages
     */
    MessagesPtr createMessages() const;

    /**
     * @brief Creates NullNumber.
     *
     * @result NullNumber
     */
    NumberPtr createNumber() const;

    /**
     * @brief Creates Null Numbers.
     *
     * @result Null Numbers
     */
    NumbersPtr createNumbers() const;

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer() const;

    /**
     * @brief Creates NullPlayers.
     *
     * @result Player
     */
    PlayersPtr createPlayers() const;

    /**
     * @brief Creates NullData.
     *
     * @result NullData
     */
    DataPtr createData() const;

    /**
     * @brief Creates NullDataAccessor.
     *
     * @result NullDataAccessor
     */
    DataAccessorPtr createDataAccessor() const;

    /**
     * @brief Creates NullDataPiece.
     *
     * @result NullDataPiece
     */
    DataPiecePtr createDataPiece() const;

    /**
     * @brief Creates NullDataBuilder.
     *
     * @result NullDataBuilder
     */
    DataBuilderPtr createDataBuilder() const;

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame() const;

    /**
     * @brief Creates NullGameBuilder.
     *
     * @result NullGameBuilder
     */
    GameBuilderPtr createGameBuilder() const;

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult() const;

    /**
     * @brief Creates NullResultBuilder.
     *
     * @result NullResultBuilder
     */
    ResultBuilderPtr createResultBuilder() const;

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
