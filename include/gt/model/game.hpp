#ifndef __GT_MODEL_GAME_HPP__
#define __GT_MODEL_GAME_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
 */
class Game : public virtual Root {
public:
    /**
     * @breif Returns Game's Players.
     *
     * @return Players
     */
    virtual PlayersPtr getPlayers() = 0;

    /**
     * @brief Game's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class Game */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Game for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGame : public Game {
public:
    virtual PlayersPtr getPlayers() {
        return NullFactory::getInstance().createPlayers();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGame");
    }
}; /* END class NullGame */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_HPP__ */
