#ifndef __GT_MODEL_PLAYER_HPP__
#define __GT_MODEL_PLAYER_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Defines Player.
 *
 * <p>Each Player is defined by its name and used strategies. They will later be used during Game definition
 * and calculation of equilibria.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Game
 * @see GameBuilder
 */
class Player : public virtual Root {
    /**
     * @brief Type storing strategy to ordinal mapping.
     */
    typedef boost::container::map<Identifier, Index>  StrategyMap;

    /**
     * @brief Player's name.
     */
    const IdentifierPtr name;

    /**
     * @brief Player's strategies.
     */
    const IdentifiersPtr strategies;

    /**
     * @brief Mapps strategies to its ordinal.
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
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        Root& root
    ) override;

    /**
     * @brief Returns Message with Player's name and strategies.
     *
     * @return Player's name and strategies
     */
    virtual Message toString() override;

    /**
     * @brief Syntax sugar for isEqual method.
     *
     * @param player1 first Player to compare
     * @param player2 second Player to compare
     * @return        true if Players are equal
     */
    friend bool operator== (
        PlayerPtr& player1,
        PlayerPtr& player2
    );

    /**
     * @brief Syntax sugar for !isEqual method.
     *
     * @param player1 first Player to compare
     * @param player2 second Player to compare
     * @return        true if Players are not equal
     */
    friend bool operator!= (
        PlayerPtr& player1,
        PlayerPtr& player2
    );

    /**
     * @brief Syntax sugar for toStream method.
     *
     * @param stream stream to concatenate
     * @param player Player to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<< (
        OutputStream& stream,
        PlayerPtr&    player
    );
}; /* END class Player */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    virtual IdentifierPtr getName() override {
        return NullFactory::getInstance().createIdentifier();
    }

    virtual IdentifiersPtr getStrategies() override {
        return NullFactory::getInstance().createIdentifiers();
    }

    virtual Index getStrategiesNumber() override {
        return 0;
    }

    virtual Index getStrategyOrdinal(
        Identifier&
    ) override {
        return 0;
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullPlayer");
    }
}; /* END class NullPlayer */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_PLAYER_HPP__ */
