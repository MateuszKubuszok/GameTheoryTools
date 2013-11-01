#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Game.
 *
 * <p>Game Object can be later used to Query it or to store it into Contextfor later use.</pre>
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Parser
 */
class Game : public virtual Object {
    /**
     * @brief Model Game implementation.
     */
    Model::GamePtr game;

public:
    /**
     * @brief Initiates Object with Game model.
     *
     * @param game Model Game implementation
     */
    Game(
        Model::GamePtr game
    );

    /**
     * @brief Search pure Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr pureEquilibrium(
        const Context&    context,
        const Conditions& conditions
    );

    /**
     * @brief Search mixed Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr mixedEquilibrium(
        const Context&    context,
        const Conditions& conditions
    );

    /**
     * @brief Search behavioral Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr behavioralEquilibrium(
        const Context&    context,
        const Conditions& conditions
    );

    /**
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString();

    /**
     * @brief Explicit cast to Game type.
     *
     * @return Game
     */
    virtual operator Game&();
}; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class NullGame : public Game {
public:
    NullGame() :
        Game(Model::NullFactory::getInstance().createGame())
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGame");
    }
}; /* END class NullGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ErrorGame : public Game {
    Message message;

public:
    ErrorGame(
        Message errorMessage
    ) :
        Game(Model::NullFactory::getInstance().createGame()),
        message(errorMessage)
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const {
        return false;
    }

    virtual Message toString() {
        return message;
    }
}; /* END class ErrorGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
