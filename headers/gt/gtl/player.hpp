#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__ 1

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

class Player : Object {
public:
	Player(
		Identifier& playerName,
		Identifiers& playerStrategies
	) :
		name(playerName),
		strategies(playerStrategies);

	Identifier& getName();

	Identifiers& getStrategies();

	int getStrategiesNumber();

	int getStrategyOrdinal(
		Identifier& strategy
	);

private:
	Identifier name;

	Identifiers strategies;
}

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
