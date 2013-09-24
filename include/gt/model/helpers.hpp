#ifndef __GT_MODEL_HELPERS_HPP__
#define __GT_MODEL_HELPERS_HPP__

namespace GT {

////////////////////////////////////////////////////////////////////////////////

Message createMessage(
    Index message
);

Message createMessage(
    const char* message
);

Message createMessage(
    std::string message
);

Message createMessage(
    boost::shared_ptr<std::string> message
);

Message createMessage(
    Number number
);

Message createMessage(
    NumberPtr number
);

MessagePtr createMessagePtr(
    Index message
);

MessagePtr createMessagePtr(
    const char* message
);

MessagePtr createMessagePtr(
    std::string message
);

MessagePtr createMessagePtr(
    boost::shared_ptr<std::string> message
);

MessagePtr createMessagePtr(
    Number number
);

MessagePtr createMessagePtr(
    NumberPtr number
);

Messages createMessages();

MessagesPtr createMessagesPtr();

MessagesPtr createMessagesPtr(
    Messages messages
);

////////////////////////////////////////////////////////////////////////////////

Identifier createIdentifier(
    Index identifier
);

Identifier createIdentifier(
    const char* identifier
);

Identifier createIdentifier(
    std::string identifier
);

Identifier createIdentifier(
    boost::shared_ptr<std::string> identifier
);

IdentifierPtr createIdentifierPtr(
    Index identifier
);

IdentifierPtr createIdentifierPtr(
    const char* identifier
);

IdentifierPtr createIdentifierPtr(
    std::string identifier
);

IdentifierPtr createIdentifierPtr(
    boost::shared_ptr<std::string> identifier
);

Identifiers createIdentifiers();

IdentifiersPtr createIdentifiersPtr();

IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
);

////////////////////////////////////////////////////////////////////////////////

Number createNumber(
    int number
);

Number createNumber(
    float number
);

Number createNumber(
    double number
);

Number createNumber(
    std::string number
);

Number createNumber(
    boost::shared_ptr<std::string> number
);

Number createNumber(
    Number number
);

Number createNumber(
    NumberPtr number
);

NumberPtr createNumberPtr(
    int number
);

NumberPtr createNumberPtr(
    float number
);

NumberPtr createNumberPtr(
    double number
);

NumberPtr createNumberPtr(
    std::string number
);

NumberPtr createNumberPtr(
    boost::shared_ptr<std::string> number
);

NumberPtr createNumberPtr(
    Number number
);

NumberPtr createNumberPtr(
    NumberPtr number
);

Numbers createNumbers();

NumbersPtr createNumbersPtr();

NumbersPtr createNumbersPtr(
    Numbers numbers
);

////////////////////////////////////////////////////////////////////////////////

Positions createPositions();

PositionsPtr createPositionsPtr();

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_HELPERS_HPP__ */
