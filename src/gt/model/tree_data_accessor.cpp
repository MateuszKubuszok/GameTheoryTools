#include "inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class TreeDataAccessor {
// public:

TreeDataAccessor::TreeDataAccessor(
    TreeDataPtr strategicData
) :
    data(strategicData)
    {}

DataPiecePtr TreeDataAccessor::operator[](
    Positions& positions
) {
    return (*data)[positions];
}

DataPiecePtr TreeDataAccessor::operator[](
    PositionsPtr positions
) {
    return (*data)[positions];
}

PlayersPtr TreeDataAccessor::getPlayers() {
    return data->getPlayers();
}

DataPiecePtr TreeDataAccessor::getValues(
    PositionsPtr positions
) {
    return data->getValues(positions);
}

DataPiecePtr TreeDataAccessor::getValues(
    Positions& positions
) {
    return data->getValues(positions);
}

Message TreeDataAccessor::toString() {
    IdentifierPtr name      = createIdentifierPtr("Tree Data Accessor");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
