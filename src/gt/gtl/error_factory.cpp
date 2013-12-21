/**
 * @file      gt/gtl/error_factory.cpp
 * @brief     Defines GT::GTL::ErrorFactory methods.
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

// class ErrorFactory {

ErrorFactory& ErrorFactory::getInstance() {
    static ErrorFactory instance;
    return instance;
}

// public:

ConditionPtr ErrorFactory::createCondition(
    const Message errorMessage
) const {
    return ConditionPtr(new ErrorCondition(errorMessage));
}

CoordinatePtr ErrorFactory::createCoordinate(
    const Message errorMessage
) const {
    return CoordinatePtr(new ErrorCoordinate(errorMessage));
}

DefinitionPtr ErrorFactory::createDefinition(
    const Message errorMessage
) const {
    return DefinitionPtr(new ErrorDefinition(errorMessage));
}

DetailsPtr ErrorFactory::createDetails(
    const Message errorMessage
) const {
    return DetailsPtr(new ErrorDetails(errorMessage));
}

GamePtr ErrorFactory::createGame(
    const Message errorMessage
) const {
    return GamePtr(new ErrorGame(errorMessage));
}

ObjectPtr ErrorFactory::createObject(
    const Message errorMessage
) const {
    return ObjectPtr(new ErrorObject(errorMessage));
}

ParamPtr ErrorFactory::createParam(
    const Message errorMessage
) const {
    return ParamPtr(new ErrorParam(errorMessage));
}

PlayerPtr ErrorFactory::createPlayer(
    const Message errorMessage
) const {
    return PlayerPtr(new ErrorPlayer(errorMessage));
}

QueryPtr ErrorFactory::createQuery(
    const Message errorMessage
) const {
    return QueryPtr(new ErrorQuery(errorMessage));
}

// private:

ErrorFactory::ErrorFactory() {}

ErrorFactory::~ErrorFactory() {}

// }; /* END class ErrorFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
