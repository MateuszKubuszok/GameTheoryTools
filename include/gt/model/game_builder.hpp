#ifndef __GT_MODEL_GAME_BUILDER_HPP__
#define __GT_MODEL_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used to create Games.
 *
 * <p>Has the same interface as DataBuilder to make decoration possible.</p>
 *
 * <p>Intended to be used recursively with clone method:</p>
 *
 * <p><pre>
 * DataBuilderPtr builder1 = gameBuilder->clone();
 *     builder1->addNextPositions(position11);
 *     builder->clone()->addNextPositions(positions21).setParams(param11_21); // payoff(p1=s1, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param11_22); // payoff(p1=s1, p2=s2)
 * DataBuilderPtr builder2 = gameBuilder->clone();
 *     builder2->addNextPositions(position12);
 *     builder->clone()->addNextPositions(positions21).setParams(param12_21); // payoff(p1=s2, p2=s1)
 *     builder->clone()->addNextPositions(positions22).setParams(param12_22); // payoff(p1=s2, p2=s2)
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Game
 * @see DataBuilder
 */
class GameBuilder : public DataBuilder {
public:
    /**
     * @brief Builds Game.
     *
     * @return Game
     */
    virtual GamePtr build() = 0;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers() = 0;

    /**
     * @brief Returns inner DataBuilder.
     *
     * @return DataBuilder
     */
    virtual DataBuilderPtr dataBuilder() = 0;
}; /* END class GameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null GameBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGameBuilder : public GameBuilder {
public:
    virtual PlayersPtr getPlayers() {
        return NullFactory::getInstance().createPlayers();
    }

    virtual DataBuilder& setPlayers(
        PlayersPtr
    ) {
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        PositionsPtr
    ) {
        return *this;
    }

    virtual DataBuilder& setParams(
        NumbersPtr
    ) {
        return *this;
    }

    virtual DataBuilderPtr dataBuilder() {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual GamePtr build() {
        return NullFactory::getInstance().createGame();
    }

    virtual DataBuilderPtr clone() {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullGameBuilder");
    }
}; /* END class NullDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_BUILDER_HPP__ */
