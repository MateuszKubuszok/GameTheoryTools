#ifndef __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating ExtensiveGame's Data.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree. Each node of that tree has assigned
 * Player. As such each SubCoordinates is mapped to strategy of the same Player.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 * @see ExtensiveGame
 */
class ExtensiveDataBuilder final : public DataBuilder {
    /**
     * @brief Actual data.
     */
    ExtensiveDataPtr data;

    /**
     * @brief Players.
     */
    PlayersPtr players;
    /**
     * @brief Current Positions that will be used to set params with setParams(NumbersPtr).
     */
    Positions  currentPositions;

    /**
     * @brief Current depth as numeric value.
     */
    Index      depthValue;
     /**
     * @brief Current depth as Identifier.
     */
    Identifier depthName;

public:
    /**
     * @brief Defalt constructor.
     */
    ExtensiveDataBuilder();

    /**
     * @brief Returns set up Data.
     *
     * @return built Data
     */
    ExtensiveDataPtr build() const;

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    const PlayersPtr getPlayers() const;

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
     * @brief ExtensiveDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveDataBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__ */
