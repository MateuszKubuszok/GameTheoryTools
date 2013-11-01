#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ValidableSymbol : public virtual Root {

void ValidableSymbol::comparisonsAreNotAllowed() const {}

// public:

ValidableSymbol::ValidableSymbol() :
    inputLocation(new InputLocation())
    {}

ValidableSymbol::~ValidableSymbol() {}

bool ValidableSymbol::isValid() const {
    return true;
}

InputLocationPtr ValidableSymbol::getInputLocation() {
    return inputLocation;
}

void ValidableSymbol::setInputLocation(
    InputLocationPtr newInputLocation
) {
    inputLocation = newInputLocation;
}

ValidableSymbol::operator SafeBoolIdiom() const {
    return isValid() ? &ValidableSymbol::comparisonsAreNotAllowed : 0;
}

// }; /* END class ValidableSymbol */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
