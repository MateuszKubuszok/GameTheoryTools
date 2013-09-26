#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class StrategicDataBuilder {
// public:

StrategicDataBuilder::StrategicDataBuilder() :
    data(new NullStrategicData()),
    players(NullFactory::getInstance().createPlayers()),
    currentPositions(),
    currentlyKnownPositions()
    {}

StrategicDataPtr StrategicDataBuilder::getData() {
    return data;
}

PlayersPtr StrategicDataBuilder::getPlayers() {
    return players;
}

DataBuilder& StrategicDataBuilder::setPlayers(
    PlayersPtr newPlayers
) {
    if (data->isNotNull())
        throw ExceptionFactory::getInstance()
                .playersAlreadySet();

    data    = StrategicDataPtr(new StrategicData(newPlayers));
    players = newPlayers;
    
    return *this;
}

DataBuilder& StrategicDataBuilder::addNextPositions(
    PositionsPtr positions
) {
    BOOST_FOREACH(Positions::value_type& position, (*positions)) {
        if (currentlyKnownPositions.count(position.first) && currentlyKnownPositions[position.first])
            throw ExceptionFactory::getInstance().coordinatesAlreadySet(*positions);
        if (!(*players)[position.first]->hasStrategy(position.second))
            throw ExceptionFactory::getInstance().invalidCoordinateFormat(*positions);
    }

    BOOST_FOREACH(Positions::value_type& position, (*positions)) {
        currentPositions.insert( position );
        currentlyKnownPositions.insert( KnownPositions::value_type(position.first, true) );
    }

    return *this;
}

DataBuilder& StrategicDataBuilder::setParams(
    NumbersPtr params
) {
    BOOST_FOREACH(Identifier player, (*players) | boost::adaptors::map_keys)
        if (!currentlyKnownPositions.count(player) || !currentlyKnownPositions[player])
            throw ExceptionFactory::getInstance().incompleteCoordinates();

    data->setValues(currentPositions, params);

    return *this;
}

DataBuilderPtr StrategicDataBuilder::clone() {
    return DataBuilderPtr(new StrategicDataBuilder(*this));
}

Message StrategicDataBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Data");
    MessagePtr    message = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
