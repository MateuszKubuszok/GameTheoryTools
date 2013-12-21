#ifndef __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__
#define __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/selectable_strategies_routine.hpp
 * @brief     Defines GT::Routines::SelectableStrategiesRoutine class.
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class SelectableStrategiesRoutine
 * @brief Interface used to setup available Players.
 *
 * @author Mateusz Kubuszok
 *
 * @see Routine
 */
class SelectableStrategiesRoutine : virtual public Routine {
    /**
     * @brief Map containing available strategies.
     */
    typedef map<Identifier, IdentifiersPtr> AvailableStrategies;

    /**
     * @brief Available Players.
     */
    const PlayersPtr    players;

    /**
     * @brief Available strategies.
     */
    AvailableStrategies availableStrategies;

public:
    /**
     * @brief Initiates Routine with available Players.
     *
     * @param players Players definitions
     */
    explicit SelectableStrategiesRoutine(
        const PlayersPtr players
    );

    /**
     * @brief Obtains list of currently available Players.
     *
     * @return available Players
     */
    const PlayersPtr getAvailablePlayers() const;

    /**
     * @brief Returna available strategies for a Player.
     *
     * @param player Player for which strategies are obtaines
     * @return       currently available strategies
     */
    IdentifiersPtr getAvailableStrategiesForPlayer(
        const Identifier& player
    ) const;

    /**
     * @brief Sets available strategies for given Players.
     *
     * @param player     Player for which strategies are set up
     * @param strategies avialable strategies for Player
     */
    void setAvailableStrategiesForPlayer(
        const Identifier& player,
        IdentifiersPtr    strategies
    );
}; /* END class SelectableStrategiesRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__ */
