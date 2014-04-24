#ifndef GT_ROUTINES_ROUTINE_CONFIG_HPP_INCLUDED
#define GT_ROUTINES_ROUTINE_CONFIG_HPP_INCLUDED

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/routines/routine_config.hpp
 * @brief     Defines GT::Routines::RoutineConfig interface.
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

/**
 * @class RoutineConfig
 * @brief Parent of RoutineConfigs that will store configuration specific to a Routine.
 *
 * @author Mateusz Kubuszok
 *
 * @see Routine
 * @see Condition
 */
class RoutineConfig : public virtual Root {
public:
    /**
     * @brief Whether current configuration is valid.
     *
     * @return true if current configuration is valid
     */
    virtual bool isValid() const = 0;

    /**
     * @brief Returns RoutineConfig's Message.
     *
     * @return RoutineConfig's Message
     */
    virtual Message toString() const override = 0;
}; /* END class RoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullRoutineConfig
 * @brief Null RoutineConfig for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullRoutineConfig : public RoutineConfig {
public:
    virtual bool isValid() const override {
        return true;
    }

    virtual Message toString() const override {
        return Message("NullRoutineConfig");
    }
}; /* END class NullRoutineConfig */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef GT_ROUTINES_ROUTINE_CONFIG_HPP_INCLUDED */
