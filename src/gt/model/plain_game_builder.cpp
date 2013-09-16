#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainGameBuilder {
// public:

PlainGameBuilder::PlainGameBuilder() :
    plainDataBuilder(new PlainDataBuilder())
    {}

DataBuilder& PlainGameBuilder::setPlayers(
    PlayersPtr players
) {
    plainDataBuilder->setPlayers(players);
    return *this;
}

DataBuilder& PlainGameBuilder::addNextPositions(
    PositionsPtr positions
) {
    plainDataBuilder->addNextPositions(positions);
    return *this;
}

DataBuilder& PlainGameBuilder::setParams(
    NumbersPtr params
) {
    plainDataBuilder->setParams(params);
    return *this;
}

DataBuilderPtr PlainGameBuilder::clone() {
    return plainDataBuilder->clone();
}

DataBuilderPtr PlainGameBuilder::dataBuilder() {
    return boost::dynamic_pointer_cast<DataBuilder>(plainDataBuilder);
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
