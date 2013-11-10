#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerStrategiesProperty : public ObjectProperty {
// public:

PlayerStrategiesProperty::PlayerStrategiesProperty(
    const Player* describedPlayer
) :
    player(describedPlayer)
    {}

ResultPtr PlayerStrategiesProperty::findForConditions(
    const Context&,
    const Conditions&
) const {
    IdentifierPtr strategiesName  = createIdentifierPtr("Strategies");

    IdentifierPtr name  = createIdentifierPtr("Strategy");
    ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();
    for (IdentifierPtr& strategy : *player->getStrategies()) {
        MessagePtr value = createMessagePtr(strategy);
        subResultBuilder->addResult(name, value);
    }
    MessagePtr strategiesValue = createMessagePtr(subResultBuilder->buildRaw()->getResult());

    return ResultFactory::getInstance().buildResult()->addResult(strategiesName, strategiesValue).build();
}

// }; /* END class PlayerStrategiesProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
