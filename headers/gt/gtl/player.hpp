#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player : public virtual Object, public virtual GT::Model::Player {
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
		Object(),
		GT::Model::Player(playerName, playerStrategies);
}

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
