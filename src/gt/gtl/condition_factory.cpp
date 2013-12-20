#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConditionFactory {

ConditionFactory& ConditionFactory::getInstance() {
    static ConditionFactory instance;
    return instance;
}

// public:

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const ObjectPtr player,
    const ObjectPtr strategy
) const {
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
