#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PureGameBuilder {
// public:

GamePtr PureGameBuilder::build() {
    return GamePtr(
        new PureGame(
            plainDataBuilder->getPlayers(),
            plainDataBuilder->getData()
        )
    );
}

Message PureGameBuilder::toString() {
    // TODO
    return Message();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
