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

void PlayerChoiceCondition::conditionQuery(
    Query& //query
) const {
    // TODO when routines are implemented
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
