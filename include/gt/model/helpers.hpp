#ifndef __GT_MODEL_HELPERS_HPP__
#define __GT_MODEL_HELPERS_HPP__

namespace GT {

////////////////////////////////////////////////////////////////////////////////

/**
 * Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    Index message
);

/**
 * Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    const char* message
);

/**
 * Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    std::string message
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    boost::shared_ptr<std::string> message
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    Number number
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    NumberPtr number
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    Index message
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    const char* message
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    std::string message
);

/**
 * Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    boost::shared_ptr<std::string> message
);

/**
 * Creates Message.
 *
 * @param number source to turn into Message
 * @return       Message
 */
MessagePtr createMessagePtr(
    Number number
);

/**
 * Creates Messages.
 *
 * @param number source to turn into Message
 * @return       Message
 */
MessagePtr createMessagePtr(
    NumberPtr number
);

/**
 * Creates Messages.
 *
 * @return Message
 */
Messages createMessages();

/**
 * Creates Messages.
 *
 * @return Message
 */
MessagesPtr createMessagesPtr();

/**
 * Creates Message.
 *
 * @param messages source to turn into Message
 * @return         Messages
 */
MessagesPtr createMessagesPtr(
    Messages messages
);

////////////////////////////////////////////////////////////////////////////////

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    Index identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    const char* identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    std::string identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    boost::shared_ptr<std::string> identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    Index identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    const char* identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    std::string identifier
);

/**
 * Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    boost::shared_ptr<std::string> identifier
);

/**
 * Creates Identifiers.
 *
 * @return Identifiers
 */
Identifiers createIdentifiers();

/**
 * Creates Identifier.
 *
 * @return Identifier
 */
IdentifiersPtr createIdentifiersPtr();

/**
 * Creates Identifiers.
 *
 * @param identifiers source to turn into Identfiers
 * @return            Identifiers
 */
IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
);

////////////////////////////////////////////////////////////////////////////////

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    int number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    float number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    double number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    std::string number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    boost::shared_ptr<std::string> number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    Number number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    NumberPtr number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    int number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    float number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    double number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    std::string number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    boost::shared_ptr<std::string> number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    Number number
);

/**
 * Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    NumberPtr number
);

/**
 * Creates Numbers.
 *
 * @return Numbers
 */
Numbers createNumbers();

/**
 * Creates Numbers.
 *
 * @return Numbers
 */
NumbersPtr createNumbersPtr();

/**
 * Creates Numbers.
 *
 * @param numbers source to turn into Numbers
 * @return        Numbers
 */
NumbersPtr createNumbersPtr(
    Numbers numbers
);

////////////////////////////////////////////////////////////////////////////////

/**
 * Creates Positions.
 *
 * @return Positions
 */
Positions createPositions();

/**
 * Creates Positions.
 *
 * @return Positions
 */
PositionsPtr createPositionsPtr();

////////////////////////////////////////////////////////////////////////////////

namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * Creates Players.
 *
 * @return Players
 */
Players createPlayers();

/**
 * Creates Players.
 *
 * @return Players
 */
PlayersPtr createPlayersPtr();

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_HELPERS_HPP__ */
