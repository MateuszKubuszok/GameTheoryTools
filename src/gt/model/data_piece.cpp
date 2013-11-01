#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DataPiece : public virtual Root {
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

// }; /* END class DataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
