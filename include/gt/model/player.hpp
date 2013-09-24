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
    typedef boost::container::map<Identifier, Index>  StrategyMap;

    /**
     * @breif Player's name.
     */
    const IdentifierPtr name;

    /**
     * @breif Player's strategies.
     */
    const IdentifiersPtr strategies;

    /**
     * @breif Mapps strategies to its ordinal.
     */
    StrategyMap strategyMapping;

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
    virtual Index getStrategiesNumber();

     /**
     * @brief Returns ordinal of a strategy with given identifier.
     *
     * @return                   ordinal of strategy with given identifier
     * @throws InvalidCoordinate thrown if Player has no such strategy
     */
    virtual Index getStrategyOrdinal(
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

/**
 * @brief Null Player for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
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
    
    virtual Index getStrategiesNumber() {
        return 0;
    }

    virtual Index getStrategyOrdinal(
        const Identifier& strategy
    ) {
        return 0;
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */
