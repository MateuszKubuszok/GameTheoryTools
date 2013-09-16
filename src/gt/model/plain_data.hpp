#ifndef __GT_MODEL_PLAIN_DATA_HPP__
#define __GT_MODEL_PLAIN_DATA_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainData : public Data {
    PlayersPtr players;

    IdentifierMap playersHelper;
    StrategyMap   strategiesHelper;
    IdentifierMap positionsHelper;

    boost::container::vector<NumbersPtr> paramsStorage;
    boost::container::vector<bool>       paramsStorageAllocation;
    
public:
    PlainData(
        PlayersPtr playersDefinitions
    );

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

private:
    Index calculatePlayer(
        Identifier& playerName
    );

    Index calculatePlayer(
        IdentifierPtr playerName
    );

    Index calculatePosition(
        Positions& positions
    );

    Index calculatePosition(
        PositionsPtr positions
    );

    bool checkPlayer(
        Identifier& playerName
    );

    bool checkPlayer(
        IdentifierPtr playerName
    );

    bool checkPositions(
        Positions& positions
    );

    bool checkPositions(
        PositionsPtr positions
    );

    ResultPtr contentMessage();
}; /* END class PlainData */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_DATA_HPP__ */
