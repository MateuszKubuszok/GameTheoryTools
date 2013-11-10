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
    const Model::GameBuilderPtr gameBuilder;
    /**
     * @brief Players.
     */
    const ObjectsPtr            players;
    /**
     * @brief Coordinates to setup data.
     */
    const CoordinatesPtr        coordinates;
    /**
     * @brief Context.
     */
    const Context*              context;

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
        const Model::GameBuilderPtr gameBuilder,
        const ObjectsPtr            players,
        const CoordinatesPtr        coordinates,
        const Context*              context
    );

    /**
     * @brief Returns Game's Players.
     *
     * @return Players
     */
    virtual const Model::PlayersPtr getPlayers() const override;

    /**
     * @brief Grants access to Data specific to a Game.
     *
     * @return DataAccessor returns DataAccessor specific for a Game
     */
    virtual const Model::DataAccessorPtr getData() const override;

    /**
     * @brief Game's Message.
     *
     * @return message
     */
    virtual Message toString() const override;

private:
    /**
     * @brief Create temporary instance of Game.
     *
     * @return Games instance
     */
    const Model::GamePtr accessGame() const;
}; /* END class LazyGameProxy */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_LAZY_GAME_PROXY_HPP__ */
