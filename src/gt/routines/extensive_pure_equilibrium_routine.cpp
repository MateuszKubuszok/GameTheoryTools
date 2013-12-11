#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureEquilibriumRoutine : public SelectableStrategiesRoutine {
// public:

ResultPtr ExtensivePureEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) {
    Model::ExtensiveDataAccessorPtr data =
        boost::dynamic_pointer_cast<Model::ExtensiveDataAccessor>(game->getData());
    if (!data) {
        static Identifier extensiveGameName("Extensive Game");
        throw ExceptionFactory::getInstance().invalidGameType(extensiveGameName);
    }

    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message ExtensivePureEquilibriumRoutine::toString() const {
    return Message("ExtensivePureEquilibriumRoutine");
}

void gatherPaths() {

}

// }; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
