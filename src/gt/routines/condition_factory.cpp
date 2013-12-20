#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ConditionFactory {

ConditionFactory& ConditionFactory::getInstance() {
    static ConditionFactory instance;
    return instance;
}

// public:

ConditionPtr ConditionFactory::createPlayerChoiceCondition(
    const IdentifierPtr player,
    const IdentifierPtr strategy
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

} /* END namespace Routines */
} /* END namespace GT */
