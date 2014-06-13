/**
 * @file      gt/model/extensive_data_node.cpp
 * @brief     Defines GT::Model::ExtensiveDataNode methods.
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

#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

using boost::adaptors::map_keys;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

void intrusive_ptr_add_ref(
    ExtensiveDataNode*
) {}

void intrusive_ptr_release(
    ExtensiveDataNode* parent
) {
    // ExtensiveDataNode implementation has parent set to nullptr - need to null check first
    if (parent && parent->isNull())
        delete parent;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

//class ExtensiveDataNode : public virtual Root {
// public:

ExtensiveDataNode::ExtensiveDataNode() :
    parent(new NullExtensiveDataNode()),
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(1),
    depthName(createIdentifier(1))
    {}

const ExtensiveDataNode& ExtensiveDataNode::getParent() const {
    return *parent;
}

const ExtensiveDataNodes& ExtensiveDataNode::getChildren() const {
    return *nodes;
}

const PlayerPtr ExtensiveDataNode::getPlayer() const {
    return player;
}

const PlayerPtr ExtensiveDataNode::getPlayer(
    const Positions& positions
) const {
    if (isPositionOfCurrentNodePlayer(positions))
        return player;

    if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);

    if (nodes->count(strategy))
        return (*nodes)[strategy]->getPlayer(positions);
    return NullFactory::getInstance().createPlayer();
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    const PlayerPtr newPlayer
) {
    player = newPlayer;
    return *this;
}

ExtensiveDataNode& ExtensiveDataNode::setPlayer(
    const Positions& positions,
    const PlayerPtr  newPlayer
) {
    if (isPositionOfCurrentNodePlayer(positions)) {
        if (player->isNotNull() && player != newPlayer)
            throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);
        setPlayer(newPlayer);
    }

    else if (!checkPlayerPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    else {
        const Identifier& strategy = positions.at(depthName);

        if (!nodes->count(strategy)) {
            ExtensiveDataNodePtr node(new ExtensiveDataNode(this, depthValue+1));
            nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
        }

        (*nodes)[strategy]->setPlayer(positions, newPlayer);
    }

    return *this;
}

const NumbersPtr ExtensiveDataNode::getPayoffs(
    const Positions& positions
) const {
    if (depthValue == 0)
        return payoff;

    if (!checkPositions(positions))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);
    return (*nodes)[strategy]->getPayoffs(positions);
}

ExtensiveDataNode& ExtensiveDataNode::setPayoffs(
    const Positions& positions,
    const NumbersPtr values
) {
    if (!positions.count(depthName))
        throw ExceptionFactory::getInstance().invalidCoordinateFormat(positions);

    const Identifier& strategy = positions.at(depthName);

    if (!nodes->count(strategy)) {
        ExtensiveDataNodePtr node;
        if (depthValue == positions.size())
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(this, values));
        else {
            node = ExtensiveDataNodePtr(new ExtensiveDataNode(this, depthValue+1));
            node->setPayoffs(positions, values);
        }
        nodes->insert( ExtensiveDataNodes::value_type(strategy, node) );
    } else if (depthValue != positions.size())
        (*nodes)[strategy]->setPayoffs(positions, values);
    else
        throw ExceptionFactory::getInstance().coordinatesAlreadySet(positions);

    return *this;
}

IdentifiersPtr ExtensiveDataNode::getChoices() const {
    IdentifiersPtr choices = createIdentifiersPtr();

    for (Identifier choice : *nodes | map_keys)
        choices->push_back( createIdentifierPtr(choice) );

    return choices;
}

bool ExtensiveDataNode::hasChoice(
    const Identifier& strategy
) const {
    return nodes->count(strategy);
}

bool ExtensiveDataNode::isLeaf() const {
    return nodes->empty();
}

const ExtensiveDataNode& ExtensiveDataNode::getNodeForChoice(
    const Identifier& strategy
) const {
    if (!nodes->count(strategy))
        throw ExceptionFactory::getInstance().invalidStrategy(strategy);

    return *nodes->at(strategy);
}

Message ExtensiveDataNode::toString() const {
    static const IdentifierPtr    valueName     = createIdentifierPtr("Value");
    ResultBuilderPtr              resultBuilder = ResultFactory::getInstance().buildResult();

    if (depthValue == 0)
        for (NumberPtr& number : (*payoff)) {
            MessagePtr result = createMessagePtr(number);
            resultBuilder->addResult(valueName, result);
        }
    else {
        static const IdentifierPtr playerName  = createIdentifierPtr("Player");
        const MessagePtr           playerValue = createMessagePtr(player->toString());
        resultBuilder->addResult(playerName, playerValue);

        for (ExtensiveDataNodes::value_type& node : (*nodes)) {
            IdentifierPtr nodeName = createIdentifierPtr(node.first);
            MessagePtr    result   = createMessagePtr(node.second->toString());
            resultBuilder->addResult(nodeName, result);
        }
    }

    return resultBuilder->build()->getResult();
}

Message ExtensiveDataNode::toString(
    const ExtensiveGamePositionsHelper& positionsHelper
) const {
    static const IdentifierPtr valueName     = createIdentifierPtr("Value");
    ResultBuilderPtr           resultBuilder = ResultFactory::getInstance().buildResult();

    if (depthValue == 0)
        for (NumberPtr& number : (*payoff)) {
            MessagePtr result = createMessagePtr(number);
            resultBuilder->addResult(valueName, result);
        }
    else {
        static const IdentifierPtr playerName  = createIdentifierPtr("Player");
        const MessagePtr           playerValue = createMessagePtr(player->toString());
        resultBuilder->addResult(playerName, playerValue);

        static const IdentifierPtr setName  = createIdentifierPtr("Information Set");
        try {
            const MessagePtr           setValue = createMessagePtr(
                positionsHelper.getInformationSetsForPlayer(*player->getName())
                               .right.at(const_cast<GT::Model::ExtensiveDataNode* const>(this))
            );
            resultBuilder->addResult(setName, setValue);
        } catch (...) {}

        for (ExtensiveDataNodes::value_type& node : (*nodes)) {
            IdentifierPtr nodeName = createIdentifierPtr(node.first);
            MessagePtr    result   = createMessagePtr(node.second->toString(positionsHelper));
            resultBuilder->addResult(nodeName, result);
        }
    }

    return resultBuilder->build()->getResult();
}

// protected:

ExtensiveDataNode::ExtensiveDataNode(
    ExtensiveDataNode* definedParent,
    Index              currentDepth
) :
    parent(definedParent),
    player(NullFactory::getInstance().createPlayer()),
    payoff(new Numbers()),
    nodes(new ExtensiveDataNodes()),
    depthValue(currentDepth),
    depthName(createIdentifier(currentDepth))
    {}

ExtensiveDataNode::ExtensiveDataNode(
    ExtensiveDataNode* definedParent,
    NumbersPtr         values
) :
    parent(definedParent),
    player(NullFactory::getInstance().createPlayer()),
    payoff(values),
    nodes(new ExtensiveDataNodes()),
    depthValue(0),
    depthName("")
    {}

// private:

bool ExtensiveDataNode::isPositionOfCurrentNodePlayer(
    const Positions& positions
) const {
    return depthValue == positions.size()+1;
}

bool ExtensiveDataNode::checkPositions(
    const Positions& positions
) const {
    return positions.count(depthName) && nodes->count(positions.at(depthName));
}

bool ExtensiveDataNode::checkPlayerPositions(
    const Positions& positions
) const {
    return positions.empty() || positions.count(depthName);
}

// }; /* END class ExtensiveDataNode */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
