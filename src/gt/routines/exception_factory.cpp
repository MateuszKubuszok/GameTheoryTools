/**
 * @file      gt/routines/exception_factory.cpp
 * @brief     Defines GT::Routines::ExceptionFactory methods.
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

using std::stringstream;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory final {
// public:

ExceptionFactory& ExceptionFactory::getInstance() {
    static ExceptionFactory instance;
    return instance;
}

InvalidCondition ExceptionFactory::invalidCondition(
    const std::exception& exception
) const {
    stringstream result;

    result << "Invalid Condition: " << exception.what();

    return InvalidCondition(result.str());
}

InvalidCondition ExceptionFactory::contradictoryConditions() const {
    return InvalidCondition("Contradictory conditions lead to an invalid configuration");
}

InvalidGameType ExceptionFactory::invalidGameType(
    const Identifier& expectedGame
) const {
    stringstream result;

    result << "Invalid Game Type: " << expectedGame << " expected" ;

    return InvalidGameType(result.str());
}

InvalidPlayerChoice ExceptionFactory::playerNotFound(
    const Identifier& playerName
) const {
    stringstream result;

    result << "Player \"" << playerName << "\" do not exists";

    return InvalidPlayerChoice(result.str());
}

InvalidPlayerChoice ExceptionFactory::strategyNotFound(
    const Identifier& playerName,
    const Identifier& strategy
) const {
    stringstream result;

    result << "There is no strategy \"" << strategy << "\" for player \"" <<  playerName << "\"";

    return InvalidPlayerChoice(result.str());
}

InvalidPlayerChoice ExceptionFactory::informationSetNotFound(
    const Identifier& playerName,
    const Identifier& informationSet
) const {
    stringstream result;

    result << "There is no information set \"" << informationSet << "\" for player \"" <<  playerName << "\"";

    return InvalidPlayerChoice(result.str());
}

IncompletePayoffInformation ExceptionFactory::incompletePayoffInformation(
    const Identifier& playerName,
    const Identifier& strategy
) const {
    stringstream result;

    result << "There is no Payoff information about \"" << strategy
           << "\" for player \"" <<  playerName << "\"";

    return IncompletePayoffInformation(result.str());
}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
