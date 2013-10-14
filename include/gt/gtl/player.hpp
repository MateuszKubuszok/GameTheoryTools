#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player : public virtual Object, public Model::Player {
public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the player
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
    virtual Message toString();
}; /* END class Player */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullPlayer : public Player {
public:
    NullPlayer() :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        )
        {}

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorPlayer : public Player {
    Message message;
    
public:
    ErrorPlayer(
        Message errorMessage
    ) :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        ),
        message(errorMessage)
        {}

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorPlayer */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
