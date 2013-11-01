#include "gt/model/inner_common.hpp"

namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Message createMessage(
    Index message
) {
    std::stringstream result;
    result << message;
    return Message(result.str());
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Identifier createIdentifier(
    Index identifier
) {
    std::stringstream result;
    result << identifier;
    return Identifier(result.str());
}

IdentifierPtr createIdentifierPtr(
    Index identifier
) {
    std::stringstream result;
    result << identifier;
    return IdentifierPtr(new Identifier(result.str()));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GT */
