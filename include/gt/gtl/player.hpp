#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Player.
 *
 * <p>Player is defined with:</p>
 *
 * <p><pre>
 * PLAYER playerName { [strategies] }
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Game
 * @see Parser
 */
class Player : public Object, public Model::Player {
public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the Player
     * @param playerStrategy declared strategies
     */
    Player(
        const IdentifierPtr  playerName,
        const IdentifiersPtr playerStrategies
    );

    /**
     * @brief Returns Message about Player.
     *
     * @return Player's Message
     */
    virtual Message toString() const override;

    /**
     * @brief Explicit cast to Player type.
     *
     * @return Player
     */
    virtual operator const Player&() const override;
}; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullPlayer final : public Player {
public:
    NullPlayer() :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        )
        {}

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorPlayer final : public Player {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorPlayer(
        const Message errorMessage
    ) :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        ),
        message(errorMessage)
        {}

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
