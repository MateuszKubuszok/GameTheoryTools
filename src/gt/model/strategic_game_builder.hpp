#ifndef __GT_MODEL_STRATEGIC_GAME_BUILDER_HPP__
#define __GT_MODEL_STRATEGIC_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating StrategicGame.
 *
 * <p>Games in this form should have all coordinates filled with payoffs. Since
 * all Players and their strategies are known beforehand, positions can also
 * be hashed to Indexes with PositionsHelper.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see StrategicGame
 * @see StrategicDataBuilder
 */
class StrategicGameBuilder : public GameBuilder {
    StrategicDataBuilderPtr strategicDataBuilder;

public:
    /**
     * @brief Default constructor.
     */
	StrategicGameBuilder();

    /**
     * @brief Returns set up Game.
     *
     * @return built Game
     */
    virtual GamePtr build();

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    virtual PlayersPtr getPlayers();

    /**
     * @brief Sets Players' definitions.
     *
     * @param newPlayers Players' definitions
     * @return           reference to itself for chanining
     */
    virtual DataBuilder& setPlayers(
        PlayersPtr newPlayers
    );

    /**
     * @brief Specifies next Positions.
     *
     * @param positions next Positions to specify
     * @return          reference to itself for chanining
     */
    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    );

    /**
     * @brief Sets payoffs values.
     *
     * @param params values of payoffs 
     * @return       reference to itself for chanining
     */
    virtual DataBuilder& setParams(
        NumbersPtr params
    );

    /**
     * @brief Returns copy of itsef with shared content and frozen values of already set Positions. 
     *
     * @return copy with frozem Positions and content common to parent
     */
    virtual DataBuilderPtr clone();

    /**
     * @brief Returns Same's DataBuilder. 
     *
     * @return DataBuilder
     */
    virtual DataBuilderPtr dataBuilder();

    /**
     * @brief StrategicGameBuilder Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class StrategicGameBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_GAME_BUILDER_HPP__ */
