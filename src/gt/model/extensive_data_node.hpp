#ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates Tree containing whole ExtensiveData content.
 *
 * @author Mateusz Kubuszok
 *
 * @see ExtensiveData
 */
class ExtensiveDataNode : public virtual Root {
    /**
     * @brief Parent of this node.
     */
    ExtensiveDataNode*    parent;
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
     * @brief Tree's root's constructor.
     */
    ExtensiveDataNode();

    /**
     * @brief Tree's root's destructor.
     */
    virtual ~ExtensiveDataNode();

    /**
     * @brief Returns parent pf this Node (Null object for Root).
     *
     * @return parent Node
     */
    virtual ExtensiveDataNode& getParent();

    /**
     * @brief Returns Player of a current Node.
     *
     * @return Player of this Node
     */
    virtual PlayerPtr getPlayer();

    /**
     * @brief Returns Player for a given Positions.
     *
     * @param positions Positions of a sought Player
     * @return          Player of this Node
     */
    virtual PlayerPtr getPlayer(
        Positions& positions
    );

    /**
     * @brief Sets Player of a current Node.
     *
     * @param player Player of this Node
     * @return       reference to itself for chaining
     */
    virtual ExtensiveDataNode& setPlayer(
        PlayerPtr player
    );

    /**
     * @brief Sets Player of a current Node.
     *
     * @param positions Positions of a set Player
     * @param player    Player of this Node
     * @return          reference to itself for chaining
     */
    virtual ExtensiveDataNode& setPlayer(
        Positions& positions,
        PlayerPtr  player
    );

    /**
     * @brief Return Payoff values.
     *
     * @param  positions Positions of a sought Payoff
     * @return           values of Payoffs
     */
    virtual NumbersPtr getValues(
        Positions& positions
    );

    /**
     * @brief Sets Payoff values.
     *
     * @param  positions Positions of a set Payoff
     * @param  values    Payoff value
     * @return           reference to itself for chaining
     */
    virtual ExtensiveDataNode& setValues(
        Positions& positions,
        NumbersPtr values
    );

    /**
     * @brief ExtensiveDataNode's Message.
     *
     * @return Message
     */
    virtual Message toString();

protected:
    /**
     * @brief Child Node constructor.
     *
     * @param parent parent of thisNode
     * @param depth  depth of a created Node
     */
    ExtensiveDataNode(
        ExtensiveDataNode* parent,
        Index              depth
    );

    /**
     * @brief Leaf Node constructor.
     *
     * @param parent parent of thisNode
     * @param values Payoff values
     */
    ExtensiveDataNode(
        ExtensiveDataNode* parent,
        NumbersPtr         values
    );

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

/**
 * @brief Null ExtensiveDriver for acting as a root's parent.
 *
 * @author Mateusz Kubuszok
 */
class NullExtensiveDataNode : public ExtensiveDataNode {
public:
    NullExtensiveDataNode() :
        ExtensiveDataNode(
            nullptr, // prevents infinite loop of constructor calls
            Model::NullFactory::getInstance().createNumbers()
        )
        {}

    virtual ExtensiveDataNode& getParent() {
        return *this;
    }

    virtual PlayerPtr getPlayer() {
        return NullFactory::getInstance().createPlayer();
    }

    virtual PlayerPtr getPlayer(
        Positions&
    ) {
        return NullFactory::getInstance().createPlayer();
    }

    virtual ExtensiveDataNode& setPlayer(
        PlayerPtr
    ) {
        return *this;
    }

    virtual ExtensiveDataNode& setPlayer(
        Positions&,
        PlayerPtr
    ) {
        return *this;
    }

    virtual NumbersPtr getValues(
        Positions&
    ) {
        return Model::NullFactory::getInstance().createNumbers();
    }

    virtual ExtensiveDataNode& setValues(
        Positions&,
        NumbersPtr
    ) {
        return *this;
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullExtensiveDataNode");
    }
}; /* END class NullExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__ */
