#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class TreeGameBuilder {
// public:

TreeGameBuilder::TreeGameBuilder() :
    treeDataBuilder(new TreeDataBuilder())
    {}

PlayersPtr TreeGameBuilder::getPlayers() {
    return treeDataBuilder->getPlayers();
}

DataBuilder& TreeGameBuilder::setPlayers(
    PlayersPtr players
) {
    treeDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& TreeGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    treeDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& TreeGameBuilder::setParams(
    NumbersPtr params
) {
    treeDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr TreeGameBuilder::clone() {
    return treeDataBuilder->clone();
}

DataBuilderPtr TreeGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(treeDataBuilder);
}


GamePtr TreeGameBuilder::build() {
    return GamePtr(
        new TreeGame(
            treeDataBuilder->getPlayers(),
            treeDataBuilder->build()
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
