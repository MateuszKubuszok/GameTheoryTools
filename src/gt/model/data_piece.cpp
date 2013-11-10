#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class DataPiece : public virtual Root {
// public:

const NumberPtr& DataPiece::getValue(
    const IdentifierPtr playerName
) const {
    return getValue(*playerName);
}

const NumberPtr& DataPiece::operator[](
    const Identifier& playerName
) const {
    return getValue(playerName);
}

const NumberPtr& DataPiece::operator[](
    const IdentifierPtr playerName
) const {
    return getValue(playerName);
}

// }; /* END class DataPiece */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
