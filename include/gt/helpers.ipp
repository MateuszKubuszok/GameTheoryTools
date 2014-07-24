// namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/helpers.ipp
 * @brief     Defines helpers for creating GT objects.
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

inline Message createMessage(
    const char* message
) {
    return Message(message);
}

inline Message createMessage(
    string message
) {
    return Message(message);
}

inline Message createMessage(
    shared_ptr<string> message
) {
    return Message(*message);
}

inline MessagePtr createMessagePtr(
    const char* message
) {
    return boost::make_shared<Message>(message);
}

inline MessagePtr createMessagePtr(
    string message
) {
    return boost::make_shared<Message>(message);
}

inline MessagePtr createMessagePtr(
    shared_ptr<string> message
) {
    return message;
}

inline Messages createMessages() {
    return Messages();
}

inline MessagesPtr createMessagesPtr() {
    return boost::make_shared<Messages>();
}

inline MessagesPtr createMessagesPtr(
    Messages messages
) {
    return boost::make_shared<Messages>(messages);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Identifier createIdentifier(
    const char* identifier
) {
    return Identifier(identifier);
}

inline Identifier createIdentifier(
    string identifier
) {
    return Identifier(identifier);
}

inline Identifier createIdentifier(
    shared_ptr<string> identifier
) {
    return Identifier(*identifier);
}

inline IdentifierPtr createIdentifierPtr(
    const char* identifier
) {
    return boost::make_shared<Identifier>(identifier);
}

inline IdentifierPtr createIdentifierPtr(
    string identifier
) {
    return boost::make_shared<Identifier>(identifier);
}

inline IdentifierPtr createIdentifierPtr(
    shared_ptr<string> identifier
) {
    return identifier;
}

inline Identifiers createIdentifiers() {
    return Identifiers();
}

inline IdentifiersPtr createIdentifiersPtr() {
    return boost::make_shared<Identifiers>();
}

inline IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
) {
    return boost::make_shared<Identifiers>(identifiers);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Number createNumber(
    int number
) {
    return Number(number);
}

inline Number createNumber(
    float number
) {
    return Number(number);
}

inline Number createNumber(
    double number
) {
    return Number(number);
}

inline Number createNumber(
    string number
) {
    return Number(number);
}

inline Number createNumber(
    shared_ptr<string> number
) {
    return Number(*number);
}

inline Number createNumber(
    Number number
) {
    return number;
}

inline Number createNumber(
    NumberPtr number
) {
    return *number;
}

inline NumberPtr createNumberPtr(
    int number
) {
    return boost::make_shared<Number>(number);
}

inline NumberPtr createNumberPtr(
    float number
) {
    return boost::make_shared<Number>(number);
}

inline NumberPtr createNumberPtr(
    double number
) {
    return boost::make_shared<Number>(number);
}

inline NumberPtr createNumberPtr(
    string number
) {
    return boost::make_shared<Number>(number);
}

inline NumberPtr createNumberPtr(
    shared_ptr<string> number
) {
    return boost::make_shared<Number>(*number);
}

inline NumberPtr createNumberPtr(
    Number number
) {
    return boost::make_shared<Number>(number);
}

inline NumberPtr createNumberPtr(
    NumberPtr number
) {
    return number;
}

inline Numbers createNumbers() {
    return Numbers();
}

inline NumbersPtr createNumbersPtr() {
    return boost::make_shared<Numbers>();
}

inline NumbersPtr createNumbersPtr(
    Numbers numbers
) {
    return boost::make_shared<Numbers>(numbers);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Positions createPositions() {
    return Positions();
}

inline PositionsPtr createPositionsPtr() {
    return boost::make_shared<Positions>();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// } /* END nampespace GT*/
