#ifndef __GT_MODEL_TREE_GAME_BUILDER_HPP__
#define __GT_MODEL_TREE_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class TreeGameBuilder : public GameBuilder {
    TreeDataBuilderPtr strategicDataBuilder;

public:
    TreeGameBuilder();

    virtual DataBuilder& setPlayers(
        PlayersPtr players
    );

    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    );

    virtual DataBuilder& setParams(
        NumbersPtr params
    );

    virtual DataBuilderPtr clone();

    virtual DataBuilderPtr dataBuilder();

    virtual GamePtr build();

    virtual Message toString();
}; /* END class TreeGameBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_TREE_GAME_BUILDER_HPP__ */
