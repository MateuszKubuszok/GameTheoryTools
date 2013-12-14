#include "gt/routines/inner_common.hpp"

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensivePureStrategyPath {
// public:

ExtensivePureStrategyPath::ExtensivePureStrategyPath(
    const PlayersPtr playersDefinitions
) :
    players(playersDefinitions),
    payoffs(Model::NullFactory::getInstance().createDataPiece()),
    playersChoices()
{
    for (Players::value_type& player : *players)
        playersChoices.insert( PlayersChoices::value_type(player.first, Positions()) );
}

ExtensivePureStrategyPath& ExtensivePureStrategyPath::addOlderChoice(
    const Identifier& informationSet,
    const Identifier& player,
    const Identifier& strategy
) {
    if (!players->count(player) || !playersChoices.count(player))
        throw ExceptionFactory::getInstance().playerNotFound(player);
    if (!(*players)[player]->hasStrategy(strategy))
        throw ExceptionFactory::getInstance().strategyNotFound(player, strategy);

    Positions& choices = playersChoices[player];
    choices.insert( choices.begin(), Positions::value_type( informationSet, strategy ) );

    return *this;
}

const ExtensivePureStrategyPath::PlayersChoices& ExtensivePureStrategyPath::getPlayersChoices() const {
    return playersChoices;
}

const Model::DataPiecePtr ExtensivePureStrategyPath::getPayoff() const {
    return payoffs;
}

ExtensivePureStrategyPath& ExtensivePureStrategyPath::setPayoff(
    Model::DataPiecePtr newPayoffs
) {
    payoffs = newPayoffs;
    return *this;
}

Message ExtensivePureStrategyPath::toString() const {
    static IdentifierPtr payoffName = createIdentifierPtr("Payoffs");

    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();

    for (PlayersChoices::value_type playerChoices : playersChoices) {
        ResultBuilderPtr subResultBuilder = ResultFactory::getInstance().buildResult();

        for (Positions::value_type& choice : playerChoices.second)
            subResultBuilder->addResult( createIdentifierPtr(choice.first), createMessagePtr(choice.second) );

        resultBuilder->addResult(
            createIdentifierPtr(playerChoices.first),
            createMessagePtr(subResultBuilder->build()->getResult())
        );
    }

    resultBuilder->addResult(
        payoffName,
        createMessagePtr(payoffs->toString())
    );

    return resultBuilder->build()->getResult();
}

// }; /* END class ExtensivePureStrategyPath */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */
