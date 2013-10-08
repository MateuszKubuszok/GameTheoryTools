#ifndef __GT_GTL_GAME_HPP__
#define __GT_GTL_GAME_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Game.
 *
 * @author Mateusz Kubuszok
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
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString();
}; /* END class Game */

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
