#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicGameBuilder : public GameBuilder {
// public:

StrategicGameBuilder::StrategicGameBuilder() :
    strategicDataBuilder(new StrategicDataBuilder())
    {}

const PlayersPtr StrategicGameBuilder::getPlayers() const {
    return strategicDataBuilder->getPlayers();
}

DataBuilder& StrategicGameBuilder::setPlayers(
    const PlayersPtr players
) {
    strategicDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& StrategicGameBuilder::addNextPositions(
    const PositionsPtr positions
) {
    strategicDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& StrategicGameBuilder::setParams(
    const NumbersPtr params
) {
    strategicDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr StrategicGameBuilder::clone() const {
    return strategicDataBuilder->clone();
}

GameBuilderPtr StrategicGameBuilder::cloneBuilder() const {
    return GameBuilderPtr(new StrategicGameBuilder());
}

DataBuilderPtr StrategicGameBuilder::dataBuilder() const {
    return boost::dynamic_pointer_cast<DataBuilder>(strategicDataBuilder);
}


GamePtr StrategicGameBuilder::build() const {
    return GamePtr(
        new StrategicGame(
            strategicDataBuilder->getPlayers(),
            strategicDataBuilder->build()
        )
    );
}

Message StrategicGameBuilder::toString() const {
    IdentifierPtr name    = createIdentifierPtr("Current Strategic Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class StrategicGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
