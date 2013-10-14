#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class ValidableSymbol {

void ValidableSymbol::comparisonsAreNotAllowed() const {}

// public:

ValidableSymbol::~ValidableSymbol() {}

bool ValidableSymbol::isValid() const {
    return true;
}

ValidableSymbol::operator SafeBoolIdiom() const {
    return isValid() ? &ValidableSymbol::comparisonsAreNotAllowed : 0;
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
