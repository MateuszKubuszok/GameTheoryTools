#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class PlayerNameProperty {
// public:

PlayerNameProperty::PlayerNameProperty(
    Player* describedPlayer
) :
    player(describedPlayer)
    {}

ResultPtr PlayerNameProperty::findForConditions(
    const Context&,
    const Conditions&
) {
    IdentifierPtr name  = createIdentifierPtr("Name");
    MessagePtr    value = createMessagePtr(player->getName());
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
