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
    boost::container::map<Identifier, int> strategyMapping;

public:
    /**
     * @brief Constructor of the Player.
     *
     * @param playerName     name of the player
     * @param playerStrategy declared strategies
     */
    Player(
        const IdentifierPtr  playerName,
        const IdentifiersPtr playerStrategies
    );

    /**
     * @brief Returns name ot the Player.
     *
     * @return Player's name
     */
    virtual IdentifierPtr getName();

    /**
     * @brief Returns Player's strategies.
     *
     * @return Player's strategies
     */
    virtual IdentifiersPtr getStrategies();

    /**
     * @brief Returns number of strategies.
     *
     * @return number of strategies
     */    
    virtual int getStrategiesNumber();

     /**
     * @brief Returns ordinal of a strategy with given identifier.
     *
     * @return                       ordinal of strategy with given identifier
     * @throws std::invalid_argument thrown if Player has no such strategy
     */
    virtual int getStrategyOrdinal(
        Identifier& strategy
    );

     /**
     * @brief Returns whether strategy with such name exists.
     *
     * @return true if Player has such strategy
     */
    virtual bool hasStrategy(
        Identifier& strategy
    );

    /**
     * @brief Returns Message with Player's name and strategies.
     *
     * @return Player's name and strategies
     */
    virtual Message toString();
}; /* END class Player */

////////////////////////////////////////////////////////////////////////////////

class NullPlayer : public Player {
public:
    NullPlayer() :
        Player(
            NullFactory::getInstance().createIdentifier(),
            NullFactory::getInstance().createIdentifiers()
        )
        {}

    virtual IdentifierPtr getName() {
        return NullFactory::getInstance().createIdentifier();
    }

    virtual IdentifiersPtr getStrategies() {
        return NullFactory::getInstance().createIdentifiers();
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
