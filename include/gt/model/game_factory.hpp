#ifndef __GT_MODEL_GAME_FACTORY_HPP__
#define __GT_MODEL_GAME_FACTORY_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/game_factory.hpp
 * @brief     Defines GT::Model::GameFactory class.
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

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class GameFactory
 * @brief Creates GameBuilders for required types of Games.
 *
 * @author Mateusz Kubuszok
 */
class GameFactory final {
public:
     /**
     * @brief Returns the instance of a GameFactory.
     *
     * @return GameFactory instance
     */
    static GameFactory& getInstance();

    /**
     * @brief Returns StrategicGame builder.
     *
     * StrategyGame builder requires that Players should be set at the very beginning. It also require that
     * Each coordinate is set and its set exactly once. Otherwise InvalidCoordinate or IllegalInnerState
     * exception is thrown.
     *
     * @return Strategic Game builder
     */
    GameBuilderPtr buildStrategicGame() const;

    /**
     * @brief Returns ExtensiveGame builder.
     *
     * ExtensiveGame builder requires that Players should be set at the very beginning. It required that
     * at each node of tree only one Player is used. Different turns can have different Players. Otherwise
     * InvalidCoordinate or IllegalInnerState exception is thrown.
     *
     * @return Extensive Game builder
     */
    GameBuilderPtr buildExtensiveGame() const;

private:
    /**
     * @brief Private constructor.
     */
    GameFactory();

    /**
     * @brief Private copy constructor.
     */
    GameFactory(
        const GameFactory& gameFactory
    );

    /**
     * @brief Private destructor.
     */
    ~GameFactory();
}; /* END class GameFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_GAME_FACTORY_HPP__ */
