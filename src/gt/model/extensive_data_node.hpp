#ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__
#define __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @file      gt/model/extensive_data_node.hpp
 * @brief     Defines GT::Model::ExtensiveDataNode class.
 * @copyright (C) 2013-2014
 * @author    Mateusz Kubuszok
 *
 * This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero
 * General Public License as published by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this program. If not,
 * see [http://www.gnu.org/licenses/].
 */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class ExtensiveDataNode
 * @brief Creates tree containing whole ExtensiveData content.
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
     * @brief Returns parent of this Node (Null object for Root).
     *
     * @return parent Node
     */
    virtual const ExtensiveDataNode& getParent() const;

    /**
     * @brief Returns children of this Node (empty for leaf).
     *
     * @return children Nodes
     */
    virtual const ExtensiveDataNodes& getChildren() const;

    /**
     * @brief Returns Player of a current Node.
     *
     * @return Player of this Node
     */
    virtual const PlayerPtr getPlayer() const;

    /**
     * @brief Returns Player for a given Positions.
     *
     * @param positions Positions of a sought Player
     * @return          Player of this Node
     */
    virtual const PlayerPtr getPlayer(
        const Positions& positions
    ) const;

    /**
     * @brief Sets Player of a current Node.
     *
     * @param player Player of this Node
     * @return       reference to itself for chaining
     */
    virtual ExtensiveDataNode& setPlayer(
        const PlayerPtr player
    );

    /**
     * @brief Sets Player of a current Node.
     *
     * @param positions Positions of a set Player
     * @param player    Player of this Node
     * @return          reference to itself for chaining
     */
    virtual ExtensiveDataNode& setPlayer(
        const Positions& positions,
        const PlayerPtr  player
    );

    /**
     * @brief Returns Payoff values.
     *
     * @param  positions Positions of a sought Payoff
     * @return           values of Payoffs
     */
    virtual const NumbersPtr getValues(
        const Positions& positions
    ) const;

    /**
     * @brief Sets Payoff values.
     *
     * @param  positions Positions of a set Payoff
     * @param  values    Payoff value
     * @return           reference to itself for chaining
     */
    virtual ExtensiveDataNode& setValues(
        const Positions& positions,
        const NumbersPtr values
    );

    /**
     * @brief Returns available choices.
     *
     * @return choices
     */
    virtual IdentifiersPtr getChoices() const;

    /**
     * @brief Returns whether such choice is available.
     *
     * @param strategy choice to check
     * @return         true if choice is available
     */
    virtual bool hasChoice(
        const Identifier& strategy
    ) const;

    /**
     * @brief Returns node for given choice.
     *
     * @param strategy        choice to obtain
     * @return                node for choice
     * @thors InvalidStrategy thrown if such strategy isn't available choice
     */
    virtual const ExtensiveDataNode& getNodeForChoice(
        const Identifier& strategy
    ) const;

    /**
     * @brief Returns whether the node is a leaf.
     *
     * @return true if the node is a leaf
     */
    virtual bool isLeaf() const;

    /**
     * @brief ExtensiveDataNode's Message.
     *
     * @return Message
     */
    virtual Message toString() const override;

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
        const Positions& positions
    ) const;

    /**
     * @brief Whether Positions contains choice for current Node.
     *
     * @param positions Positions of sought Payoff
     * @return          true if Positions contains strategy for current depth that is available in this node
     */
    bool checkPositions(
        const Positions& positions
    ) const;

    /**
     * @brief Whether Positions contains NEXT choice.
     *
     * @param positions Positions of sought Player
     * @return          true if Positions are empty or contains some choice for this depth
     */
    bool checkPlayerPositions(
        const Positions& positions
    ) const;
}; /* END class ExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @class NullExtensiveDataNode
 * @brief Null ExtensiveDriver for acting as a root's parent.
 *
 * @author Mateusz Kubuszok
 */
class NullExtensiveDataNode final : public ExtensiveDataNode {
public:
    NullExtensiveDataNode() :
        ExtensiveDataNode(
            nullptr, // prevents infinite loop of constructor calls
            Model::NullFactory::getInstance().createNumbers()
        )
        {}

    virtual const ExtensiveDataNode& getParent() const override {
        return *this;
    }

    virtual const PlayerPtr getPlayer() const override {
        return NullFactory::getInstance().createPlayer();
    }

    virtual const PlayerPtr getPlayer(
        const Positions&
    ) const override {
        return NullFactory::getInstance().createPlayer();
    }

    virtual ExtensiveDataNode& setPlayer(
        const PlayerPtr
    ) override {
        return *this;
    }

    virtual ExtensiveDataNode& setPlayer(
        const Positions&,
        const PlayerPtr
    ) override {
        return *this;
    }

    virtual const NumbersPtr getValues(
        const Positions&
    ) const override {
        return Model::NullFactory::getInstance().createNumbers();
    }

    virtual ExtensiveDataNode& setValues(
        const Positions&,
        const NumbersPtr
    ) override {
        return *this;
    }

    virtual IdentifiersPtr getChoices() const override {
        return Model::NullFactory::getInstance().createIdentifiers();
    }

    virtual bool isLeaf() const override {
        return true;
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullExtensiveDataNode");
    }
}; /* END class NullExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EXTENSIVE_DATA_NODE_HPP__ */
