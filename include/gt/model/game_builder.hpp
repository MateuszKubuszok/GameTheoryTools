#ifndef __GT_MODEL_GAME_BUILDER_HPP__
#define __GT_MODEL_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used to create Games.
 *
 * Has the same interface as DataBuilder to make decoration possible.
 *
 * @author Mateusz Kubuszok
 */
class GameBuilder : public DataBuilder {
public:
    /**
     * @brief Builds Game.
     *
     * @return                       Game
     * @throw std::runtime_exception thrown when data used for building is inconsistent
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
