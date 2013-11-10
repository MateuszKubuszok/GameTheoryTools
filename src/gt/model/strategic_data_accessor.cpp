#include "inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class StrategicDataAccessor : public DataAccessor {
// public:

StrategicDataAccessor::StrategicDataAccessor(
    const StrategicDataPtr strategicData
) :
    data(strategicData)
    {}

const PlayersPtr StrategicDataAccessor::getPlayers() const {
    return data->getPlayers();
}

const DataPiecePtr StrategicDataAccessor::getValues(
    const Index positionInStorage
) const {
    return data->getValues(positionInStorage);
}

const DataPiecePtr StrategicDataAccessor::getValues(
    const PositionsPtr positions
) const {
    return data->getValues(positions);
}

const DataPiecePtr StrategicDataAccessor::getValues(
    const Positions& positions
) const {
    return data->getValues(positions);
}

Message StrategicDataAccessor::toString() const {
    IdentifierPtr name      = createIdentifierPtr("Strategic Data Accessor");
    MessagePtr    subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const Index positionInStorage
) const {
    return (*data)[positionInStorage];
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const Positions& positions
) const {
    return (*data)[positions];
}

const DataPiecePtr StrategicDataAccessor::operator[](
    const PositionsPtr positions
) const {
    return (*data)[positions];
}

// }; /* END class StrategicDataAccessor*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
