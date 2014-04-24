#ifndef GT_ROUTINES_PLAYER_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED
#define GT_ROUTINES_PLAYER_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/player_choice_routine_config.hpp
 * @brief     Defines GT::Routines::PlayerChoiceRoutineConfig class.
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

using Model::PlayersPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class PlayerChoiceRoutineConfig
 * @brief Contains information about available choices for each Player.
 *
 * @author Mateusz Kubuszok
 *
 * @see PlayerChoiceCondition
 */
class PlayerChoiceRoutineConfig : public virtual RoutineConfig {
    /**
     * @brief Contains information about strategies available for each Player.
     */
    typedef map<Identifier, Identifiers> AvailableForPlayers;

    /**
     * @brief Available strategies for each Player.
     */
    AvailableForPlayers                  availableForPlayers;

public:
    /**
     * @brief Initiates config with Players definitions.
     *
     * @param players Players definitions
     */
    explicit PlayerChoiceRoutineConfig(
        const PlayersPtr players
    );

    /**
     * @brief Trims availabe choices for Player for just one.
     *
     * @param  player             Player's name
     * @param  chosenStrategy     chosen strategy
     * @return                    reference to itself for chainging
     * @throw InvalidPlayerChoice thrown if Player's or information set's name is invalid
     */
    PlayerChoiceRoutineConfig& requireChoiceExactly(
        const Identifier& player,
        const Identifier& chosenStrategy
    );

    /**
     * @brief Trims availabe choices for Player to passed ones.
     *
     * @param  player             Player's name
     * @param  allowedStrategies  allowed strategies
     * @return                    reference to itself for chainging
     * @throw InvalidPlayerChoice thrown if Player's or information set's name is invalid
     */
    PlayerChoiceRoutineConfig& requireChoiceWithin(
        const Identifier&  player,
        const Identifiers& allowedStrategies
    );

    /**
     * @brief Returns available choices for given Player.
     *
     * @param player              Player's name
     * @return                    available strategies
     * @throw InvalidPlayerChoice thrown if Player's name is invalid
     */
    const Identifiers& getAvailableStrategies(
        const Identifier& player
    ) const;

    /**
     * @brief Whether current configuration is valid.
     *
     * @return true if current configuration is valid
     */
    virtual bool isValid() const override = 0;
}; /* END class PlayerChoiceRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_PLAYER_CHOICE_ROUTINE_CONFIG_HPP_INCLUDED */
