#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

// class PlayerChoiceCondition {
// public:

PlayerChoiceCondition::PlayerChoiceCondition(
    const ObjectPtr definedPlayer,
    const ObjectPtr definedStrategy
) :
    player(definedPlayer),
    strategy(definedStrategy)
    {}

void PlayerChoiceCondition::conditionQuery(
    Query& //query
) {
    // TODO when routines are implemented
}

Message PlayerChoiceCondition::toString() {
    std::stringstream result;
    result << "Player \"" << player << "\" choosed \"" << strategy << "\"";

    IdentifierPtr name  = createIdentifierPtr("Condtion");
    MessagePtr    value = createMessagePtr(result.str());

    return ResultFactory::getInstance().buildResult()->addResult(name, value).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
