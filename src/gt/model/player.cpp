#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Player : public virtual Root {
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
    for (IdentifierPtr& strategy : *strategies)
        strategyMapping.insert( StrategyMap::value_type(*strategy, index++) );
}

const IdentifierPtr Player::getName() const {
    return name;
}

const IdentifiersPtr Player::getStrategies() const {
    return strategies;
}

Index Player::getStrategiesNumber() const {
    return strategies->size();
}

Index Player::getStrategyOrdinal(
    const Identifier& strategy
) const {
    if (strategyMapping.count(strategy))
        return strategyMapping.at(strategy);
    throw ExceptionFactory::getInstance().invalidStrategy(strategy);
}

bool Player::hasStrategy(
    const Identifier& strategy
) const {
    return strategyMapping.count(strategy);
}

bool Player::isEqual(
    const Root& root
) const {
    const Player* player = dynamic_cast<const Player*>(&root);
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

Message Player::toString() const {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    static const IdentifierPtr playerName      = createIdentifierPtr("Name");
    const MessagePtr           playerNameValue = createMessagePtr(getName());
    resultBuilder->addResult(playerName, playerNameValue);

    for (IdentifierPtr& strategy : *strategies) {
        IdentifierPtr name  = createIdentifierPtr(getStrategyOrdinal(*strategy));
        MessagePtr    value = createMessagePtr(strategy);
        resultBuilder->addResult(name, value);
    }

    return resultBuilder->build()->getResult();
}

// }; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool operator==(
    const PlayerPtr& player1,
    const PlayerPtr& player2
) {
    return (*player1) == (*player2);
}

bool operator!=(
    const PlayerPtr& player1,
    const PlayerPtr& player2
) {
    return (*player1) != (*player2);
}

OutputStream& operator<<(
    OutputStream&    stream,
    const PlayerPtr& player
) {
    return stream << player->toString();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
