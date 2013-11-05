#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConditionFactory {

SINGLETON_DEFINITION(ConditionFactory, getInstance, conditionFactoryMutex)

// public:

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const IdentifierPtr player,
    const IdentifierPtr strategy
) {
    return ConditionPtr(
        new PlayerChoiceCondition(player, strategy)
    );
}

// private:

ConditionFactory::ConditionFactory() {}

ConditionFactory::~ConditionFactory() {}

// }; /* END class ConditionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
