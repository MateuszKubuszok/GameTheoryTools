#ifndef __GT_MODEL_PLAIN_DATA_BUILDER_HPP__
#define __GT_MODEL_PLAIN_DATA_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainDataBuilder : public DataBuilder {
    typedef boost::container::map<Identifier, bool> KnownPositions;

    DataPtr data;

    PlayersPtr players;

    Positions      currentPositions;
    KnownPositions currentlyKnownPositions;

public:
    PlainDataBuilder();

    DataPtr getData();

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
}; /* END class PlainDataBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_BUILDER_HPP__ */
