#ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP__
#define __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/extensive_pure_equilibrium_routine_config.hpp
 * @brief     Defines GT::Routines::ExtensivePureEquilibriumRoutineConfig class.
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

using Model::ExtensiveDataNodePtr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ExtensivePureEquilibriumRoutineConfig
 * @brief Contains information for ExtensivePureEquilibriumRoutine.
 *
 * @author Mateusz Kubuszok
 */
class ExtensivePureEquilibriumRoutineConfig final : public InformationSetChoiceRoutineConfig {
public:
    /**
     * @brief Initiates config with ExtensiveData's tree root.
     *
     * @param extensiveGameRoot root of Data tree
     */
    explicit ExtensivePureEquilibriumRoutineConfig(
        const ExtensiveDataNodePtr extensiveGameRoot
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
}; /* END class ExtensivePureEquilibriumRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_EQUILIBRIUM_ROUTINE_CONFIG_HPP__ */
