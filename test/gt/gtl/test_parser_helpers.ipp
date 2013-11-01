// class TestConditionDriverImpl : public GT::GTL::NullConditionDriver {
// public:

inline unsigned int TestConditionDriverImpl::getCreatedConditions() {
    return createdConditions;
}

// }; /* END class TestConditionDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////


// class TestCoordinateDriverImpl : public GT::GTL::NullCoordinateDriver {
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

// }; /* END class TestCoordinateDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestGameDriverImpl : public GT::GTL::NullGameDriver {
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

// }; /* END class TestGameDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestStatementDriverImpl : public GT::GTL::NullStatementDriver {
// public:

inline unsigned int TestStatementDriverImpl::getExecutedDefinitions() {
    return executedDefinitions;
}

inline unsigned int TestStatementDriverImpl::getExecutedQueries() {
    return executedQueries;
}

// }; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestValueDriverImpl : public GT::GTL::NullValueDriver {
// public:

inline unsigned int TestValueDriverImpl::getUsedParameters() {
    return usedParameters;
}

// }; /* END class TestValueDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class TestDriverImpl : public GT::GTL::Driver {
// public:

inline unsigned int TestDriverImpl::getShownResults() {
    return shownResults;
}

inline unsigned int TestDriverImpl::getShownErrors() {
    return shownErrors;
}

// }; /* END class TestDriverImpl */
