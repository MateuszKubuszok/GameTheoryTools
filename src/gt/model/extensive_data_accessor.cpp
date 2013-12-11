#include "inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveDataAccessor : public DataAccessor {
// public:

ExtensiveDataAccessor::ExtensiveDataAccessor(
    const ExtensiveDataPtr strategicData
) :
    data(strategicData)
    {}

const ExtensiveDataNodePtr ExtensiveDataAccessor::getRoot() const {
    return data->getRoot();
}

const PlayersPtr ExtensiveDataAccessor::getPlayers() const {
    return data->getPlayers();
}

const DataPiecePtr ExtensiveDataAccessor::getValues(
    const PositionsPtr positions
) const {
    return data->getValues(positions);
}

const DataPiecePtr ExtensiveDataAccessor::getValues(
    const Positions& positions
) const {
    return data->getValues(positions);
}

Message ExtensiveDataAccessor::toString() const {
    static const IdentifierPtr name      = createIdentifierPtr("Extensive Data Accessor");
    const MessagePtr           subresult = createMessagePtr(data->toString());
    return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

const DataPiecePtr ExtensiveDataAccessor::operator[](
    const Positions& positions
) const {
    return (*data)[positions];
}

const DataPiecePtr ExtensiveDataAccessor::operator[](
    const PositionsPtr positions
) const {
    return (*data)[positions];
}

// }; /* END class ExtensiveDataAccessor */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
