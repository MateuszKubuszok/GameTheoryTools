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

// class NullFactory final {
// public:

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

IdentifierPtr NullFactory::createIdentifier() const {
    return IdentifierPtr(new Identifier("NullIdentifier"));
}

IdentifiersPtr NullFactory::createIdentifiers() const {
    return IdentifiersPtr(new Identifiers());
}

MessagePtr NullFactory::createMessage() const {
    return MessagePtr(new Message("NullMessage"));
}

MessagesPtr NullFactory::createMessages() const {
    return MessagesPtr(new Messages());
}

NumberPtr NullFactory::createNumber() const {
    return NumberPtr(new Number(0));
}

NumbersPtr NullFactory::createNumbers() const {
    return NumbersPtr(new Numbers());
}

PlayerPtr NullFactory::createPlayer() const {
    return PlayerPtr(new NullPlayer());
}

PlayersPtr NullFactory::createPlayers() const {
    return PlayersPtr(new Players());
}

DataPtr NullFactory::createData() const {
    return DataPtr(new NullData());
}

DataAccessorPtr NullFactory::createDataAccessor() const {
    return DataAccessorPtr(new NullDataAccessor());
}

DataPiecePtr NullFactory::createDataPiece() const {
    return DataPiecePtr(new NullDataPiece());
}

DataBuilderPtr NullFactory::createDataBuilder() const {
    return DataBuilderPtr(new NullDataBuilder());
}

GamePtr NullFactory::createGame() const {
    return GamePtr(new NullGame());
}

GameBuilderPtr NullFactory::createGameBuilder() const {
    return GameBuilderPtr(new NullGameBuilder());
}

ResultPtr NullFactory::createResult() const {
    return ResultPtr(new NullResult());
}

ResultBuilderPtr NullFactory::createResultBuilder() const {
    return ResultBuilderPtr(new NullResultBuilder());
}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
