#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerNameProperty : public ObjectProperty {
// public:

PlayerNameProperty::PlayerNameProperty(
    const Player* describedPlayer
) :
    player(describedPlayer)
    {}

ResultPtr PlayerNameProperty::findForConditions(
    const Context&,
    const Conditions&
) const {
    IdentifierPtr name  = createIdentifierPtr("Name");
    MessagePtr    value = createMessagePtr(player->getName());
    return ResultFactory::getInstance().buildResult()->addResult(name, value).build();
}

// }; /* END class PlayerNameProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
