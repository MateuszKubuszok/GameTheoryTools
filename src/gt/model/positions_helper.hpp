#ifndef __GT_MODEL_POSITIONS_HELPER_HPP__
#define __GT_MODEL_POSITIONS_HELPER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used for calculating Positions into Index and the other way round. 
 *
 * @author Mateusz Kubuszok
 */
class PositionsHelper : public Root {
	PlayersPtr players;

	IdentifierMap playersHelper;
    StrategyMap   strategiesHelper;
    IdentifierMap positionsHelper;

    Index upperBound;

public:
    /**
     * @brief Constructor initiated with Players definitions.
     *
     * @param players Players definitions
     */
	explicit PositionsHelper(
		PlayersPtr players
	);

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    PlayersPtr getPlayers();

    /**
     * @brief Returns upper bound of Indexes.
     *
     * @return upper bound of Indexes 
     */
    Index getUpperBound();

    /**
     * @brief Calculates Player's position in Numbers collection.
     *
     * @param playerName name of required Player
     * @return           Index of Player's Number
     */
    Index calculatePlayer(
        Identifier& playerName
    );

    /**
     * @brief Calculates Player's position in Numbers collection.
     *
     * @param playerName name of required Player
     * @return           Index of Player's Number
     */
    Index calculatePlayer(
        IdentifierPtr playerName
    );

    /**
     * @brief Calculates Player's name by its position in Numbers collection.
     *
     * @param playerPosition Index of Player's Number
     * @return               name of required Player
     */
    IdentifierPtr retrievePlayer(
        Index playerPosition
    );

    /**
     * @brief Calculates Numbers's position in params storage.
     *
     * @param positions Positions as coordinates
     * @return          Index in params storage
     */
    Index calculatePosition(
        Positions& positions
    );

    /**
     * @brief Calculates Numbers's position in params storage.
     *
     * @param positions Positions as coordinates
     * @return          Index in params storage
     */
    Index calculatePosition(
        PositionsPtr positions
    );

    /**
     * @brief Calculates Positions by its Index in params storage.
     *
     * @param positionInStorage Index of Positions
     * @return                  Positions as coordinates
     */
    PositionsPtr retrievePositions(
        Index positionInStorage
    );

    /**
     * @brief Checks whether given Player exists.
     *
     * @param playerName name of checked Player
     * @return           true if Player exists
     */
    bool checkPlayer(
        Identifier& playerName
    );

    /**
     * @brief Checks whether given Player exists.
     *
     * @param playerName name of checked Player
     * @return           true if Player exists
     */
    bool checkPlayer(
        IdentifierPtr playerName
    );

    /**
     * @brief Checks whether given Position is vaid.
     *
     * @param positions checked positions
     * @return          true if Position is valid
     */
    bool checkPositions(
        Positions& positions
    );

    /**
     * @brief Checks whether given Position is vaid.
     *
     * @param positions checked positions
     * @return          true if Position is valid
     */
    bool checkPositions(
        PositionsPtr positions
    );

    /**
     * @brief Retuns PositionsHelper's Message.
     *
     * @return Message
     */
    Message toString();
};

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_POSITIONS_HELPER_HPP__ */
