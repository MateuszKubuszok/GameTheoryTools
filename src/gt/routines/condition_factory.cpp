/**
 * @file      gt/routines/condition_factory.cpp
 * @brief     Defines GT::Routines::ConditionFactory methods.
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

// class ConditionFactory final {

ConditionFactory& ConditionFactory::getInstance() {
    static ConditionFactory instance;
    return instance;
}

// public:

ConditionPtr ConditionFactory::createInformationSetChoiceCondition(
    const IdentifierPtr player,
    const IdentifierPtr informationSet,
    const IdentifierPtr strategy
) const {
    return ConditionPtr( new InformationSetChoiceCondition(player, informationSet, strategy) );
}

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) const {
    return ConditionPtr( new PlayerChoiceCondition(player, strategy) );
}

// private:

ConditionFactory::ConditionFactory() {}

ConditionFactory::~ConditionFactory() {}

// }; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
