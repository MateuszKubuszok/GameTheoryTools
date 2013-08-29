#ifndef __GT_MODEL_PLAYER_HPP__
#define __GT_MODEL_PLAYER_HPP__ 1

#include "gt/model/common.hpp"

namespace GT {
namespace Model {

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player {
public:
	/**
	 * @brief Constructor of the Player.
	 *
	 * @param playerName     name of the player
	 * @param playerStrategy declared strategies
	 */
    Player(
        Identifier&  playerName,
        Identifiers& playerStrategies
    ) :
        name(playerName),
        strategies(playerStrategies),
        strategyMapping();

    ~Player();

	/**
	 * @brief Returns name ot the Player.
	 *
	 * @return Player's name
	 */
	Identifier getName();

	/**
	 * @brief Returns Player's strategies.
	 *
	 * @return Player's strategies
	 */
	Identifiers getStrategies();

	/**
	 * @brief 
	 *
	 * @return 
	 */	
	int getStrategiesNumber();

	 /**
	 * @brief 
	 *
	 * @return 
	 */
	int getStrategyOrdinal(
		Identifier& strategy
	);

private:
    const Identifier name;

    const Identifiers strategies;

    const boost::container::map<std::string, int> strategyMapping;
}

} /* END namespace Model */
} /* END namespace GT */
#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */
