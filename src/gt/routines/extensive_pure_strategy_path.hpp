#ifndef __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__
#define __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/extensive_pure_strategy_path.hpp
 * @brief     Defines GT::Routines::ExtensivePureStrategyPath class.
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
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::container::map;

using Model::DataPiecePtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ExtensivePureStrategyPath
 * @brief Contains path to a payoff (with payoff).
 *
 * @author Mateusz Kubuszok
 */
class ExtensivePureStrategyPath final : public Root {
    /**
     * @brief Players definitions.
     */
    const PlayersPtr players;

    /**
     * @brief Payoff.
     */
    DataPiecePtr payoffs;

    /**
     * @brief Contains choices for given Players.
     */
    map<Identifier, Positions> playersChoices;

public:
    /**
     * @brief Contains choices for given Players.
     */
    typedef map<Identifier, Positions> PlayersChoices;

    /**
     * @brief Initiates path with Players definitions.
     *
     * @param players Players definitions
     */
    ExtensivePureStrategyPath(
        const PlayersPtr players
    );

    /**
     * @brief Adds older choice to the beginning of list.
     *
     * @param informationSet      information set's name
     * @param player              Player's name
     * @param strategy            chosen strategy
     * @return                    reference for itself for chaining
     * @throw InvalidPlayerChoice thrown when Player's name or chosen strategy is invalid
     */
    ExtensivePureStrategyPath& addPlayerChoice(
        const Identifier& informationSet,
        const Identifier& player,
        const Identifier& strategy
    );

    /**
     * @brief Returns all players choices till now.
     *
     * @return Players' choices
     */
    const PlayersChoices& getPlayersChoices() const;

    /**
     * @brief Returns payoffs for path.
     *
     * @return payoff
     */
    const DataPiecePtr getPayoff() const;

    /**
     * @brief Sets payoff.
     *
     * @param payoffs new payoffs
     * @return        reference to itself for chaining
     */
    ExtensivePureStrategyPath& setPayoff(
        DataPiecePtr payoffs
    );

    /**
     * @brief Returns ExtensivePureStrategyMessage message.
     *
     * @return Message
     */
    virtual Message toString() const;
}; /* END class ExtensivePureStrategyPath */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__ */
