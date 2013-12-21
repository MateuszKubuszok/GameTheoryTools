/**
 * @file      gt/model/player.cpp
 * @brief     Defines GT::Model::Player methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
