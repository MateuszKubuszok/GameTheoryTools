/**
 * @file      gt/gtl/game.cpp
 * @brief     Defines GT::GTL::Game methods.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/inner_common.hpp"

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using std::endl;
using std::stringstream;

using boost::dynamic_pointer_cast;
using boost::shared_ptr;
using boost::make_shared;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class Game : public Object {
// public:

Game::Game(
    const Model::GamePtr gameImplementation
) :
    Object(createIdentifier("Game")),
    game(gameImplementation),
    gameType(createIdentifierPtr(""))
{
    registerProperty(
        Identifier("pure_equilibrium"),     make_shared<GamePureEquilibriumProperty>(this)
    );
    registerProperty(
        Identifier("mixed_equilibrium"),    make_shared<GameMixedEquilibriumProperty>(this)
    );
    registerProperty(
        Identifier("behavior_equilibrium"), make_shared<GameBehaviorEquilibriumProperty>(this)
    );
}

Game::Game(
    const Model::GamePtr gameImplementation,
    const IdentifierPtr  gameTypeName
) :
    Object(createIdentifier("Game")),
    game(gameImplementation),
    gameType(gameTypeName)
{
    registerProperty(
        Identifier("pure_equilibrium"),     make_shared<GamePureEquilibriumProperty>(this)
    );
    registerProperty(
        Identifier("mixed_equilibrium"),    make_shared<GameMixedEquilibriumProperty>(this)
    );
    registerProperty(
        Identifier("behavior_equilibrium"), make_shared<GameBehaviorEquilibriumProperty>(this)
    );
}

ResultPtr Game::pureEquilibrium(
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().pureStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions = make_shared<Routines::Conditions>();
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

ResultPtr Game::mixedEquilibrium(
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().mixedStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions = make_shared<Routines::Conditions>();
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

ResultPtr Game::behaviorEquilibrium(
    const Context&    context,
    const Conditions& conditions
) const {
    Routines::RoutinePtr routine =
        Routines::RoutineFactory::getInstance().behaviourStrategyEquilibriumFindingRoutineFor(game);

    Routines::ConditionsPtr routineConditions = make_shared<Routines::Conditions>();
    for (const ConditionPtr& condition : conditions)
        routineConditions->push_back(condition->getCondition(context));

    return routine->findResultFor(game, routineConditions);
}

const IdentifierPtr Game::getGameType() const {
    return gameType;
}

Message Game::serialize() const {
    stringstream result;

    if (!gameType->empty())
        result << *gameType << ' ';
    result << "GAME WITH\n";

    const shared_ptr<LazyGameProxy> lazyGame = dynamic_pointer_cast<LazyGameProxy>(game);
    if (lazyGame) {
        const ObjectsPtr players = lazyGame->getPlayersParams();
        if (players->size()) {
            stringstream subresult;

            bool firstElement = true;
            for (const ObjectPtr& player : *players) {
                if (!firstElement)
                    subresult << ',' << endl;
                subresult << player->serialize();
                firstElement = false;
            }

            result << addIndent(subresult.str()) << endl;
        }

        result << "SUCH AS" << endl;
        stringstream subresult;

        bool firstElement = true;
        for (const CoordinatePtr& coordinate : *lazyGame->getCoordinates()) {
            if (!firstElement)
                subresult << ',' << endl;
            subresult << coordinate->serialize();
            firstElement = false;
        }

        result << addIndent(subresult.str()) << endl;
    } else
        result << addIndent("!! CANNOT RECOVER DATA !!") << endl;

    result << "END";

    return result.str();
}

Message Game::toString() const {
    return game->toString();
}

const Game& Game::toGame() const {
    return *this;
}

// }; /* END class Game */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */
