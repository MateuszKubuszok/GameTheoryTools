#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class Player {
// public:

Player::Player(
    const IdentifierPtr  playerName,
    const IdentifiersPtr playerStrategies
) :
    name(playerName),
    strategies(playerStrategies),
    strategyMapping(),
    probabilities()
{
    if (!strategies->empty()) {
        Number probability = Number(1)/Number(strategies->size());
    
        Index index = 0;
        BOOST_FOREACH(IdentifierPtr& strategy, *strategies) {
            probabilities.insert( ProbabilityMap::value_type(*strategy, probability) );
            strategyMapping.insert( StrategyMap::value_type(*strategy, index++) );
        }
    }
}

Player& Player::setProbabilities(
    NumbersPtr chances
) {
    if (chances->size() != strategies->size())
        throw ExceptionFactory::getInstance()
                .probabilitiesAndStrategiesDontMatchInSize(
                    strategies->size(),
                    chances->size()
                );

    Number maxChances(1);
    for (Index i = 0; i < chances->size(); i++) {
        Number&     chance   = (*(*chances)[i]);
        Identifier& strategy = (*(*strategies)[i]);

        if (chance < 0 || chance > 1)
            throw ExceptionFactory::getInstance().invalidProbability(strategy, chance);
        
        maxChances -= chance;
        if (maxChances < 0)
            throw ExceptionFactory::getInstance().invalidDistribution();
    }
    // TODO check whether result is around 0

    for (Index i = 0; i < chances->size(); i++) {
        Number&     chance   = (*(*chances)[i]);
        Identifier& strategy = (*(*strategies)[i]);
        probabilities.insert( ProbabilityMap::value_type(strategy, chance) );
    }

    return *this;
}

IdentifierPtr Player::getName() {
    return name;
}

IdentifiersPtr Player::getStrategies() {
    return strategies;
}

Index Player::getStrategiesNumber() {
    return strategies->size();
}

Index Player::getStrategyOrdinal(
    Identifier& strategy
) {
    if (strategyMapping.count(strategy))
        return strategyMapping[strategy];
    throw ExceptionFactory::getInstance().invalidStrategy(strategy);
}

Number Player::getStrategyProbability(
    Identifier& strategy
) {
    if (probabilities.count(strategy))
        return probabilities[strategy];
    throw ExceptionFactory::getInstance().invalidStrategy(strategy);
}

bool Player::hasStrategy(
    Identifier& strategy
) {
    return strategyMapping.count(strategy);
}

Message Player::toString() {
    ResultBuilderPtr resultBuilder = ResultFactory::getInstance().buildResult();
    BOOST_FOREACH(IdentifierPtr& strategy, *strategies) {
        IdentifierPtr name  = createIdentifierPtr(getStrategyOrdinal(*strategy));
        MessagePtr    value = createMessagePtr(strategy);
        resultBuilder->addResult(name, value);
    }
    return resultBuilder->build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
