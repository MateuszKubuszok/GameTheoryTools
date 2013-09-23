#ifndef __GT_MODEL_POSITIONS_HELPER_HPP__
#define __GT_MODEL_POSITIONS_HELPER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PositionsHelper : public Root {
	PlayersPtr players;

	IdentifierMap playersHelper;
    StrategyMap   strategiesHelper;
    IdentifierMap positionsHelper;

    Index upperBound;

public:
	PositionsHelper(
		PlayersPtr players
	);

    PlayersPtr getPlayers();

    Index getUpperBound();

    Index calculatePlayer(
        Identifier& playerName
    );

    Index calculatePlayer(
        IdentifierPtr playerName
    );

    IdentifierPtr retrievePlayer(
        Index playerPosition
    );

    Index calculatePosition(
        Positions& positions
    );

    Index calculatePosition(
        PositionsPtr positions
    );

    PositionsPtr retrievePositions(
        Index positionInStorage
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

    Message toString();
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_POSITIONS_HELPER_HPP__ */
