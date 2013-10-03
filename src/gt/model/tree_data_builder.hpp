#ifndef __GT_MODEL_TREE_DATA_BUILDER_HPP__
#define __GT_MODEL_TREE_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Builder used for creating TreeGame's Data.
 *
 * <p>Games in this form has all payoffs defined in nodes of a game tree.
 * Each level of that tree has assigned Player and for this level. As such
 * coordinates are mapping from turn into choosen strategy instead of
 * Player to strategy mapping.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see TreeData
 */
class TreeDataBuilder : public DataBuilder {
    TreeDataPtr data;

    PlayersPtr players;

    Positions  currentPositions;

    Index      depthValue;
    Identifier depthName;

public:
    /**
     * @brief Defalt constructor.
     */
    TreeDataBuilder();

    /**
     * @brief Returns set up Data.
     *
     * @return built Data
     */
    TreeDataPtr build();

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
     * @brief TreeDataBuilder Message.
     *
     * @return Message
     */
    virtual Message toString();
}; /* END class TreeDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_DATA_BUILDER_HPP__ */
