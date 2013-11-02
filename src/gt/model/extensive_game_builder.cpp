#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGameBuilder : public GameBuilder {
// public:

ExtensiveGameBuilder::ExtensiveGameBuilder() :
    extensiveDataBuilder(new ExtensiveDataBuilder())
    {}

PlayersPtr ExtensiveGameBuilder::getPlayers() {
    return extensiveDataBuilder->getPlayers();
}

DataBuilder& ExtensiveGameBuilder::setPlayers(
    PlayersPtr players
) {
    extensiveDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    extensiveDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::setParams(
    NumbersPtr params
) {
    extensiveDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr ExtensiveGameBuilder::clone() {
    return extensiveDataBuilder->clone();
}

DataBuilderPtr ExtensiveGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(extensiveDataBuilder);
}


GamePtr ExtensiveGameBuilder::build() {
    return GamePtr(
        new ExtensiveGame(
            extensiveDataBuilder->getPlayers(),
            extensiveDataBuilder->build()
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
