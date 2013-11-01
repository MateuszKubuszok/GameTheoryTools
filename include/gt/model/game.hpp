#ifndef __GT_MODEL_GAME_HPP__
#define __GT_MODEL_GAME_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
     * @brief Grants access to Data specific to a Game.
     *
     * @return DataAccessor returns DataAccessor specific for a Game
     */
    virtual DataAccessorPtr getData() = 0;

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        Root& root
    );

    /**
     * @brief Game's Message.
     *
     * @return message
     */
    virtual Message toString() = 0;

    /**
     * @brief Syntax sugar for isEqual method.
     *
     * @param game1 first Game to compare
     * @param game2 second Game to compare
     * @return      true if Games are equal
     */
    friend bool operator==(
        GamePtr& game1,
        GamePtr& game2
    );

    /**
     * @brief Syntax sugar for !isEqual method.
     *
     * @param game1 first Game to compare
     * @param game2 second Game to compare
     * @return      true if Games are not equal
     */
    friend bool operator!=(
        GamePtr& game1,
        GamePtr& game2
    );

    /**
     * @brief Syntax sugar for toStream method.
     *
     * @param stream stream to concatenate
     * @param game   Game to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream& stream,
        GamePtr&      game
    );
}; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    virtual DataAccessorPtr getData() {
        return NullFactory::getInstance().createDataAccessor();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGame");
    }
}; /* END class NullGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_HPP__ */
