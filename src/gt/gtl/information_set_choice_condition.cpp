/**
 * @file      gt/gtl/information_set_choice_condition.cpp
 * @brief     Defines GT::GTL::InformationSetChoiceCondition methods.
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

// class InformationSetChoiceCondition final : public Condition {
// public:

InformationSetChoiceCondition::InformationSetChoiceCondition(
    const ObjectPtr definedPlayer,
    const ObjectPtr definedInformationSet,
    const ObjectPtr definedStrategy
) :
    player(definedPlayer),
    informationSet(definedInformationSet),
    strategy(definedStrategy)
    {}

Routines::ConditionPtr InformationSetChoiceCondition::getCondition(
    const Context& context
) const {
    return Routines::ConditionFactory::getInstance().createInformationSetChoiceCondition(
        createIdentifierPtr(getIdentifier(context, player)),
        createIdentifierPtr(getIdentifier(context, informationSet)),
        createIdentifierPtr(getIdentifier(context, strategy))
    );
}

Message InformationSetChoiceCondition::toString() const {
    static const IdentifierPtr playerName         = createIdentifierPtr("Player");
    static const IdentifierPtr informationSetName = createIdentifierPtr("Information Set");
    static const IdentifierPtr chosenName         = createIdentifierPtr("Chosen");

    Message result = ResultFactory::getInstance().buildResult()
        ->addResult(playerName,         createMessagePtr(player->toString()))
         .addResult(informationSetName, createMessagePtr(informationSet->toString()))
         .addResult(chosenName,         createMessagePtr(strategy->toString()))
         .build()->getResult();

    static const IdentifierPtr name  = createIdentifierPtr("Condition");
    MessagePtr                 value = createMessagePtr(result);

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class InformationSetChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
