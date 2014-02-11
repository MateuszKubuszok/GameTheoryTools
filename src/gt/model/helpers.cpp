/**
 * @file      gt/model/helpers.cpp
 * @brief     Defines GT::Model helpers.
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

#include "gt/model/inner_common.hpp"

namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::stringstream;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message createMessage(
    Index message
) {
    stringstream result;
    result << message;
    return Message(result.str());
}

Message createMessage(
    double message
) {
    stringstream result;
    result << message;
    return Message(result.str());
}

Message createMessage(
    Number number
) {
    stringstream result;
    result << std::setprecision(5) << number;
    return result.str();
}

Message createMessage(
    NumberPtr number
) {

    stringstream result;
    result << std::setprecision(5) << (*number);
    return result.str();
}

MessagePtr createMessagePtr(
    Index message
) {
    stringstream result;
    result << message;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    double message
) {
    stringstream result;
    result << message;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    Number number
) {
    stringstream result;
    result << std::setprecision(5) << number;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    NumberPtr number
) {
    stringstream result;
    result << std::setprecision(5) << (*number);
    return MessagePtr(new Message(result.str()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Identifier createIdentifier(
    Index identifier
) {
    stringstream result;
    result << identifier;
    return Identifier(result.str());
}

IdentifierPtr createIdentifierPtr(
    Index identifier
) {
    stringstream result;
    result << identifier;
    return IdentifierPtr(new Identifier(result.str()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */
