#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainDataBuilder {
// public:

PlainDataBuilder::PlainDataBuilder() :
    data(NullFactory::getInstance().createData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    currentlyKnownPositions()
    {}

DataPtr PlainDataBuilder::getData() {
    return data;
}

PlayersPtr PlainDataBuilder::getPlayers() {
    return players;
}

DataBuilder& PlainDataBuilder::setPlayers(
    PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw IllegalInnerState("Cannot change already set Players");

    data    = DataPtr(new PlainData(newPlayers));
    players = newPlayers;
    
    return *this;
}

DataBuilder& PlainDataBuilder::addNextPositions(
    PositionsPtr positions
) {
    BOOST_FOREACH(Positions::value_type& position, (*positions)) {
        if (currentlyKnownPositions.count(position.first) && currentlyKnownPositions[position.first])
            throw InvalidCoordinate("Some of Coordinates are already set");
        if (!(*players)[position.first]->hasStrategy(position.second))
            throw InvalidCoordinate("Coordinate value not allowed");
    }

    BOOST_FOREACH(Positions::value_type& position, (*positions)) {
        currentPositions.insert( position );
        currentlyKnownPositions.insert( KnownPositions::value_type(position.first, true) );
    }

    return *this;
}

DataBuilder& PlainDataBuilder::setParams(
    NumbersPtr params
) {
    BOOST_FOREACH(Identifier player, (*players) | boost::adaptors::map_keys)
        if (!currentlyKnownPositions.count(player) || !currentlyKnownPositions[player])
            throw IllegalInnerState("Cannot set parameters when not all coordinates are known");

    data->setValues(currentPositions, params);

    return *this;
}

DataBuilderPtr PlainDataBuilder::clone() {
    return DataBuilderPtr(new PlainDataBuilder(*this));
}

Message PlainDataBuilder::toString() {
    // TODO
    return Message();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
