#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceCondition : public Condition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const ObjectPtr definedPlayer,
    const ObjectPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

Routines::ConditionPtr PlayerChoiceCondition::getCondition(
    const Context&
) const {
    const boost::shared_ptr<IdentifierParam> playerParam =
        boost::dynamic_pointer_cast<IdentifierParam>(player);
    const boost::shared_ptr<IdentifierParam> strategyParam =
        boost::dynamic_pointer_cast<IdentifierParam>(strategy);

    if (!playerParam || !strategyParam) {
        Identifier expectedType = createIdentifier("Identifier Param");
        throw ExceptionFactory::getInstance().invalidObjectType(expectedType);
    }

    return Routines::ConditionFactory::getInstance().createPlayerChoiceCondition(
        createIdentifierPtr(playerParam->getIdentifier()),
        createIdentifierPtr(strategyParam->getIdentifier())
    );
}

Message PlayerChoiceCondition::toString() const {
    std::stringstream result;
    result << "Player \"" << player << "\" choosed \"" << strategy << "\"";

    static const IdentifierPtr name  = createIdentifierPtr("Condtion");
    MessagePtr                 value = createMessagePtr(result.str());

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }; /* END class PlayerChoiceCondition */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
