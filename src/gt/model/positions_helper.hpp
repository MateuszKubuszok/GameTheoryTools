#ifndef __GT_MODEL_POSITIONS_HELPER_HPP__
#define __GT_MODEL_POSITIONS_HELPER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Helper used for calculating Positions into Index and the other way round.
 *
 * @author Mateusz Kubuszok
 */
class PositionsHelper : public Root {
    /**
     * @brief Players.
     */
    const PlayersPtr players;

    /**
     * @brief Map Players' Identifeirs to a number to quickly find Player's ordinal.
     */
    IdentifierMap playersHelper;
     /**
     * @brief Maps Players' Strategies to a number to match: index = sum playerNumber * strategyNumber.
     */
    StrategyMap   strategiesHelper;
    /**
     * @brief Maps Players' Identifeirs to a number to match: index = sum playerNumber * strategyNumber.
     */
    IdentifierMap positionsHelper;

    /**
     * @brief Upper bound of storage's positions.
     */
    Index upperBound;

public:
    /**
     * @brief Constructor initiated with Players definitions.
     *
     * @param players Players definitions
     */
    explicit PositionsHelper(
        const PlayersPtr players
    );

    /**
     * @brief Returns Players definitions.
     *
     * @return Players definitions
     */
    const PlayersPtr getPlayers() const;

    /**
     * @brief Returns upper bound of Indexes.
     *
     * @return upper bound of Indexes
     */
    Index getUpperBound() const;

    /**
     * @brief Calculates Player's position in Numbers collection.
     *
     * @param playerName name of required Player
     * @return           Index of Player's Number
     */
    Index calculatePlayer(
        const Identifier& playerName
    ) const;

    /**
     * @brief Calculates Player's position in Numbers collection.
     *
     * @param playerName name of required Player
     * @return           Index of Player's Number
     */
    Index calculatePlayer(
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Calculates Player's name by its position in Numbers collection.
     *
     * @param playerPosition Index of Player's Number
     * @return               name of required Player
     */
    const IdentifierPtr retrievePlayer(
        const Index playerPosition
    ) const;

    /**
     * @brief Calculates Numbers's position in params storage.
     *
     * @param positions Positions as coordinates
     * @return          Index in params storage
     */
    Index calculatePosition(
        const Positions& positions
    ) const;

    /**
     * @brief Calculates Numbers's position in params storage.
     *
     * @param positions Positions as coordinates
     * @return          Index in params storage
     */
    Index calculatePosition(
        const PositionsPtr positions
    ) const;

    /**
     * @brief Calculates Positions by its Index in params storage.
     *
     * @param positionInStorage Index of Positions
     * @return                  Positions as coordinates
     */
    const PositionsPtr retrievePositions(
        const Index positionInStorage
    ) const;

    /**
     * @brief Checks whether given Player exists.
     *
     * @param playerName name of checked Player
     * @return           true if Player exists
     */
    bool checkPlayer(
        const Identifier& playerName
    ) const;

    /**
     * @brief Checks whether given Player exists.
     *
     * @param playerName name of checked Player
     * @return           true if Player exists
     */
    bool checkPlayer(
        const IdentifierPtr playerName
    ) const;

    /**
     * @brief Checks whether given Position is vaid.
     *
     * @param positions checked positions
     * @return          true if Position is valid
     */
    bool checkPositions(
        const Positions& positions
    ) const;

    /**
     * @brief Checks whether given Position is vaid.
     *
     * @param positions checked positions
     * @return          true if Position is valid
     */
    bool checkPositions(
        const PositionsPtr positions
    ) const;

    /**
     * @brief Retuns PositionsHelper's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class PositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_POSITIONS_HELPER_HPP__ */
