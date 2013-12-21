/**
 * @file      gt/model/strategic_game_builder.cpp
 * @brief     Defines GT::Model::StrategicGameBuilder methods.
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

// class StrategicGameBuilder final : public GameBuilder {
// public:

StrategicGameBuilder::StrategicGameBuilder() :
    strategicDataBuilder(new StrategicDataBuilder())
    {}

const PlayersPtr StrategicGameBuilder::getPlayers() const {
    return strategicDataBuilder->getPlayers();
}

DataBuilder& StrategicGameBuilder::setPlayers(
    const PlayersPtr players
) {
    strategicDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& StrategicGameBuilder::addNextPositions(
    const PositionsPtr positions
) {
    strategicDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& StrategicGameBuilder::setParams(
    const NumbersPtr params
) {
    strategicDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr StrategicGameBuilder::clone() const {
    return strategicDataBuilder->clone();
}

GameBuilderPtr StrategicGameBuilder::cloneBuilder() const {
    return GameBuilderPtr(new StrategicGameBuilder());
}

DataBuilderPtr StrategicGameBuilder::dataBuilder() const {
    return dynamic_pointer_cast<DataBuilder>(strategicDataBuilder);
}

GamePtr StrategicGameBuilder::build() const {
    return GamePtr(
        new StrategicGame(
            strategicDataBuilder->getPlayers(),
            strategicDataBuilder->build()
        )
    );
}

Message StrategicGameBuilder::toString() const {
    static const IdentifierPtr name    = createIdentifierPtr("Current Strategic Game");
    const MessagePtr           message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class StrategicGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
