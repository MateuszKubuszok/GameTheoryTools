#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExceptionFactory {

SINGLETON_DEFINITION(ExceptionFactory, getInstance, exceptionFactoryMutex)

// public:

InvalidCondition ExceptionFactory::invalidCondition(
    const std::exception& exception
) const {
    std::stringstream result;

    result << "Invalid Condition: " << exception.what();

    return InvalidCondition(result.str());
}

InvalidGameType ExceptionFactory::invalidGameType(
    const Identifier& expectedGame
) const {
    std::stringstream result;

    result << "Invalid Game Type: " << expectedGame << " expected" ;

    return InvalidGameType(result.str());
}

InvalidPlayerChoice ExceptionFactory::playerNotFound(
    const Identifier& playerName
) const {
    std::stringstream result;

    result << "Player \"" << playerName << "\" do not exists";

    return InvalidPlayerChoice(result.str());
}

InvalidPlayerChoice ExceptionFactory::strategyNotFound(
    const Identifier& playerName,
    const Identifier& strategy
) const {
    std::stringstream result;

    result << "There is no strategy \"" << strategy << "\" for player \"" <<  playerName << "\"";

    return InvalidPlayerChoice(result.str());
}

IncompletePayoffInformation ExceptionFactory::incompletePayoffInformation(
    const Identifier& playerName,
    const Identifier& strategy
) const {
    std::stringstream result;

    result << "There is no Payoff information about \"" << strategy << "\" for player \"" <<  playerName << "\"";

    return IncompletePayoffInformation(result.str());
}

// private:

ExceptionFactory::ExceptionFactory() {}

ExceptionFactory::~ExceptionFactory() {}

// }; /* END class ExceptionFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
