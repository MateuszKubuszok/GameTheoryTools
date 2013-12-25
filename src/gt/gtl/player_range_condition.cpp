/**
 * @file      gt/gtl/player_range_condition.cpp
 * @brief     Defines GT::GTL::PlayerRangeCondition methods.
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

using std::stringstream;

using boost::dynamic_pointer_cast;
using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerRangeCondition final : public Condition {
// public:

PlayerRangeCondition::PlayerRangeCondition(
    const ObjectPtr  definedPlayer,
    const ObjectsPtr definedStrategies
) :
    player(definedPlayer),
    strategies(definedStrategies)
    {}

Routines::ConditionPtr PlayerRangeCondition::getCondition(
    const Context& context
) const {
    const Identifier playerName = getIdentifier(context, player);

    Identifiers strategiesNames;
    for (const ObjectPtr& strategy : *strategies)
        strategiesNames.push_back( createIdentifierPtr(getIdentifier(context, strategy)) );

    return Routines::ConditionFactory::getInstance().createPlayerRangeCondition(
        createIdentifierPtr(playerName),
        createIdentifiersPtr(strategiesNames)
    );
}

Message PlayerRangeCondition::toString() const {
    static const IdentifierPtr playerName  = createIdentifierPtr("Player");
    static const IdentifierPtr allowedName = createIdentifierPtr("Allowed");

    ResultBuilderPtr strategiesValue = ResultFactory::getInstance().buildResult();
    for (Index i = 0; i < strategies->size(); i++) {
        strategiesValue->addResult(
            createIdentifierPtr(i+1),
            createMessagePtr(strategies->at(i)->toString())
        );
    }

    Message result = ResultFactory::getInstance().buildResult()
        ->addResult(playerName,  createMessagePtr(player->toString()))
         .addResult(allowedName, createMessagePtr(strategiesValue->build()->getResult()))
         .build()->getResult();

    static const IdentifierPtr name  = createIdentifierPtr("Condition");
    MessagePtr                 value = createMessagePtr(result);

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class PlayerRangeCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
