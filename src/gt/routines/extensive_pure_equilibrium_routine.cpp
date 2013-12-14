#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureEquilibriumRoutine : public SelectableStrategiesRoutine {
// public:

ResultPtr ExtensivePureEquilibriumRoutine::findResultFor(
    const GamePtr       game,
    const ConditionsPtr
) const {
    const Model::ExtensiveDataAccessorPtr data =
        boost::dynamic_pointer_cast<Model::ExtensiveDataAccessor>(game->getData());

    if (!data) {
        static Identifier extensiveGameName("Extensive Game");
        throw ExceptionFactory::getInstance().invalidGameType(extensiveGameName);
    }

    const Model::ExtensiveGamePositionsHelper positionsHelper(data->getRoot());
    const Model::ExtensiveDataNode&           root = *data->getRoot();
    ExtensivePureStrategyPath                 resultPath(game->getPlayers());

    NumbersPtr finalPayoff = getBestPayoffWhen(
        positionsHelper,
        root,
        resultPath
    );

    // TODO display result

    return ResultFactory::getInstance().constResult(Message("Not yet implemented"));
}

Message ExtensivePureEquilibriumRoutine::toString() const {
    return Message("ExtensivePureEquilibriumRoutine");
}

// private:

NumbersPtr ExtensivePureEquilibriumRoutine::getBestPayoffWhen(
    const Model::ExtensiveGamePositionsHelper& positionsHelper,
    const Model::ExtensiveDataNode&            checkedNode,
    ExtensivePureStrategyPath&                 optimalChoices
) const {
    NumbersPtr bestPayoff = createNumbersPtr();

    if (checkedNode.isLeaf()) {
        static Positions emptyPositions;
        bestPayoff = checkedNode.getValues(emptyPositions);
    } else {
        CalculatedPayoffs calculatedPayoffs;

        for (const Model::ExtensiveDataNodes::value_type& child : checkedNode.getChildren()) {
            const Identifier& strategy                = child.first;
            const Model::ExtensiveDataNode& childNode = *child.second;

            const NumbersPtr& bestSubTreePayoff = getBestPayoffWhen(
                positionsHelper,
                childNode,
                optimalChoices
            );

            calculatedPayoffs.insert( CalculatedPayoffs::value_type(strategy, bestSubTreePayoff) );
        }
        //      znajdź najlepszy wybór
        //      dodaj wybór do wyniku
    }

    return bestPayoff;
}

// }; /* END class ExtensivePureEquilibriumRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
