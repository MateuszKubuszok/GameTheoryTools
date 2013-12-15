#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ExtensiveGamePositionsHelper : public Root {
// public:

ExtensiveGamePositionsHelper::ExtensiveGamePositionsHelper(
    const ExtensiveDataNodePtr extensiveGameRoot
) :
    root(extensiveGameRoot),
    playersInformationSets()
{
    boost::container::vector<ExtensiveDataNode*> currentlyChecked;
    boost::container::vector<ExtensiveDataNode*> nextToBeChecked;

    currentlyChecked.push_back( root.get() );

    while (!currentlyChecked.empty()) {
        for (ExtensiveDataNode* currentNode : currentlyChecked) {
            // leafs doesn't contains decisions and thus cannot make information sets
            if (!currentNode->isLeaf()) {
                const Identifier& player = *currentNode->getPlayer()->getName();

                if (!playersInformationSets.count(player))
                    playersInformationSets.insert(
                        PlayersInformationSets::value_type( player, PlayerInformationSets() )
                    );

                PlayerInformationSets& informationSets = playersInformationSets.at(player);
                informationSets.insert(
                    PlayerInformationSets::value_type(
                        createIdentifier(informationSets.size()+1),
                        currentNode
                    )
                );

                const ExtensiveDataNodes& children = currentNode->getChildren();
                nextToBeChecked.reserve( nextToBeChecked.size() + children.size() );
                for (const ExtensiveDataNodePtr& nextNode : children | boost::adaptors::map_values)
                    nextToBeChecked.push_back( nextNode.get() );
            }
        }
        currentlyChecked.clear();
        currentlyChecked.reserve( nextToBeChecked.size() );
        currentlyChecked.insert(currentlyChecked.end(), nextToBeChecked.begin(), nextToBeChecked.end());
        nextToBeChecked.clear();
    }
}

IdentifiersPtr ExtensiveGamePositionsHelper::getPossiblePlayers() const {
    IdentifiersPtr players = createIdentifiersPtr();

    for (Identifier playerName : playersInformationSets | boost::adaptors::map_keys)
        players->push_back( createIdentifierPtr(playerName) );

    return players;
}

bool ExtensiveGamePositionsHelper::isPlayerPossible(
    const Identifier& playerName
) const {
    for (Identifier checkedPlayerName : playersInformationSets | boost::adaptors::map_keys)
        if (playerName == checkedPlayerName)
            return true;
    return false;
}

IdentifiersPtr ExtensiveGamePositionsHelper::getPossibleInformationSetsForPlayer(
    const Identifier& player
) const {
    if (!playersInformationSets.count(player))
        throw ExceptionFactory::getInstance().invalidPlayer(player);

    IdentifiersPtr informationSets = createIdentifiersPtr();

    for (Identifier setName : playersInformationSets.at(player).left | boost::adaptors::map_keys)
        informationSets->push_back( createIdentifierPtr(setName) );

    return informationSets;
}

const ExtensiveGamePositionsHelper::PlayerInformationSets&
ExtensiveGamePositionsHelper::getInformationSetsForPlayer(
    const Identifier& player
) const {
    if (!playersInformationSets.count(player))
        throw ExceptionFactory::getInstance().invalidPlayer(player);

    return playersInformationSets.at(player);
}

const ExtensiveDataNode& ExtensiveGamePositionsHelper::getInformationSetForPlayer(
    const Identifier& player,
    const Identifier& setName
) const {
    if (!playersInformationSets.count(player))
        throw ExceptionFactory::getInstance().invalidPlayer(player);
    if (!playersInformationSets.at(player).left.count(setName))
        throw ExceptionFactory::getInstance().invalidInformationSet(setName);

    return *playersInformationSets.at(player).left.at(setName);
}

Message ExtensiveGamePositionsHelper::toString() const {
    return Message("ExtensiveGamePositionsHelper");
}

// }; /* END class ExtensiveGamePositionsHelper */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
