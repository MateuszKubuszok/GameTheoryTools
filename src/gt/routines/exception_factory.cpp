#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

SINGLETON_DEFINITION(ExceptionFactory, getInstance, exceptionFactoryMutex)

// public:

InvalidCondition ExceptionFactory::invalidCondition(
    std::exception& exception
) {
    std::stringstream result;

    result << "Invalid Condition: " << exception.what();

    return InvalidCondition(result.str());
}

InvalidPlayerChoice ExceptionFactory::playerNotFound(
    Identifier& playerName
) {
    std::stringstream result;

    result << "Player \"" << playerName << "\" do not exists";

    return InvalidPlayerChoice(result.str());
}

InvalidPlayerChoice ExceptionFactory::strategyNotFound(
    Identifier& playerName,
    Identifier& strategy
) {
    std::stringstream result;

    result << "There is no strategy \"" << strategy << "\" for player \"" <<  playerName << "\"";

    return InvalidPlayerChoice(result.str());
}

// private:

ExceptionFactory::ExceptionFactory() {}

ExceptionFactory::~ExceptionFactory() {}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
