#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConditionFactory {

SINGLETON_DEFINITION(ConditionFactory, getInstance, conditionFactoryMutex)

// public:

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const ObjectPtr player,
    const ObjectPtr strategy
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

} /* END namespace GTL */
} /* END namespace GT */
