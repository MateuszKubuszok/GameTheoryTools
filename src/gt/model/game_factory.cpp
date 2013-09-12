#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex gameFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class PlainData : public virtual Root {
    PlayersPtr players;

    boost::container::vector<Identifier> playerNames;

    boost::container::map<int, NumbersPtr> params;

public:
    NumberPtr getValue(
        PositionsPtr  positions, 
        IdentifierPtr playerName
    ) {
        // TODO: retrive value from map
        return NullFactory::getInstance().createNumber();
    }

    NumbersPtr getValues(
        int positionInMap
    ) {
        if (!params.count(positionInMap))
            // TODO: create ExceptionFactory and define exceptions
            // (rename standard ones)
            throw std::invalid_argument("No params under such condition");
        return params[positionInMap];
    }

    NumbersPtr getValues(
        PositionsPtr positions
    ) {
        return getValues(
            calculatePosition(positions)
        );
    }

    PlainData& setValues(int positionInMap, NumbersPtr numbers) {
        params.insert(
            std::make_pair(
                positionInMap,
                numbers
            )
        );
        return *this;
    }

    PlainData& setValues(
        PositionsPtr positions,
        NumbersPtr   numbers
    ) {
        return setValues(
            calculatePosition(positions),
            numbers
        );
    }

    Message toString() {
        // TODO: print data as table: | positions | values |
        return *NullFactory::getInstance().createMessage();
    }

private:
    int calculatePosition(
        PositionsPtr positions
    ) {
        // TODO: positions -> int
        // throw std::runtime_exception if positions do not match players
        return 0;
    }

    bool checkPlayer(
        IdentifierPtr playerName
    ) {
        // TODO:
        return true;
    }

    bool checkPositions(
        PositionsPtr positions
    ) {
        // TODO:
        return true;
    }

    ResultPtr contentMessage() {
        // TODO: generate message with conetent using ResultBuilder
        return NullFactory::getInstance().createResult();
    }
};

////////////////////////////////////////////////////////////////////////////////

// class PlainDataBuilder : public DataBuilder {
//     PlayersPtr players;

//     boost::container::map<Identifier, bool> allocatedPositions;

//     PositionsPtr positions;


// }; 

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
