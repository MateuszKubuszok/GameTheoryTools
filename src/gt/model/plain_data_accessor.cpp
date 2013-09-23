#include "inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class PlainDataAccessor {
// public:

PlainDataAccessor::PlainDataAccessor(
    DataPtr plainData
) :
    data(plainData)
    {}

DataPiecePtr PlainDataAccessor::operator[](
    Index positionInStorage
) {
    return (*data)[positionInStorage];
}

DataPiecePtr PlainDataAccessor::operator[](
    Positions& positions
) {
    return (*data)[positions];
}

DataPiecePtr PlainDataAccessor::operator[](
    PositionsPtr positions
) {
    return (*data)[positions];
}

PlayersPtr PlainDataAccessor::getPlayers() {
    return data->getPlayers();
}

DataPiecePtr PlainDataAccessor::getValues(
    Index positionInStorage
) {
    return data->getValues(positionInStorage);
}

DataPiecePtr PlainDataAccessor::getValues(
    PositionsPtr positions
) {
    return data->getValues(positions);
}

DataPiecePtr PlainDataAccessor::getValues(
    Positions& positions
) {
    return data->getValues(positions);
}

Message PlainDataAccessor::toString() {
    IdentifierPtr name      = createIdentifierPtr("Plain Data Accessor");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
