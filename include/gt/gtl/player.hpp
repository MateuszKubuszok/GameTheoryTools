#ifndef __GT_GTL_PLAYER_HPP__
#define __GT_GTL_PLAYER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/gtl/player.hpp
 * @brief     Defines GT::GTL::Player class.
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
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class Player
 * @brief Defines Player.
 *
 * Player is defined with:
 *
 * @code
 * PLAYER playerName { [strategies] }
 * @endcode
 *
 * @author Mateusz Kubuszok
 *
 * @see GameDriver
 * @see Game
 * @see Parser
 */
class Player : public Object, public Model::Player {
public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName       name of the Player
     * @param playerStrategies declared strategies
     */
    Player(
        const IdentifierPtr  playerName,
        const IdentifiersPtr playerStrategies
    );

    /**
     * @brief Returns Message about Player.
     *
     * @return Player's Message
     */
    virtual Message toString() const override;

    /**
     * @brief Explicit cast to Player type.
     *
     * @return Player
     */
    virtual operator const Player&() const override;
}; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullPlayer
 * @brief Null Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullPlayer final : public Player {
public:
    NullPlayer() :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        )
        {}

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ErrorPlayer
 * @brief Error Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class ErrorPlayer final : public Player {
    /**
     * @brief Error message.
     */
    const Message message;

public:
    ErrorPlayer(
        const Message errorMessage
    ) :
        Player(
            Model::NullFactory::getInstance().createIdentifier(),
            Model::NullFactory::getInstance().createIdentifiers()
        ),
        message(errorMessage)
        {}

    virtual bool isValid() const override {
        return false;
    }

    virtual Message toString() const override {
        return message;
    }
}; /* END class ErrorPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_PLAYER_HPP__ */
