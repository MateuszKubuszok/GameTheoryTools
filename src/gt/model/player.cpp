#include "gt/model/inner_common.hpp"

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
    Index index = 0;
    BOOST_FOREACH(IdentifierPtr& strategy, *strategies)
        strategyMapping.insert( StrategyMap::value_type(*strategy, index++) );
}

IdentifierPtr Player::getName() {
    return name;
}

IdentifiersPtr Player::getStrategies() {
    return strategies;
}

Index Player::getStrategiesNumber() {
    return strategies->size();
}

Index Player::getStrategyOrdinal(
    Identifier& strategy
) {
    if (strategyMapping.count(strategy))
        return strategyMapping[strategy];
    throw ExceptionFactory::getInstance().invalidStrategy(strategy);
}

bool Player::hasStrategy(
    Identifier& strategy
) {
    return strategyMapping.count(strategy);
}

Message Player::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    BOOST_FOREACH(IdentifierPtr& strategy, *strategies) {
        IdentifierPtr name  = createIdentifierPtr(getStrategyOrdinal(*strategy));
        MessagePtr    value = createMessagePtr(strategy);
        resultBuilder->addResult(name, value);
    }
    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
