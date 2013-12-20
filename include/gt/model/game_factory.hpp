#ifndef __GT_MODEL_GAME_FACTORY_HPP__
#define __GT_MODEL_GAME_FACTORY_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates some simple Results as well as supplies builders for more complex of them.
 *
 * @author Mateusz Kubuszok
 */
class GameFactory {
public:
     /**
     * @brief Returns the instance of a GameFactory.
     *
     * @return GameFactory instance
     */
    static GameFactory& getInstance();

    /**
     * @brief Returns Strategic Game builder.
     *
     * <p>StrategyGame builder requires that Players should be set at the very beginning. It also require that
     * Each coordinate is set and its set exactly once. Otherwise InvalidCoordinate or IllegalInnerState
     * exception is thrown.</p>
     *
     * @return Strategic Game builder
     */
    GameBuilderPtr buildStrategicGame() const;

    /**
     * @brief Returns Extensive Game builder.
     *
     * <p>ExtensiveGame builder requires that Players should be set at the very beginning. It required that
     * at each node of tree only one Player is used. Different turns can have different Players. Otherwise
     * InvalidCoordinate or IllegalInnerState exception is thrown.</p>
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
