/**
 * @file      gt/gtl/player_choice_condition.cpp
 * @brief     Defines GT::GTL::PlayerChoiceCondition methods.
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

// class PlayerChoiceCondition final : public Condition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const ObjectPtr definedPlayer,
    const ObjectPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

Routines::ConditionPtr PlayerChoiceCondition::getCondition(
    const Context&
) const {
    const boost::shared_ptr<IdentifierParam> playerParam =
        boost::dynamic_pointer_cast<IdentifierParam>(player);
    const boost::shared_ptr<IdentifierParam> strategyParam =
        boost::dynamic_pointer_cast<IdentifierParam>(strategy);

    if (!playerParam || !strategyParam) {
        Identifier expectedType = createIdentifier("Identifier Param");
        throw ExceptionFactory::getInstance().invalidObjectType(expectedType);
    }

    return Routines::ConditionFactory::getInstance().createPlayerChoiceCondition(
        createIdentifierPtr(playerParam->getIdentifier()),
        createIdentifierPtr(strategyParam->getIdentifier())
    );
}

Message PlayerChoiceCondition::toString() const {
    std::stringstream result;
    result << "Player \"" << player << "\" choosed \"" << strategy << "\"";

    static const IdentifierPtr name  = createIdentifierPtr("Condtion");
    MessagePtr                 value = createMessagePtr(result.str());

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
