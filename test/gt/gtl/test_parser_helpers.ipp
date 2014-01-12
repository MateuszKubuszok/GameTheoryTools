// class TestConditionDriverImpl : public GT::GTL::NullConditionDriver {
// public:

inline unsigned int TestConditionDriverImpl::getCreatedConditions() const {
    return createdConditions;
}

// }; /* END class TestConditionDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


// class TestCoordinateDriverImpl : public GT::GTL::NullCoordinateDriver {
// public:

inline unsigned int TestCoordinateDriverImpl::getCreatedCoordinates() const {
    return createdCoordinates;
}

inline unsigned int TestCoordinateDriverImpl::getFilledCoordinates() const {
    return filledCoordinates;
}

inline  unsigned int TestCoordinateDriverImpl::getMergeCoordinates() const {
    return mergedCoordinates;
}

// }; /* END class TestCoordinateDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl : public GT::GTL::NullGameDriver {
// public:

inline unsigned int TestGameDriverImpl::getCreatedStrategicGames() const {
    return createdStrategicGames;
}

inline unsigned int TestGameDriverImpl::getCreatedExtensiveGames() const {
    return createdExtensiveGames;
}

inline unsigned int TestGameDriverImpl::getCreatedDetails() const {
    return createdDetails;
}

inline unsigned int TestGameDriverImpl::getCreatedPlayers() const {
    return createdPlayers;
}

// }; /* END class TestGameDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl : public GT::GTL::NullStatementDriver {
// public:

inline unsigned int TestStatementDriverImpl::getExecutedDefinitions() const {
    return executedDefinitions;
}

inline unsigned int TestStatementDriverImpl::getExecutedQueries() const {
    return executedQueries;
}

// }; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl : public GT::GTL::NullValueDriver {
// public:

inline unsigned int TestValueDriverImpl::getUsedParameters() const {
    return usedParameters;
}

// }; /* END class TestValueDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl : public GT::GTL::Driver {
// public:

inline unsigned int TestDriverImpl::getShownResults() const {
    return shownResults;
}

inline unsigned int TestDriverImpl::getShownErrors() const {
    return shownErrors;
}

inline unsigned int TestDriverImpl::getExecuted() const {
    return executed;
}

inline unsigned int TestDriverImpl::getLoaded() const {
    return loaded;
}

inline unsigned int TestDriverImpl::getSaved() const {
    return saved;
}

// }; /* END class TestDriverImpl */
