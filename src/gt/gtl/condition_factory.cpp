/**
 * @file      gt/gtl/condition_factory.cpp
 * @brief     Defines GT::GTL::ConditionFactory methods.
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

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConditionFactory {

ConditionFactory& ConditionFactory::getInstance() {
    static ConditionFactory instance;
    return instance;
}

// public:

ConditionPtr ConditionFactory::createInformationSetChoiceCondition(
    const ObjectPtr player,
    const ObjectPtr informationSet,
    const ObjectPtr strategy
) const {
    return ConditionPtr(
        new InformationSetChoiceCondition(player, informationSet, strategy)
    );
}

ConditionPtr ConditionFactory::createInformationSetRangeCondition(
    const ObjectPtr  player,
    const ObjectPtr  informationSet,
    const ObjectsPtr strategies
) const {
    return ConditionPtr(
        new InformationSetRangeCondition(player, informationSet, strategies)
    );
}

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const ObjectPtr player,
    const ObjectPtr strategy
) const {
    return ConditionPtr(
        new PlayerChoiceCondition(player, strategy)
    );
}

ConditionPtr ConditionFactory::createPlayerRangeCondition(
    const ObjectPtr  player,
    const ObjectsPtr strategies
) const {
    return ConditionPtr(
        new PlayerRangeCondition(player, strategies)
    );
}

// private:

ConditionFactory::ConditionFactory() {}

ConditionFactory::~ConditionFactory() {}

// }; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
