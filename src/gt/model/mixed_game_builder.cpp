#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class MixedGameBuilder {
// public:

GamePtr MixedGameBuilder::build() {
    return GamePtr(
        new MixedGame(
            plainDataBuilder->getPlayers(),
            plainDataBuilder->getData()
        )
    );
}

Message MixedGameBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Mixed Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
