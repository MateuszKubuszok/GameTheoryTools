#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class TreeGameBuilder {
// public:

TreeGameBuilder::TreeGameBuilder() :
    strategicDataBuilder(new TreeDataBuilder())
    {}

DataBuilder& TreeGameBuilder::setPlayers(
    PlayersPtr players
) {
    strategicDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& TreeGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    strategicDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& TreeGameBuilder::setParams(
    NumbersPtr params
) {
    strategicDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr TreeGameBuilder::clone() {
    return strategicDataBuilder->clone();
}

DataBuilderPtr TreeGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(strategicDataBuilder);
}


GamePtr TreeGameBuilder::build() {
    return GamePtr(
        new TreeGame(
            strategicDataBuilder->getPlayers(),
            strategicDataBuilder->getData()
        )
    );
}

Message TreeGameBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Tree Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
