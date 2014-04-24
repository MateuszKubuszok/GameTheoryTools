#ifndef GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP_INCLUDED
#define GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/strategic_pure_equilibrium_routine_config.hpp
 * @brief     Defines GT::Routines::StrategicPureEquilibriumRoutineConfig class.
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

using Model::PlayersPtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class StrategicPureEquilibriumRoutineConfig
 * @brief Contains information for StrategicPureEquilibriumRoutine.
 *
 * @author Mateusz Kubuszok
 */
class StrategicPureEquilibriumRoutineConfig final : public PlayerChoiceRoutineConfig {
public:
    /**
     * @brief Initiates config with ExtensiveData's tree root.
     *
     * @param players Players' definitions
     */
    explicit StrategicPureEquilibriumRoutineConfig(
        const PlayersPtr players
    );

    /**
     * @brief Whether current configuration is valid.
     *
     * @return true if current configuration is valid
     */
    virtual bool isValid() const override;

    /**
     * @brief Returns RoutineConfig's Message.
     *
     * @return RoutineConfig's Message
     */
    virtual Message toString() const override;
}; /* END class StrategicPureEquilibriumRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_STRATEGIC_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP_INCLUDED */
