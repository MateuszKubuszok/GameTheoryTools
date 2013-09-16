#ifndef __GT_MODEL_PLAIN_GAME_BUILDER_HPP__
#define __GT_MODEL_PLAIN_GAME_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainGameBuilder : public GameBuilder {
public:
    PlainGameBuilder();

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

    virtual GamePtr build() = 0;

    virtual Message toString() = 0;

protected:
    PlainDataBuilderPtr plainDataBuilder;
}; /* END class PlainGameBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_GAME_BUILDER_HPP__ */
