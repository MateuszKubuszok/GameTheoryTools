// namespace GT {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Message createMessage(
    const char* message
) {
    return Message(message);
}

inline Message createMessage(
    std::string message
) {
    return Message(message);
}

inline Message createMessage(
    boost::shared_ptr<std::string> message
) {
    return Message(*message);
}

inline MessagePtr createMessagePtr(
    const char* message
) {
    return MessagePtr(new Message(message));
}

inline MessagePtr createMessagePtr(
    std::string message
) {
    return MessagePtr(new Message(message));
}

inline MessagePtr createMessagePtr(
    boost::shared_ptr<std::string> message
) {
    return message;
}


inline Messages createMessages() {
    return Messages();
}

inline MessagesPtr createMessagesPtr() {
    return MessagesPtr(new Messages());
}

inline MessagesPtr createMessagesPtr(
    Messages messages
) {
    return MessagesPtr(new Messages(messages));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Identifier createIdentifier(
    const char* identifier
) {
    return Identifier(identifier);
}

inline Identifier createIdentifier(
    std::string identifier
) {
    return Identifier(identifier);
}

inline Identifier createIdentifier(
    boost::shared_ptr<std::string> identifier
) {
    return Identifier(*identifier);
}

inline IdentifierPtr createIdentifierPtr(
    const char* identifier
) {
    return IdentifierPtr(new Identifier(identifier));
}

inline IdentifierPtr createIdentifierPtr(
    std::string identifier
) {
    return IdentifierPtr(new Identifier(identifier));
}

inline IdentifierPtr createIdentifierPtr(
    boost::shared_ptr<std::string> identifier
) {
    return identifier;
}

inline Identifiers createIdentifiers() {
    return Identifiers();
}

inline IdentifiersPtr createIdentifiersPtr() {
    return IdentifiersPtr(new Identifiers());
}

inline IdentifiersPtr createIdentifiersPtr(
    Identifiers identifiers
) {
    return IdentifiersPtr(new Identifiers(identifiers));
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
    std::string number
) {
    return Number(number);
}

inline Number createNumber(
    boost::shared_ptr<std::string> number
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
    return NumberPtr(new Number(number));
}

inline NumberPtr createNumberPtr(
    float number
) {
    return NumberPtr(new Number(number));
}

inline NumberPtr createNumberPtr(
    double number
) {
    return NumberPtr(new Number(number));
}

inline NumberPtr createNumberPtr(
    std::string number
) {
    return NumberPtr(new Number(number));
}

inline NumberPtr createNumberPtr(
    boost::shared_ptr<std::string> number
) {
    return NumberPtr(new Number(*number));
}

inline NumberPtr createNumberPtr(
    Number number
) {
    return NumberPtr(new Number(number));
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
    return NumbersPtr(new Numbers());
}

inline NumbersPtr createNumbersPtr(
    Numbers numbers
) {
    return NumbersPtr(new Numbers(numbers));
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Positions createPositions() {
    return Positions();
}

inline PositionsPtr createPositionsPtr() {
    return PositionsPtr(new Positions());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

inline Players createPlayers() {
    return Players();
}

inline PlayersPtr createPlayersPtr() {
    return PlayersPtr(new Players());
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
// } /* END nampespace GT*/
