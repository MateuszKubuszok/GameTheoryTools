#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class StrategicGameBuilder {
// public:

StrategicGameBuilder::StrategicGameBuilder() :
    strategicDataBuilder(new StrategicDataBuilder())
    {}

DataBuilder& StrategicGameBuilder::setPlayers(
    PlayersPtr players
) {
    strategicDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& StrategicGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    strategicDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& StrategicGameBuilder::setParams(
    NumbersPtr params
) {
    strategicDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr StrategicGameBuilder::clone() {
    return strategicDataBuilder->clone();
}

DataBuilderPtr StrategicGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(strategicDataBuilder);
}


GamePtr StrategicGameBuilder::build() {
    return GamePtr(
        new StrategicGame(
            strategicDataBuilder->getPlayers(),
            strategicDataBuilder->getData()
        )
    );
}

Message StrategicGameBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Strategic Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
