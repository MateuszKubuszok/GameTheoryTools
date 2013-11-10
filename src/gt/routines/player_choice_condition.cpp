#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceCondition : public Condition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const IdentifierPtr definedPlayer,
    const IdentifierPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

void PlayerChoiceCondition::configureRoutine(
    RoutinePtr routine
) const {
    SelectableStrategiesRoutinePtr specificRoutine =
        boost::dynamic_pointer_cast<SelectableStrategiesRoutine>(routine);

    if (!routine)
        return;

    try {
        IdentifiersPtr availableStrategies = specificRoutine->getAvailableStrategiesForPlayer(*player);

        Identifiers::iterator strategyPosition = std::find_if(
            availableStrategies->begin(),
            availableStrategies->end(),
            [this](IdentifierPtr& currentStrategy) { return (bool) (*strategy == *currentStrategy); }
        );

        if (strategyPosition == availableStrategies->end())
            throw ExceptionFactory::getInstance().strategyNotFound(*player, *strategy);

        availableStrategies->erase(
            std::remove_if(
                availableStrategies->begin(),
                availableStrategies->end(),
                [this](IdentifierPtr& currentStrategy) { return (bool) (*strategy != *currentStrategy); }
            )
        );
    } catch (InvalidPlayerChoice& e) {
        throw ExceptionFactory::getInstance().invalidCondition(e);
    }
}

Message PlayerChoiceCondition::toString() const {
    MessagePtr strategyName = createMessagePtr(strategy);

    return ResultFactory::getInstance()
        .buildResult()->addResult(player, strategyName).build()->getResult();
}

// }; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
