#ifndef __GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP__
#define __GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ExtensiveGamePositionsHelper final : public Root {
    /**
     * @brief Root of Data tree.
     */
    const ExtensiveDataNodePtr root;

    /**
     * @brief PlayersInformationSets.
     */
    boost::container::map<
        Identifier,
        boost::bimaps::bimap<Identifier, ExtensiveDataNode*>
    > playersInformationSets;

public:
    /**
     * @brief Contains single element information set for one Player.
     */
    typedef boost::bimaps::bimap<Identifier, ExtensiveDataNode*>      PlayerInformationSets;

    /**
     * @brief Contains information sets' collections for each Player.
     */
    typedef boost::container::map<Identifier, PlayerInformationSets> PlayersInformationSets;

    /**
     * @brief Inititiates helper with ExtensiveGame tree's root.
     *
     * @param extensiveGameRoot root of Game's tree
     */
    explicit ExtensiveGamePositionsHelper(
        const ExtensiveDataNodePtr extensiveGameRoot
    );

    /**
     * @brief Returns list of available Players.
     *
     * @return list of available Players
     */
    IdentifiersPtr getPossiblePlayers() const;

    /**
     * @brief Returns whether Player is available.
     *
     * @param player Player's name
     * @return       true if Player is available
     */
    bool isPlayerPossible(
        const Identifier& player
    ) const;

    /**
     * @brief Returns list of available information sets.
     *
     * @param player            Player's name
     * @return                  list of available information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player available
     */
    IdentifiersPtr getPossibleInformationSetsForPlayer(
        const Identifier& player
    ) const;

    /**
     * @brief Returns available information sets.
     *
     * @param player            Player's name
     * @return                  information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player available
     */
    const PlayerInformationSets& getInformationSetsForPlayer(
        const Identifier& player
    ) const;

    /**
     * @brief Returns list of available information sets.
     *
     * @param player            Player's name
     * @param setNam            information set's name
     * @return                  list of available information sets for a Player
     * @throw InvalidCoordinate thrown when no such Player or information set available
     */
    const ExtensiveDataNode& getInformationSetForPlayer(
        const Identifier& player,
        const Identifier& setName
    ) const;

    /**
     * @brief Retuns ExtensiveGamePositionsHelper's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;
}; /* END class ExtensiveGamePositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_GAME_POSITIONS_HELPER_HPP__ */
