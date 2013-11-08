#ifndef __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__
#define __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Interface used to setup available Players.
 *
 * @author Mateusz Kubuszok
 *
 * @see Routine
 */
class SelectableStrategiesRoutine : virtual public Routine {
    /**
     * @brief Map containing available strategies.
     */
    typedef boost::container::map<Identifier, IdentifiersPtr> AvailableStrategies;

    /**
     * @brief Available Players.
     */
    PlayersPtr          players;

    /**
     * @brief Available strategies.
     */
    AvailableStrategies availableStrategies;

public:
    /**
     * @brief Initiates Routine with available Players.
     *
     * @param players Players definitions
     */
    explicit SelectableStrategiesRoutine(
        PlayersPtr players
    );

    /**
     * @brief Obtains list of currently available Players.
     *
     * @return available Players
     */
    PlayersPtr getAvailablePlayers();

    /**
     * @brief Returna available strategies for a Player.
     *
     * @param player Player for which strategies are obtaines
     * @return       currently available strategies
     */
    IdentifiersPtr getAvailableStrategiesForPlayer(
        Identifier& player
    );

    /**
     * @brief Sets available strategies for given Players.
     *
     * @param player     Player for which strategies are set up
     * @param strategies avialable strategies for Player
     */
    void setAvailableStrategiesForPlayer(
        Identifier&    player,
        IdentifiersPtr strategies
    );
}; /* END class SelectableStrategiesRoutine */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* END #ifndef __GT_ROUTINES_SELECTABLE_STRATEGIES_ROUTINE_HPP__ */
