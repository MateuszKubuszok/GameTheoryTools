#ifndef __GT_MODEL_GAME_BUILDER_HPP__
#define __GT_MODEL_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

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
     * @brief Default destructor.
     */
    virtual ~GameBuilder() {}

	/**
	 * @brief Builds Game.
	 *
	 * @return Game
	 * @throw std::runtime_exception thrown when data used for building
	 *                               is inconsistent 
	 */
	virtual GamePtr build() = 0;
}; /* END class GameBuilder */

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null GameBuilder for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullGameBuilder : public GameBuilder {
public:
    virtual DataBuilder& setPlayers(
        PlayersPtr players
    ) {
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) {
        return *this;
    }

    virtual DataBuilder& setParams(
        NumbersPtr params
    ) {
        return *this;
    }

    virtual GamePtr build() {
    	return NullFactory::getInstance().createGame();
    }

    virtual DataBuilderPtr clone() {
        return NullFactory::getInstance().createDataBuilder();
    }

    virtual Message toString() {
        return Message("NullGameBuilder");
    }
}; /* END class NullDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_GAME_BUILDER_HPP__ */
