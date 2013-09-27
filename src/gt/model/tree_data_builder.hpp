#ifndef __GT_MODEL_TREE_DATA_BUILDER_HPP__
#define __GT_MODEL_TREE_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeDataBuilder : public DataBuilder {
    TreeDataPtr data;

    PlayersPtr players;

    Positions  currentPositions;

    Index      depthValue;
    Identifier depthName;

public:
    TreeDataBuilder();

    TreeDataPtr getData();

    PlayersPtr getPlayers();

    virtual DataBuilder& setPlayers(
        PlayersPtr newPlayers
    );

    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    );

    virtual DataBuilder& setParams(
        NumbersPtr params
    );

    virtual DataBuilderPtr clone();

    virtual Message toString();
}; /* END class TreeDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_DATA_BUILDER_HPP__ */
