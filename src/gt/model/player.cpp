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

bool Player::isEqual(
    Root& root
) {
    Player* player = dynamic_cast<Player*>(&root);
    if (!player)
        return false;
    if (player == this)
        return true;
    if (player->name != name)
        return false;
    if (*player->strategies != *strategies)
        return false;
    return true;
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

bool operator==(
    PlayerPtr& player1,
    PlayerPtr& player2
) {
    return (*player1) == (*player2);
}

bool operator!=(
    PlayerPtr& player1,
    PlayerPtr& player2
) {
    return (*player1) != (*player2);
}

OutputStream& operator<<(
    OutputStream& stream,
    PlayerPtr&    player
) {
    return stream << player->toString();
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
