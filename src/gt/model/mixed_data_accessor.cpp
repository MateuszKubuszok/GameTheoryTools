#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

// class MixedDataAccessor {
// public:
MixedDataAccessor::MixedDataAccessor(
    DataPtr    data
) :
	pureData(data),
	expectedData(new PlainData(data->getPlayers())),
	positionsHelper(data->getPlayers())
	{}

DataPiecePtr MixedDataAccessor::operator[](
    Index positionInStorage
) {
	return getValues(positionInStorage);
}

DataPiecePtr MixedDataAccessor::operator[](
    Positions& positions
) {
	return getValues(positions);
}

DataPiecePtr MixedDataAccessor::operator[](
    PositionsPtr positions
) {
	return getValues(positions);
}

PlayersPtr MixedDataAccessor::getPlayers() {
	return positionsHelper.getPlayers();
}

DataPiecePtr MixedDataAccessor::getValues(
    Index positionInStorage
) {
	// TODO
	return NullFactory::getInstance().createDataPiece();
}

DataPiecePtr MixedDataAccessor::getValues(
    PositionsPtr positions
) {
	// TODO
	return NullFactory::getInstance().createDataPiece();
}

DataPiecePtr MixedDataAccessor::getValues(
    Positions& positions
) {
	// TODO
	return NullFactory::getInstance().createDataPiece();
}

Message MixedDataAccessor::toString() {
	IdentifierPtr name      = createIdentifierPtr("Mixed Data Accessor");
	MessagePtr    subresult = createMessagePtr(pureData->toString());
	return ResultFactory::getInstance().buildResult()->addResult(name, subresult).build()->getResult();
}

// private:

NumberPtr MixedDataAccessor::calculateExpectedValue(
    Index positionInStorage
) {
	// TODO
	return NullFactory::getInstance().createNumber();
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
