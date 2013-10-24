#include "inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class ExtensiveDataAccessor {
// public:

ExtensiveDataAccessor::ExtensiveDataAccessor(
    ExtensiveDataPtr strategicData
) :
    data(strategicData)
    {}

DataPiecePtr ExtensiveDataAccessor::operator[](
    Positions& positions
) {
    return (*data)[positions];
}

DataPiecePtr ExtensiveDataAccessor::operator[](
    PositionsPtr positions
) {
    return (*data)[positions];
}

PlayersPtr ExtensiveDataAccessor::getPlayers() {
    return data->getPlayers();
}

DataPiecePtr ExtensiveDataAccessor::getValues(
    PositionsPtr positions
) {
    return data->getValues(positions);
}

DataPiecePtr ExtensiveDataAccessor::getValues(
    Positions& positions
) {
    return data->getValues(positions);
}

Message ExtensiveDataAccessor::toString() {
    IdentifierPtr name      = createIdentifierPtr("Extensive Data Accessor");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
