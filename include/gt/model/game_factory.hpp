#ifndef __GT_MODEL_GAME_FACTORY_HPP__
#define __GT_MODEL_GAME_FACTORY_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates some simple Results as well as supplies builders for more complex of them.  
 *
 * @author Mateusz Kubuszok
 */
class GameFactory {
	 /**
     * @brief Contains pointer to a GameFactory instance.
     */
    static GameFactory* volatile instance;

     /**
     * @brief Returns the instance of a GameFactory.
     *
     * @return GameFactory instance
     */
    static GameFactory& getInstance();

    /**
     * @brief Returns Strategic Game builder.
     *
     * @return Strategic Game builder
     */
    GameBuilderPtr buildStrategicGame();

    /**
     * @brief Returns Tree Game builder.
     *
     * @return Tree Game builder
     */
    GameBuilderPtr buildTreeGame();

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

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_GAME_FACTORY_HPP__ */
