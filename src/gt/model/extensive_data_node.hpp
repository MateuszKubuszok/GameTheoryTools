#ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class ExtensiveDataNode : public virtual Root {
    /**
     * @brief Player which strategis are allowed in this Node.
     */
    PlayerPtr             player;
    /**
     * @brief Payoff values.
     */
    NumbersPtr            payoff;
    /**
     * @brief Children of this node (choices).
     */
    ExtensiveDataNodesPtr nodes;
    /**
     * @brief Current depth's value.
     */
    Index                 depthValue;
    /**
     * @brief Current depth's name.
     */
    Identifier            depthName;

public:
    /**
     * @brief Root's constructor.
     */
    ExtensiveDataNode();

    /**
     * @brief Child Node constructor.
     *
     * @param depth depth of a created Node
     */
    explicit ExtensiveDataNode(
        Index depth
    );

    /**
     * @brief Leaf Node constructor.
     *
     * @param values Payoff values
     */
    explicit ExtensiveDataNode(
        NumbersPtr values
    );

    /**
     * @brief Returns Player of a current Node.
     *
     * @return Player of this Node
     */
    PlayerPtr getPlayer();

    /**
     * @brief Returns Player for a given Positions.
     *
     * @param positions Positions of a sought Player
     * @return          Player of this Node
     */
    PlayerPtr getPlayer(
        Positions& positions
    );

    /**
     * @brief Sets Player of a current Node.
     *
     * @param player Player of this Node
     * @return       reference to itself for chaining
     */
    ExtensiveDataNode& setPlayer(
        PlayerPtr player
    );

    /**
     * @brief Sets Player of a current Node.
     *
     * @param positions Positions of a set Player
     * @param player    Player of this Node
     * @return          reference to itself for chaining
     */
    ExtensiveDataNode& setPlayer(
        Positions& positions,
        PlayerPtr  player
    );

    /**
     * @brief Return Payoff values.
     *
     * @param  positions Positions of a sought Payoff
     * @return           values of Payoffs
     */
    NumbersPtr getValues(
        Positions& positions
    );

    /**
     * @brief Sets Payoff values.
     *
     * @param  positions Positions of a set Payoff
     * @param  values    Payoff value
     * @return           reference to itself for chaining
     */
    ExtensiveDataNode& setValues(
        Positions& positions,
        NumbersPtr values
    );

    /**
     * @brief ExtensiveDataNode's Message.
     *
     * @return Message
     */
    Message toString();

private:
    /**
     * @brief Whether passed Positions of a Platyer point to a current Node.
     *
     * @param positions Positions of sought Player
     * @return          true if Positions point to a Player in this Node
     */
    bool isPositionOfCurrentNodePlayer(
        Positions& positions
    );

    /**
     * @brief Whether Positions contains choice for current Node.
     *
     * @param positions Positions of sought Payoff
     * @return          true if Positions contains strategy for current depth that is available in this node
     */
    bool checkPositions(
        Positions& positions
    );

    /**
     * @brief Whether Positions contains NEXT choice.
     *
     * @param positions Positions of sought Player
     * @return          true if Positions are empty or contains some choice for this depth
     */
    bool checkPlayerPositions(
        Positions& positions
    );
}; /* END class ExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__ */
