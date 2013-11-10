#ifndef __GT_MODEL_EXTENSIVE_GAME_BUILDER_HPP__
#define __GT_MODEL_EXTENSIVE_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating ExtensiveGame.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveGame
 * @see ExtensiveDataBuilder
 */
class ExtensiveGameBuilder : public GameBuilder {
    /**
     * @brief Game's DataBuilder.
     */
    ExtensiveDataBuilderPtr extensiveDataBuilder;

public:
    /**
     * @brief Defalt constructor.
     */
    ExtensiveGameBuilder();

    /**
     * @brief Returns set up Game.
     *
     * @return built Game
     */
    virtual GamePtr build() const override;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual const PlayersPtr getPlayers() const override;

    /**
     * @brief Sets Players' definitions.
     *
     * @param newPlayers Players' definitions
     * @return           reference to itself for chanining
     */
    virtual DataBuilder& setPlayers(
        const PlayersPtr newPlayers
    ) override;

    /**
     * @brief Specifies next Positions.
     *
     * @param positions next Positions to specify
     * @return          reference to itself for chanining
     */
    virtual DataBuilder& addNextPositions(
        const PositionsPtr positions
    ) override;

    /**
     * @brief Sets payoffs values.
     *
     * @param params values of payoffs
     * @return       reference to itself for chanining
     */
    virtual DataBuilder& setParams(
        const NumbersPtr params
    ) override;

    /**
     * @brief Returns copy of itsef with shared content and frozen values of already set Positions.
     *
     * @return copy with frozem Positions and content common to parent
     */
    virtual DataBuilderPtr clone() const override;

    /**
     * @brief Returns new copy of this GameBuilder's type.
     *
     * @return GameBuilder
     */
    virtual GameBuilderPtr cloneBuilder() const override;

    /**
     * @brief Returns Same's DataBuilder.
     *
     * @return DataBuilder
     */
    virtual DataBuilderPtr dataBuilder() const override;

    /**
     * @brief ExtensiveGameBuilder Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_GAME_BUILDER_HPP__ */
