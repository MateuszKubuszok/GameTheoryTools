#include "gt/model/common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class DataPiece {
// public:

NumberPtr& DataPiece::getValue(
    IdentifierPtr playerName
) {
    return getValue(*playerName);
}

NumberPtr& DataPiece::operator[](
    Identifier& playerName
) {
    return getValue(playerName);
}

NumberPtr& DataPiece::operator[](
    IdentifierPtr playerName
) {
    return getValue(playerName);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
