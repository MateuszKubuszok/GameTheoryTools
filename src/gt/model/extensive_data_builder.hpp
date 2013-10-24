#ifndef __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating ExtensiveGame's Data.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree.
 * Each level of that tree has assigned Player and for this level. As such
 * coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 */
class ExtensiveDataBuilder : public DataBuilder {
    ExtensiveDataPtr data;

    PlayersPtr players;

    Positions  currentPositions;

    Index      depthValue;
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
    ExtensiveDataPtr build();

    /**
     * @brief Returns Players' definitions.
     *
     * @return Players' definitions
     */
    PlayersPtr getPlayers();

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
     * @brief ExtensiveDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class ExtensiveDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_BUILDER_HPP__ */
