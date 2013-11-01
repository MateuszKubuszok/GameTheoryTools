#include "inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicDataAccessor : public DataAccessor {
// public:

StrategicDataAccessor::StrategicDataAccessor(
    StrategicDataPtr strategicData
) :
    data(strategicData)
    {}

DataPiecePtr StrategicDataAccessor::operator[](
    Index positionInStorage
) {
    return (*data)[positionInStorage];
}

DataPiecePtr StrategicDataAccessor::operator[](
    Positions& positions
) {
    return (*data)[positions];
}

DataPiecePtr StrategicDataAccessor::operator[](
    PositionsPtr positions
) {
    return (*data)[positions];
}

PlayersPtr StrategicDataAccessor::getPlayers() {
    return data->getPlayers();
}

DataPiecePtr StrategicDataAccessor::getValues(
    Index positionInStorage
) {
    return data->getValues(positionInStorage);
}

DataPiecePtr StrategicDataAccessor::getValues(
    PositionsPtr positions
) {
    return data->getValues(positions);
}

DataPiecePtr StrategicDataAccessor::getValues(
    Positions& positions
) {
    return data->getValues(positions);
}

Message StrategicDataAccessor::toString() {
    IdentifierPtr name      = createIdentifierPtr("Strategic Data Accessor");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// }; /* END class StrategicDataAccessor*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
