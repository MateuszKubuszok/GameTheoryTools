#ifndef __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__
#define __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__

namespace GT {
namespace Routines {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains path to a payoff (with payoff).
 *
 * @author Mateusz Kubuszok
 */
class ExtensivePureStrategyPath : public Root {
    /**
     * @brief Players definitions.
     */
    const PlayersPtr players;

    /**
     * @brief Payoff.
     */
    Model::DataPiecePtr payoffs;

    /**
     * @brief Contains choices for given Players.
     */
    boost::container::map<Identifier, Positions> playersChoices;

public:
    /**
     * @brief Contains choices for given Players.
     */
    typedef boost::container::map<Identifier, Positions> PlayersChoices;

    /**
     * @brief Initiates path with Players definitions.
     *
     * @param players Players definitions
     */
    ExtensivePureStrategyPath(
        const PlayersPtr players
    );

    /**
     * @brief Adds older choice to the beginning of list.
     *
     * @param informationSet      information set's name
     * @param player              Player's name
     * @param strategy            chosen strategy
     * @return                    reference for itself for chaining
     * @throw InvalidPlayerChoice thrown when Player's name or chosen strategy is invalid
     */
    ExtensivePureStrategyPath& addOlderChoice(
        const Identifier& informationSet,
        const Identifier& player,
        const Identifier& strategy
    );

    /**
     * @brief Returns all players choices till now.
     *
     * @return Players' choices
     */
    const PlayersChoices& getPlayersChoices() const;

    /**
     * @brief Returns payoffs for path.
     *
     * @return payoff
     */
    const Model::DataPiecePtr getPayoff() const;

    /**
     * @brief Sets payoff.
     *
     * @param payoffs new payoffs
     * @return        reference to itself for chaining
     */
    ExtensivePureStrategyPath& setPayoff(
        Model::DataPiecePtr payoffs
    );

    /**
     * @brief Returns ExtensivePureStrategyMessage message.
     *
     * @return Message
     */
    virtual Message toString() const;
}; /* END class ExtensivePureStrategyPath */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Routines */
} /* END namespace GT */

#endif /* #ifndef __GT_ROUTINES_EXTENSIVE_PURE_STRATEGY_PATH_HPP__ */
