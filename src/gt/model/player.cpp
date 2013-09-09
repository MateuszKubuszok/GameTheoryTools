#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class Player {
// public:

Player::Player(
	const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
	name(playerName),
	strategies(playerStrategies),
	strategyMapping()
{
	// foreach strategy as strategy put strategy with index
}

IdentifierPtr Player::getName() {
	return name;
}

IdentifiersPtr Player::getStrategies() {
	return strategies;
}

int Player::getStrategiesNumber() {
	return (*strategies).size();
}

int Player::getStrategyOrdinal(
    Identifier& strategy
) {
	return strategyMapping[strategy];
}

Message Player::toString() {
	Message result = Message("Player:") + (*name) + "{ ";
	// foreach add "strategy "
	return result + "}";
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
