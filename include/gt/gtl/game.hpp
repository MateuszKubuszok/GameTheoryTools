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
class Game : public Object {
    /**
     * @brief Model Game implementation.
     */
    const Model::GamePtr game;

public:
    /**
     * @brief Initiates Object with Game model.
     *
     * @param game Model Game implementation
     */
    explicit Game(
        const Model::GamePtr game
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
    ) const;

    /**
     * @brief Search mixed Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr mixedEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) const;

    /**
     * @brief Search behavior Nash equilibrium for given conditions.
     *
     * @param context    context with definitions
     * @param conditions conditions for query
     */
    virtual ResultPtr behaviorEquilibrium(
        const Context&    context,
        const Conditions& conditions
    ) const;

    /**
     * @brief Returns Message about Game.
     *
     * @return Game's state
     */
    virtual Message toString() const override;

    /**
     * @brief Explicit cast to Game type.
     *
     * @return Game
     */
    virtual operator const Game&() const override;
}; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Game for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGame : public Game {
public:
    NullGame() :
        Game(Model::NullFactory::getInstance().createGame())
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr behaviorEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullGame");
    }
}; /* END class NullGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Error Condition for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorGame : public Game {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorGame(
        const Message errorMessage
    ) :
        Game(Model::NullFactory::getInstance().createGame()),
        message(errorMessage)
        {}

    virtual ResultPtr pureEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr mixedEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual ResultPtr behaviorEquilibrium(
        const Context&,
        const Conditions&
    ) const override {
        return Model::NullFactory::getInstance().createResult();
    }

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorGame */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_GAME_HPP__ */
