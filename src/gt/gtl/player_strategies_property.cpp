/**
 * @file      gt/gtl/player_strategies_property.cpp
 * @brief     Defines GT::Model::PlayerStrategiesProperty methods.
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

// class PlayerStrategiesProperty final : public ObjectProperty {
// public:

PlayerStrategiesProperty::PlayerStrategiesProperty(
    const Player* describedPlayer
) :
    player(describedPlayer)
    {}

ResultPtr PlayerStrategiesProperty::findForConditions(
    const Context&,
    const Conditions&
) const {
    static const IdentifierPtr strategiesName  = createIdentifierPtr("Strategies");

    static const IdentifierPtr name  = createIdentifierPtr("Strategy");
    ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
    for (IdentifierPtr& strategy : *player->getStrategies()) {
        MessagePtr value = createMessagePtr(strategy);
        subResultBuilder->addResult(name, value);
    }
    MessagePtr strategiesValue = createMessagePtr(subResultBuilder->buildRaw()->getResult());

    return ResultFactory::getInstance().buildResult()->addResult(strategiesName, strategiesValue).build();
}

// }; /* END class PlayerStrategiesProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
