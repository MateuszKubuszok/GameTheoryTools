#ifndef __GT_MODEL_PLAYER_HPP__
#define __GT_MODEL_PLAYER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Player.
 *
 * @author Mateusz Kubuszok
 */
class Player : public virtual Root {
    /**
     * @breif Player's name.
     */
    const IdentifierPtr name;

    /**
     * @breif Player's strategies.
     */
    const IdentifiersPtr strategies;

    /**
     * @breif Mapps strategies to its ordnial.
     */
    const boost::container::map<std::string, int> strategyMapping;

public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the player
     * @param playerStrategy declared strategies
     */
    Player(
        const IdentifierPtr playerName,
        const Identifiers   playerStrategies
    );

    /**
     * @brief Returns name ot the Player.
     *
     * @return Player's name
     */
    virtual Identifier getName();

    /**
     * @brief Returns Player's strategies.
     *
     * @return Player's strategies
     */
    virtual Identifiers getStrategies();

    /**
     * @brief Returns number of strategies.
     *
     * @return number of strategies
     */    
    virtual int getStrategiesNumber();

     /**
     * @brief Returns ordinal of a strategy with given identifier.
     *
     * @return ordinal of strategy with given identifier
     */
    virtual int getStrategyOrdinal(
        const Identifier& strategy
    );

    /**
     * @brief Returns Message with Player's name and strategies.
     *
     * @return Player's name and strategies
     */
    virtual Message toString();
}; /* END class Player */

////////////////////////////////////////////////////////////////////////////////

class NullPlayer : public virtual Player {
public:
    NullPlayer() :
        Player(
            NullFactory::getInstance().createIdentifier(),
            Identifiers()
        )
        {}

    virtual Identifier getName() {
        return Identifier("NullPlayer");
    }

    virtual Identifiers getStrategies() {
        return Identifiers();
    }
    
    virtual int getStrategiesNumber() {
        return 0;
    }

    virtual int getStrategyOrdinal(
        const Identifier& strategy
    ) {
        return -1;
    }

    virtual Message toString() {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */
