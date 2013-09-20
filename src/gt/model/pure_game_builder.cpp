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
    IdentifierPtr name    = createIdentifierPtr("Current Pure Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
