#ifndef __GT_MODEL_STRATEGIC_DATA_HPP__
#define __GT_MODEL_STRATEGIC_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class StrategicData : public Data {
    PositionsHelper positionsHelper;

    boost::container::vector<NumbersPtr> payoffStorage;
    boost::container::vector<bool>       payoffStorageAllocation;
    
public:
    explicit StrategicData(
        PlayersPtr playersDefinitions
    );

    virtual PlayersPtr getPlayers();

    virtual DataPiecePtr getValues(
        Index positionInStorage
    );

    virtual DataPiecePtr getValues(
        Positions& positions
    );

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    );

    virtual Data& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
    );

    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    );

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    );

    virtual DataPiecePtr operator[](
        Index positionInStorage
    );

    virtual DataPiecePtr operator[](
        Positions& positions
    );

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    );

    virtual Message toString();
}; /* END class StrategicData */

////////////////////////////////////////////////////////////////////////////////

class NullStrategicData : public StrategicData {
public:
    NullStrategicData() :
        StrategicData(NullFactory::getInstance().createPlayers())
        {}

    virtual PlayersPtr getPlayers() {
        return NullFactory::getInstance().createPlayers();
    }

    virtual DataPiecePtr getValues(
        Index positionInStorage
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        Positions& positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual Data& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
    ) {
        return *this;
    }

    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    ) {
        return *this;
    }

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        return *this;
    }

    virtual DataPiecePtr operator[](
        Index positionInStorage
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        Positions& positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    ) {
        return NullFactory::getInstance().createDataPiece();
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullStrategicData");
    }
}; /* END class NullStrategicData */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_STRATEGIC_DATA_HPP__ */
