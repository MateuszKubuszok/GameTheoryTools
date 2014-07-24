/**
 * @file      gt/model/null_factory.cpp
 * @brief     Defines GT::Model::NullFactory methods.
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

using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory final {
// public:

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

IdentifierPtr NullFactory::createIdentifier() const {
    return make_shared<Identifier>("NullIdentifier");
}

IdentifiersPtr NullFactory::createIdentifiers() const {
    return make_shared<Identifiers>();
}

MessagePtr NullFactory::createMessage() const {
    return make_shared<Message>("NullMessage");
}

MessagesPtr NullFactory::createMessages() const {
    return make_shared<Messages>();
}

NumberPtr NullFactory::createNumber() const {
    return make_shared<Number>(0);
}

NumbersPtr NullFactory::createNumbers() const {
    return make_shared<Numbers>();
}

PlayerPtr NullFactory::createPlayer() const {
    return make_shared<NullPlayer>();
}

PlayersPtr NullFactory::createPlayers() const {
    return make_shared<Players>();
}

DataPtr NullFactory::createData() const {
    return make_shared<NullData>();
}

DataAccessorPtr NullFactory::createDataAccessor() const {
    return make_shared<NullDataAccessor>();
}

DataPiecePtr NullFactory::createDataPiece() const {
    return make_shared<NullDataPiece>();
}

DataBuilderPtr NullFactory::createDataBuilder() const {
    return make_shared<NullDataBuilder>();
}

GamePtr NullFactory::createGame() const {
    return make_shared<NullGame>();
}

GameBuilderPtr NullFactory::createGameBuilder() const {
    return make_shared<NullGameBuilder>();
}

ResultPtr NullFactory::createResult() const {
    return make_shared<NullResult>();
}

ResultBuilderPtr NullFactory::createResultBuilder() const {
    return make_shared<NullResultBuilder>();
}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
