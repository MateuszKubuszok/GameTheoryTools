#include "gt/model/inner_common.hpp"

namespace GT {

////////////////////////////////////////////////////////////////////////////////

Message createMessage(
    Index message
) {
    std::stringstream result;
    result << message;
    return Message(result.str());
}

Message createMessage(
    const char* message
) {
    return Message(message);
}

Message createMessage(
    std::string message
) {
    return Message(message);
}

Message createMessage(
    boost::shared_ptr<std::string> message
) {
    return Message(*message);
}

Message createMessage(
    Number number
) {
    std::stringstream result;
    result << std::setprecision(5) << number;
    return result.str();
}

Message createMessage(
    NumberPtr number
) {

    std::stringstream result;
    result << std::setprecision(5) << (*number);
    return result.str();
}

MessagePtr createMessagePtr(
    Index message
) {
    std::stringstream result;
    result << message;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    const char* message
) {
    return MessagePtr(new Message(message));
}

MessagePtr createMessagePtr(
    std::string message
) {
    return MessagePtr(new Message(message));
}

MessagePtr createMessagePtr(
    boost::shared_ptr<std::string> message
) {
    return message;
}

MessagePtr createMessagePtr(
    Number number
) {
    std::stringstream result;
    result << std::setprecision(5) << number;
    return MessagePtr(new Message(result.str()));
}

MessagePtr createMessagePtr(
    NumberPtr number
) {
    std::stringstream result;
    result << std::setprecision(5) << (*number);
    return MessagePtr(new Message(result.str()));
}

Messages createMessages() {
    return Messages();
}

MessagesPtr createMessagesPtr() {
    return MessagesPtr(new Messages());
}

MessagesPtr createMessagesPtr(
    Messages messages
) {
    return MessagesPtr(new Messages(messages));
}

////////////////////////////////////////////////////////////////////////////////

Identifier createIdentifier(
    Index identifier
) {
    std::stringstream result;
    result << identifier;
    return Identifier(result.str());
}

Identifier createIdentifier(
    const char* identifier
) {
    return Identifier(identifier);
}

Identifier createIdentifier(
    std::string identifier
) {
    return Identifier(identifier);
}

Identifier createIdentifier(
    boost::shared_ptr<std::string> identifier
) {
    return Identifier(*identifier);
}

IdentifierPtr createIdentifierPtr(
    Index identifier
) {
    std::stringstream result;
    result << identifier;
    return IdentifierPtr(new Identifier(result.str()));
}

IdentifierPtr createIdentifierPtr(
    const char* identifier
) {
    return IdentifierPtr(new Identifier(identifier));
}

IdentifierPtr createIdentifierPtr(
    std::string identifier
) {
    return IdentifierPtr(new Identifier(identifier));
}

IdentifierPtr createIdentifierPtr(
    boost::shared_ptr<std::string> identifier	
) {
    return identifier;
}

Identifiers createIdentifiers() {
    return Identifiers();
}

IdentifiersPtr createIdentifiersPtr() {
    return IdentifiersPtr(new Identifiers());
}

IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
) {
    return IdentifiersPtr(new Identifiers(identifiers));
}

////////////////////////////////////////////////////////////////////////////////

Number createNumber(
    int number
) {
    return Number(number);
}

Number createNumber(
    float number
) {
    return Number(number);
}

Number createNumber(
    double number
) {
    return Number(number);
}

Number createNumber(
    std::string number
) {
    return Number(number);
}

Number createNumber(
    boost::shared_ptr<std::string> number
) {
    return Number(*number);
}

Number createNumber(
    Number number
) {
    return number;
}

Number createNumber(
    NumberPtr number
) {
    return *number;
}

NumberPtr createNumberPtr(
    int number
) {
    return NumberPtr(new Number(number));
}

NumberPtr createNumberPtr(
    float number
) {
    return NumberPtr(new Number(number));
}

NumberPtr createNumberPtr(
    double number
) {
    return NumberPtr(new Number(number));
}

NumberPtr createNumberPtr(
    std::string number
) {
    return NumberPtr(new Number(number));
}

NumberPtr createNumberPtr(
    boost::shared_ptr<std::string> number
) {
    return NumberPtr(new Number(*number));
}

NumberPtr createNumberPtr(
    Number number
) {
    return NumberPtr(new Number(number));
}

NumberPtr createNumberPtr(
    NumberPtr number
) {
    return number;
}

Numbers createNumbers() {
    return Numbers();
}

NumbersPtr createNumbersPtr() {
    return NumbersPtr(new Numbers());
}

NumbersPtr createNumbersPtr(
    Numbers numbers
) {
    return NumbersPtr(new Numbers(numbers));
}

////////////////////////////////////////////////////////////////////////////////

Positions createPositions() {
    return Positions();
}

PositionsPtr createPositionsPtr() {
    return PositionsPtr(new Positions());
}

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */
