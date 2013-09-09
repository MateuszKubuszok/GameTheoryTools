#include <boost/foreach.hpp>

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
    int index = 0;
    BOOST_FOREACH(IdentifierPtr strategy, *strategies) {
        std::pair<Identifier, int> pair = std::make_pair(*strategy, index++);
        strategyMapping.insert(pair);
    }
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
    BOOST_FOREACH(IdentifierPtr strategy, *strategies)
        result += (*strategy) + " ";
    return result + "}";
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
