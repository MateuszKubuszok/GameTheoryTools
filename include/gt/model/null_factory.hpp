#ifndef GT_MODEL_NULL_FACTORY_HPP_INCLUDED
#define GT_MODEL_NULL_FACTORY_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/null_factory.hpp
 * @brief     Defines GT::Model::NullFactory class.
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

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullFactory
 * @brief Used for creation of Null instances for Model classes.
 *
 * @author Mateusz Kubuszok
 */
class NullFactory final {
public:
    /**
     * @brief Returns the instance of a NullFactory.
     *
     * @return NullFactory instance
     */
    static NullFactory& getInstance();

    /**
     * @brief Creates null Identifier.
     *
     * @result null Identifier
     */
    IdentifierPtr createIdentifier() const;

    /**
     * @brief Creates null Identifiers.
     *
     * @result null Identifiers
     */
    IdentifiersPtr createIdentifiers() const;

    /**
     * @brief Creates null Message.
     *
     * @result null Message
     */
    MessagePtr createMessage() const;

    /**
     * @brief Creates null Messages.
     *
     * @result null Messages
     */
    MessagesPtr createMessages() const;

    /**
     * @brief Creates NullNumber.
     *
     * @result null Number
     */
    NumberPtr createNumber() const;

    /**
     * @brief Creates Null Numbers.
     *
     * @result null Numbers
     */
    NumbersPtr createNumbers() const;

    /**
     * @brief Creates NullPlayer.
     *
     * @result NullPlayer
     */
    PlayerPtr createPlayer() const;

    /**
     * @brief Creates NullPlayers.
     *
     * @result Player
     */
    PlayersPtr createPlayers() const;

    /**
     * @brief Creates NullData.
     *
     * @result NullData
     */
    DataPtr createData() const;

    /**
     * @brief Creates NullDataAccessor.
     *
     * @result NullDataAccessor
     */
    DataAccessorPtr createDataAccessor() const;

    /**
     * @brief Creates NullDataPiece.
     *
     * @result NullDataPiece
     */
    DataPiecePtr createDataPiece() const;

    /**
     * @brief Creates NullDataBuilder.
     *
     * @result NullDataBuilder
     */
    DataBuilderPtr createDataBuilder() const;

    /**
     * @brief Creates NullGame.
     *
     * @result NullGame
     */
    GamePtr createGame() const;

    /**
     * @brief Creates NullGameBuilder.
     *
     * @result NullGameBuilder
     */
    GameBuilderPtr createGameBuilder() const;

    /**
     * @brief Creates NullResult.
     *
     * @result NullResult
     */
    ResultPtr createResult() const;

    /**
     * @brief Creates NullResultBuilder.
     *
     * @result NullResultBuilder
     */
    ResultBuilderPtr createResultBuilder() const;

private:
    /**
     * @brief Default constructor hidden from programmers.
     */
    NullFactory() = default;

    /**
     * @brief Default copy constructor hidden from programmers.
     *
     * @param nullFactory object to copy
     */
    NullFactory(
        const NullFactory& nullFactory
    ) = delete;

    /**
     * @brief Default destructor hidden from programmers.
     */
    ~NullFactory() = default;
}; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef GT_MODEL_NULL_FACTORY_HPP_INCLUDED */
