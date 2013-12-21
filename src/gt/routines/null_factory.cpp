/**
 * @file      gt/routines/null_factory.cpp
 * @brief     Defines GT::Routines::NullFactory methods.
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

#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class NullFactory final {

NullFactory& NullFactory::getInstance() {
    static NullFactory instance;
    return instance;
}

// public:

ConditionPtr NullFactory::createCondition() const {
    return ConditionPtr(new NullCondition());
}

ConditionsPtr NullFactory::createConditions() const {
    return ConditionsPtr(new Conditions());
}

RoutinePtr NullFactory::createRoutine() const {
    return RoutinePtr(new NullRoutine());
}

RoutinesPtr NullFactory::createRoutines() const {
    return RoutinesPtr(new Routines());
}

// private:

NullFactory::NullFactory() {}

NullFactory::~NullFactory() {}

// }; /* END class NullFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
