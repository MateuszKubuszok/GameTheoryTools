#ifndef __GT_HELPERS_HPP__
#define __GT_HELPERS_HPP__

namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/helpers.hpp
 * @brief     Declares helpers for creating GT objects.
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

using std::string;

using boost::shared_ptr;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    Index message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    double message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    const char* message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    string message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    shared_ptr<string> message
);

/**
 * @brief Creates Message.
 *
 * @param number source to turn into Message
 * @return       Message
 */
Message createMessage(
    Number number
);

/**
 * @brief Creates Message.
 *
 * @param number source to turn into Message
 * @return       Message
 */
Message createMessage(
    NumberPtr number
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    Index message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    double message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    const char* message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    string message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    shared_ptr<string> message
);

/**
 * @brief Creates Message.
 *
 * @param number source to turn into Message
 * @return       Message
 */
MessagePtr createMessagePtr(
    Number number
);

/**
 * @brief Creates Messages.
 *
 * @param number source to turn into Message
 * @return       Message
 */
MessagePtr createMessagePtr(
    NumberPtr number
);

/**
 * @brief Creates Messages.
 *
 * @return Message
 */
Messages createMessages();

/**
 * @brief Creates Messages.
 *
 * @return Message
 */
MessagesPtr createMessagesPtr();

/**
 * @brief Creates Message.
 *
 * @param messages source to turn into Message
 * @return         Messages
 */
MessagesPtr createMessagesPtr(
    Messages messages
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
Identifier createIdentifier(
    Index identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
Identifier createIdentifier(
    const char* identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
Identifier createIdentifier(
    string identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
Identifier createIdentifier(
    shared_ptr<string> identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    Index identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    const char* identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    string identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identifier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    shared_ptr<string> identifier
);

/**
 * @brief Creates Identifiers.
 *
 * @return Identifiers
 */
Identifiers createIdentifiers();

/**
 * @brief Creates Identifier.
 *
 * @return Identifier
 */
IdentifiersPtr createIdentifiersPtr();

/**
 * @brief Creates Identifiers.
 *
 * @param identifiers source to turn into Identifiers
 * @return            Identifiers
 */
IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    int number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    float number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    double number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    string number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    shared_ptr<string> number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    Number number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    NumberPtr number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    int number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    float number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    double number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    string number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    shared_ptr<string> number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    Number number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    NumberPtr number
);

/**
 * @brief Creates Numbers.
 *
 * @return Numbers
 */
Numbers createNumbers();

/**
 * @brief Creates Numbers.
 *
 * @return Numbers
 */
NumbersPtr createNumbersPtr();

/**
 * @brief Creates Numbers.
 *
 * @param numbers source to turn into Numbers
 * @return        Numbers
 */
NumbersPtr createNumbersPtr(
    Numbers numbers
);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Positions.
 *
 * @return Positions
 */
Positions createPositions();

/**
 * @brief Creates Positions.
 *
 * @return Positions
 */
PositionsPtr createPositionsPtr();

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/helpers.ipp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

#endif /* END #ifndef __GT_HELPERS_HPP__ */
