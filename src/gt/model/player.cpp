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
    BOOST_FOREACH(IdentifierPtr& strategy, *strategies)
        strategyMapping.insert( StrategyMap::value_type(*strategy, index++) );
}

IdentifierPtr Player::getName() {
    return name;
}

IdentifiersPtr Player::getStrategies() {
    return strategies;
}

int Player::getStrategiesNumber() {
    return strategies->size();
}

Index Player::getStrategyOrdinal(
    Identifier& strategy
) {
    if (strategyMapping.count(strategy))
        return strategyMapping[strategy];
    throw std::invalid_argument("Strategy not found");
}

bool Player::hasStrategy(
    Identifier& strategy
) {
    return strategyMapping.count(strategy);
}

Message Player::toString() {
    Message result = Message("Player:") + (*name) + "{ ";
    BOOST_FOREACH(IdentifierPtr& strategy, *strategies)
        result += (*strategy) + " ";
    return result + "}";
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
