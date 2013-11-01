#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGameBuilder : public GameBuilder {
// public:

ExtensiveGameBuilder::ExtensiveGameBuilder() :
    treeDataBuilder(new ExtensiveDataBuilder())
    {}

PlayersPtr ExtensiveGameBuilder::getPlayers() {
    return treeDataBuilder->getPlayers();
}

DataBuilder& ExtensiveGameBuilder::setPlayers(
    PlayersPtr players
) {
    treeDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    treeDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::setParams(
    NumbersPtr params
) {
    treeDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr ExtensiveGameBuilder::clone() {
    return treeDataBuilder->clone();
}

DataBuilderPtr ExtensiveGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(treeDataBuilder);
}


GamePtr ExtensiveGameBuilder::build() {
    return GamePtr(
        new ExtensiveGame(
            treeDataBuilder->getPlayers(),
            treeDataBuilder->build()
        )
    );
}

Message ExtensiveGameBuilder::toString() {
    IdentifierPtr name    = createIdentifierPtr("Current Extensive Game");
    MessagePtr    message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class ExtensiveGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
