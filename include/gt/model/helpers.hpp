#ifndef __GT_MODEL_HELPERS_HPP__
#define __GT_MODEL_HELPERS_HPP__

namespace GT {

////////////////////////////////////////////////////////////////////////////////

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
    const char* message
);

/**
 * @brief Creates Message.
 *
 * @param message source to turn into Message
 * @return        Message
 */
Message createMessage(
    std::string message
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    boost::shared_ptr<std::string> message
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    Number number
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
Message createMessage(
    NumberPtr number
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    Index message
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    const char* message
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    std::string message
);

/**
 * @brief Creates Message.
 *
 * @param mesaage source to turn into Message
 * @return        Message
 */
MessagePtr createMessagePtr(
    boost::shared_ptr<std::string> message
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

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    Index identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    const char* identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    std::string identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
Identifier createIdentifier(
    boost::shared_ptr<std::string> identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    Index identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    const char* identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    std::string identifier
);

/**
 * @brief Creates Identifier.
 *
 * @param identifier source to turn into Identfier
 * @return           Identifier
 */
IdentifierPtr createIdentifierPtr(
    boost::shared_ptr<std::string> identifier
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
 * @param identifiers source to turn into Identfiers
 * @return            Identifiers
 */
IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
);

////////////////////////////////////////////////////////////////////////////////

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
    std::string number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
Number createNumber(
    boost::shared_ptr<std::string> number
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
    std::string number
);

/**
 * @brief Creates Number.
 *
 * @param number source to turn into Number
 * @return       Number
 */
NumberPtr createNumberPtr(
    boost::shared_ptr<std::string> number
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

////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////

namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Players.
 *
 * @return Players
 */
Players createPlayers();

/**
 * @brief Creates Players.
 *
 * @return Players
 */
PlayersPtr createPlayersPtr();

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */

////////////////////////////////////////////////////////////////////////////////

#include "gt/model/helpers.ipp"

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_HELPERS_HPP__ */
