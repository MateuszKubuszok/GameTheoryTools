#include <boost/foreach.hpp>
#include <boost/bimap/bimap.hpp>
#include <boost/range/adaptor/map.hpp>
#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

typedef boost::bimaps::bimap<Identifier, Index>          IdentifierMap;
typedef boost::container::map<Identifier, IdentifierMap> StrategyMap;

////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class PlainDataPiece : public DataPiece {
    IdentifierMap playersMap;
    NumbersPtr    numbers;

public:
    PlainDataPiece(
        IdentifierMap players,
        NumbersPtr    params
    ) :
        playersMap(players),
        numbers(params)
        {}

    virtual NumberPtr& getValue(
        Identifier& playerName
    ) {
        if (!playersMap.left.count(playerName))
            throw InvalidCoordinate("No such player");
        return (*numbers)[playersMap.left.at(playerName)];
    }

    virtual Message toString() {
        // TODO
        return Message();
    }
};

////////////////////////////////////////////////////////////////////////////////

class PlainData : public Data {
    PlayersPtr players;

    IdentifierMap playersHelper;
    StrategyMap   strategiesHelper;
    IdentifierMap positionsHelper;

    boost::container::vector<NumbersPtr> paramsStorage;
    boost::container::vector<bool>       paramsStorageAllocation;
    
public:
    PlainData(
        PlayersPtr playersDefinitions
    ) :
        players(playersDefinitions),
        playersHelper(),
        strategiesHelper(),
        positionsHelper(),
        paramsStorage(),
        paramsStorageAllocation()
    {
        Index playerIndex   = 0;
        Index positionIndex = 1;

        BOOST_FOREACH(Players::value_type playerPair, (*players)) {
            const Identifier& playerName = playerPair.first;
            Player& player = *playerPair.second;

            IdentifierMap strategiesMap;
            BOOST_FOREACH(IdentifierPtr& strategy, (*player.getStrategies()))
                strategiesMap.insert( IdentifierMap::value_type(*strategy, player.getStrategyOrdinal(*strategy)) );
            playersHelper.insert( IdentifierMap::value_type(playerName, playerIndex) );
            positionsHelper.insert( IdentifierMap::value_type(playerName, positionIndex) );
            strategiesHelper.insert( StrategyMap::value_type(playerName, strategiesMap) );

            playerIndex++;
            positionIndex *= player.getStrategiesNumber();
        }
    }

    virtual DataPiecePtr getValues(
        Index positionInStorage
    ) {
        if (!paramsStorageAllocation[positionInStorage])
            throw InvalidCoordinate("No params under such position");
        
        return DataPiecePtr(
            new PlainDataPiece(
                playersHelper,
                paramsStorage[positionInStorage]
            )
        );
    }

    virtual DataPiecePtr getValues(
        Positions& positions
    ) {
        return getValues(calculatePosition(positions));
    }

    virtual DataPiecePtr getValues(
        PositionsPtr positions
    ) {
        return getValues(*positions);
    }

    virtual Data& setValues(
        Index      positionInStorage,
        NumbersPtr numbers
    ) {
        paramsStorage[positionInStorage] = numbers;
        paramsStorageAllocation[positionInStorage] = true;

        return *this;
    }

    virtual Data& setValues(
        Positions& positions,
        NumbersPtr numbers
    ) {
        if (!checkPositions(positions))
            throw InvalidCoordinate("Invalid coordinates format");

        return setValues(
            calculatePosition(positions),
            numbers
        );
    }

    virtual Data& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        return setValues(*positions, numbers);
    }

    virtual DataPiecePtr operator[](
        Index positionInStorage
    ) {
        return getValues(positionInStorage);
    }

    virtual DataPiecePtr operator[](
        Positions& positions
    ) {
        return getValues(positions);
    }

    virtual DataPiecePtr operator[](
        PositionsPtr positions
    ) {
        return getValues(positions);
    }

    virtual Message toString() {
        return contentMessage()->getResult();
    }

