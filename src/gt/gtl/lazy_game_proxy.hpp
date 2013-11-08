#ifndef __GT_GTL_LAZY_GAME_PROXY_HPP__
#define __GT_GTL_LAZY_GAME_PROXY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Makes Game act in functional manner by building it from scratch each time some property is required.
 *
 * @author Mateusz Kubuszok
 *
 * @see Model::Game
 * @see Model::GameBuilder
 * @see Coordinate
 * @see Context
 */
class LazyGameProxy : public Model::Game {
    /**
     * @brief Actual Game's builder.
     */
    Model::GameBuilderPtr gameBuilder;
    /**
     * @brief Players.
     */
    ObjectsPtr            players;
    /**
     * @brief Coordinates to setup data.
     */
    CoordinatesPtr        coordinates;
    /**
     * @brief Context.
     */
    Context*              context;

public:
    /**
     * @brief Initiates lazy proxy with data required to instantiate Game.
     *
     * @param gameBuilder builder that will create Game
     * @param players     Players definitions
     * @param coordinates Cooridnates with payoff
     * @param context     actual Context
     */
    LazyGameProxy(
        Model::GameBuilderPtr gameBuilder,
        ObjectsPtr            players,
        CoordinatesPtr        coordinates,
        Context*              context
    );

    /**
     * @brief Returns Game's Players.
     *
     * @return Players
     */
    virtual Model::PlayersPtr getPlayers() override;

    /**
     * @brief Grants access to Data specific to a Game.
     *
     * @return DataAccessor returns DataAccessor specific for a Game
     */
    virtual Model::DataAccessorPtr getData() override;

    /**
     * @brief Game's Message.
     *
     * @return message
     */
    virtual Message toString() override;

private:
    /**
     * @brief Create temporary instance of Game.
     *
     * @return Games instance
     */
    Model::GamePtr accessGame();
}; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_LAZY_GAME_PROXY_HPP__ */
