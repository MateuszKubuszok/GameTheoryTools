#ifndef __GT_MODEL_PLAYER_HPP__
#define __GT_MODEL_PLAYER_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/player.hpp
 * @brief     Defines GT::Model::Player class.
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
 * @class Player
 * @brief Defines Player.
 *
 * Each Player is defined by its name and used strategies. They will later be used during Game definition and
 * calculation of equilibria.
 *
 * @author Mateusz Kubuszok
 *
 * @see Game
 * @see GameBuilder
 */
class Player : public virtual Root {
    /**
     * @brief Type storing strategy-to-ordinal mapping.
     */
    typedef boost::container::map<Identifier, Index> StrategyMap;

    /**
     * @brief Player's name.
     */
    const IdentifierPtr name;

    /**
     * @brief Player's strategies.
     */
    const IdentifiersPtr strategies;

    /**
     * @brief Mapps strategies to its ordinal.
     */
    StrategyMap strategyMapping;

public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the Player
     * @param playerStrategy declared strategies
     */
    Player(
        const IdentifierPtr  playerName,
        const IdentifiersPtr playerStrategies
    );

    /**
     * @brief Returns name ot the Player.
     *
     * @return Player's name
     */
    virtual const IdentifierPtr getName() const;

    /**
     * @brief Returns Player's strategies.
     *
     * @return Player's strategies
     */
    virtual const IdentifiersPtr getStrategies() const;

    /**
     * @brief Returns number of strategies.
     *
     * @return number of strategies
     */
    virtual Index getStrategiesNumber() const;

     /**
     * @brief Returns ordinal of a strategy with given Identifier.
     *
     * @return                   ordinal of strategy with given Identifier
     * @throws InvalidCoordinate thrown if Player has no such strategy
     */
    virtual Index getStrategyOrdinal(
        const Identifier& strategy
    ) const;

     /**
     * @brief Returns whether strategy with such name exists.
     *
     * @return true if Player has such strategy
     */
    virtual bool hasStrategy(
        const Identifier& strategy
    ) const;

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        const Root& root
    ) const override;

    /**
     * @brief Returns Message with Player's name and strategies.
     *
     * @return Player's name and strategies
     */
    virtual Message toString() const override;

    /**
     * @brief Syntax sugar for #isEqual(const PlayerPtr&) method.
     *
     * @param player1 first Player to compare
     * @param player2 second Player to compare
     * @return        true if Players are equal
     */
    friend bool operator== (
        const PlayerPtr& player1,
        const PlayerPtr& player2
    );

    /**
     * @brief Syntax sugar for !#isEqual(const PlayerPtr&) method.
     *
     * @param player1 first Player to compare
     * @param player2 second Player to compare
     * @return        true if Players are not equal
     */
    friend bool operator!= (
        const PlayerPtr& player1,
        const PlayerPtr& player2
    );

    /**
     * @brief Syntax sugar for #toString() method.
     *
     * @param stream stream to concatenate
     * @param player Player to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<< (
        OutputStream&    stream,
        const PlayerPtr& player
    );
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
            NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createIdentifiers()
        )
        {}

    virtual const IdentifierPtr getName() const override {
        return NullFactory::getInstance().createIdentifier();
    }

    virtual const IdentifiersPtr getStrategies() const override {
        return NullFactory::getInstance().createIdentifiers();
    }

    virtual Index getStrategiesNumber() const override {
        return 0;
    }

    virtual Index getStrategyOrdinal(
        const Identifier&
    ) const override {
        return 0;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */
