#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGameBuilder : public GameBuilder {
// public:

ExtensiveGameBuilder::ExtensiveGameBuilder() :
    extensiveDataBuilder(new ExtensiveDataBuilder())
    {}

const PlayersPtr ExtensiveGameBuilder::getPlayers() const {
    return extensiveDataBuilder->getPlayers();
}

DataBuilder& ExtensiveGameBuilder::setPlayers(
    const PlayersPtr players
) {
    extensiveDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::addNextPositions(
    const PositionsPtr positions
) {
    extensiveDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& ExtensiveGameBuilder::setParams(
    const NumbersPtr params
) {
    extensiveDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr ExtensiveGameBuilder::clone() const {
    return extensiveDataBuilder->clone();
}

GameBuilderPtr ExtensiveGameBuilder::cloneBuilder() const {
    return GameBuilderPtr(new ExtensiveGameBuilder());
}

DataBuilderPtr ExtensiveGameBuilder::dataBuilder() const {
    return boost::dynamic_pointer_cast<DataBuilder>(extensiveDataBuilder);
}


GamePtr ExtensiveGameBuilder::build() const {
    return GamePtr(
        new ExtensiveGame(
            extensiveDataBuilder->getPlayers(),
            extensiveDataBuilder->build()
        )
    );
}

Message ExtensiveGameBuilder::toString() const {
    static const IdentifierPtr name    = createIdentifierPtr("Current Extensive Game");
    const MessagePtr           message = createMessagePtr(dataBuilder()->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, message).build()->getResult();
}

// }; /* END class ExtensiveGameBuilder */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
