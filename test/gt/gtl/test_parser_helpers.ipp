// class TestConditionDriverImpl {
// public:

inline unsigned int TestConditionDriverImpl::getCreatedConditions() {
    return createdConditions;
}

// }

////////////////////////////////////////////////////////////////////////////////


// class TestCoordinateDriverImpl {
// public:


inline unsigned int TestCoordinateDriverImpl::getCreatedCoordinates() {
    return createdCoordinates;
}

inline unsigned int TestCoordinateDriverImpl::getFilledCoordinates() {
    return filledCoordinates;
}

inline  unsigned int TestCoordinateDriverImpl::getMergeCoordinates() {
    return mergedCoordinates;
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl {
// public:

inline unsigned int TestGameDriverImpl::getCreatedStrategicGames() {
    return createdStrategicGames;
}

inline unsigned int TestGameDriverImpl::getCreatedExtensiveGames() {
    return createdExtensiveGames;
}

inline unsigned int TestGameDriverImpl::getCreatedDetails() {
    return createdDetails;
}

inline unsigned int TestGameDriverImpl::getCreatedPlayers() {
    return createdPlayers;
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl {
// public:

inline unsigned int TestStatementDriverImpl::getExecutedDefinitions() {
    return executedDefinitions;
}

inline unsigned int TestStatementDriverImpl::getExecutedQueries() {
    return executedQueries;
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl {
// public:

inline unsigned int TestValueDriverImpl::getUsedParameters() {
    return usedParameters;
}

// }

////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl {
// public:

inline unsigned int TestDriverImpl::getShownErrors() {
    return shownErrors;
}

// }
