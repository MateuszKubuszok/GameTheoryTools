/**
 * @file      gt/model/extensive_game_builder.cpp
 * @brief     Defines GT::Model::ExtensiveGameBuilder methods.
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

using boost::dynamic_pointer_cast;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGameBuilder final : public GameBuilder {
// public:

ExtensiveGameBuilder::ExtensiveGameBuilder() :
    extensiveDataBuilder(new ExtensiveDataBuilder())
    {}

const PlayersPtr ExtensiveGameBuilder::getPlayers() const {
    return extensiveDataBuilder->getPlayers();
}

DataBuilder& ExtensiveGameBuilder::setPlayers(
    const PlayersPtr players
) {
    extensiveDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::addNextPositions(
    const PositionsPtr positions
) {
    extensiveDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::setPayoffs(
    const NumbersPtr params
) {
    extensiveDataBuilder->setPayoffs(params);
    return *this;
}

DataBuilderPtr ExtensiveGameBuilder::clone() const {
    return extensiveDataBuilder->clone();
}

GameBuilderPtr ExtensiveGameBuilder::cloneBuilder() const {
    return GameBuilderPtr(new ExtensiveGameBuilder());
}

DataBuilderPtr ExtensiveGameBuilder::dataBuilder() const {
    return dynamic_pointer_cast<DataBuilder>(extensiveDataBuilder);
}


GamePtr ExtensiveGameBuilder::build() const {
    return GamePtr(
        new ExtensiveGame(
            extensiveDataBuilder->getPlayers(),
            extensiveDataBuilder->build()
        )
    );
}

Message ExtensiveGameBuilder::toString() const {
    static const IdentifierPtr name    = createIdentifierPtr("Current Extensive Game");
    const MessagePtr           message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class ExtensiveGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