private:
    Index calculatePlayer(
        Identifier& playerName
    ) {
        return playersHelper.left.at(playerName);
    }

    Index calculatePlayer(
        IdentifierPtr playerName
    ) {
        return checkPlayer(*playerName);
    }

    Index calculatePosition(
        Positions& positions
    ) {
        Index storagePosition = 0;
        BOOST_FOREACH(Positions::value_type& position, positions) {
            storagePosition +=
                positionsHelper.left.at(position.first)
                *
                strategiesHelper[position.first].left.at(position.second);
        }
        return storagePosition;
    }

    Index calculatePosition(
        PositionsPtr positions
    ) {
        return calculatePosition(*positions);
    }

    bool checkPlayer(
        Identifier& playerName
    ) {
        return playersHelper.left.count(playerName);
    }

    bool checkPlayer(
        IdentifierPtr playerName
    ) {
        return checkPlayer(*playerName);
    }

    bool checkPositions(
        Positions& positions
    ) {
        BOOST_FOREACH(Identifier playerName, positions | boost::adaptors::map_keys) {
            if (!checkPlayer(playerName))
                return false;
            Identifier strategyName = positions[playerName];
            if (!strategiesHelper[playerName].left.count(strategyName))
                return false;
        }
        return true;
    }

    bool checkPositions(
        PositionsPtr positions
    ) {
        return checkPositions(*positions);
    }

    ResultPtr contentMessage() {
        // TODO: generate message with conetent using ResultBuilder
        return NullFactory::getInstance().createResult();
    }
}; /* END class PlainData */

////////////////////////////////////////////////////////////////////////////////

class PlainDataBuilder : public DataBuilder {
    typedef boost::container::map<Identifier, bool> KnownPositions;

    DataPtr data;

    PlayersPtr players;

    Positions      currentPositions;
    KnownPositions currentlyKnownPositions;

public:
    PlainDataBuilder() :
        data(NullFactory::getInstance().createData()),
        players(NullFactory::getInstance().createPlayers()),
        currentPositions(),
        currentlyKnownPositions()
        {}

    virtual DataBuilder& setPlayers(
        PlayersPtr newPlayers
    ) {
        if (data->isNotNull())
            throw IllegalInnerState("Cannot change already set Players");

        data    = DataPtr(new PlainData(newPlayers));
        players = newPlayers;
        
        return *this;
    }

    virtual DataBuilder& addNextPositions(
        PositionsPtr positions
    ) {
        BOOST_FOREACH(Positions::value_type& position, (*positions)) {
            if (currentlyKnownPositions.count(position.first) && currentlyKnownPositions[position.first])
                throw InvalidCoordinate("Some of Coordinates are already set");
            if (!(*players)[position.first]->hasStrategy(position.second))
                throw InvalidCoordinate("Coordinate value not allowed");
        }

        BOOST_FOREACH(Positions::value_type& position, (*positions)) {
            currentPositions.insert( position );
            currentlyKnownPositions.insert( KnownPositions::value_type(position.first, true) );
        }

        return *this;
    }

    virtual DataBuilder& setParams(
        NumbersPtr params
    ) {
        BOOST_FOREACH(Identifier player, (*players) | boost::adaptors::map_keys)
            if (!currentlyKnownPositions.count(player) || !currentlyKnownPositions[player])
                throw IllegalInnerState("Cannot set parameters when not all coordinates are known");

        data->setValues(currentPositions, params);

        return *this;
    }

    virtual DataBuilderPtr clone() {
        return DataBuilderPtr(new PlainDataBuilder(*this));
    }

    virtual Message toString() {
        // TODO
        return Message();
    }
}; /* END class PlainDataBuilder */

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
GameFactory* volatile GameFactory::instance = 0;

// public:
GameFactory& GameFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(gameFactoryMutex);
        if (!instance) {
            GameFactory* volatile tmp = new GameFactory();
            instance = tmp;
        }
    }
    return *instance;
}

GameBuilderPtr GameFactory::buildPureGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildMixedGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

GameBuilderPtr GameFactory::buildTreeGame() {
    // TODO
    return NullFactory::getInstance().createGameBuilder();
}

// private:
GameFactory::GameFactory() {}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
