#ifndef __GT_GTL_TEST_PARSER_HELPERS_HPP__
#define __GT_GTL_TEST_PARSER_HELPERS_HPP__

////////////////////////////////////////////////////////////////////////////////

template<typename Content>
class TestCollectionsDriverImpl : public GT::GTL::NullCollectionsDriver<Content> {
    unsigned int createdCollections;
    unsigned int addedElements;

public:
    TestCollectionsDriverImpl<Content>();

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* empty();

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* create(
        typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr* element
    );

    virtual typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* insert(
        typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr*    element,
        typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* collection
    );

    inline unsigned int getCreatedCollections();

    inline unsigned int getAddedElements();
}; /* END class TestCollectionsDriver */

////////////////////////////////////////////////////////////////////////////////

class TestConditionDriverImpl : public GT::GTL::NullConditionDriver {
    unsigned int createdConditions;

public:
    TestConditionDriverImpl();

    virtual GT::GTL::ConditionPtr* playerChoosed(
        GT::GTL::ObjectPtr* player,
        GT::GTL::ObjectPtr* strategy
    );

    inline unsigned int getCreatedConditions();
}; /* END class TestConditionDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class TestCoordinateDriverImpl : public GT::GTL::NullCoordinateDriver {
    unsigned int createdCoordinates;
    unsigned int filledCoordinates;
    unsigned int mergedCoordinates;

public:
    TestCoordinateDriverImpl();

    virtual GT::GTL::CoordinatePtr* create(
        const GT::IdentifierPtr* player,
        const GT::IdentifierPtr* strategy
    );

    virtual GT::GTL::CoordinatePtr* fillWithData(
        const GT::GTL::CoordinatePtr* coordinate,
        const GT::GTL::ParamsPtr*     data
    );

    virtual GT::GTL::CoordinatePtr* merge(
        const GT::GTL::CoordinatePtr* coordinate1,
        const GT::GTL::CoordinatePtr* coordinate2
    );

    inline unsigned int getCreatedCoordinates();

    inline unsigned int getFilledCoordinates();

    inline unsigned int getMergeCoordinates();
}; /* END class TestCoordinateDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class TestGameDriverImpl : public GT::GTL::NullGameDriver {
    unsigned int createdStrategicGames;
    unsigned int createdTreeGames;
    unsigned int createdDetails;
    unsigned int createdPlayers;

public:
    TestGameDriverImpl();

    virtual GT::GTL::GamePtr* createStrategic(
        GT::GTL::DetailsPtr* details
    );

    virtual GT::GTL::GamePtr* createTree(
        GT::GTL::DetailsPtr* details
    );

    virtual GT::GTL::DetailsPtr* createDetails(
        GT::GTL::ObjectsPtr*     players,
        GT::GTL::CoordinatesPtr* data
    );

    virtual GT::GTL::PlayerPtr* createPlayer(
        GT::IdentifierPtr*  player,
        GT::IdentifiersPtr* strategies
    );

    inline unsigned int getCreatedStrategicGames();

    inline unsigned int getCreatedTreeGames();

    inline unsigned int getCreatedDetails();

    inline unsigned int getCreatedPlayers();
}; /* END class TestGameDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class TestStatementDriverImpl : public GT::GTL::NullStatementDriver {
    unsigned int executedDefinitions;
    unsigned int executedQueries;

public:
    TestStatementDriverImpl();

    virtual bool executeDefinition(
        GT::GTL::DefinitionPtr*
    );

    virtual bool executeQuery(
        GT::GTL::QueryPtr*
    );

    inline unsigned int getExecutedDefinitions();

    inline unsigned int getExecutedQueries();
}; /* END class TestStatementDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class TestValueDriverImpl : public GT::GTL::NullValueDriver {
    unsigned int usedParameters;

public:
    TestValueDriverImpl();

    virtual GT::GTL::ParamPtr* get(
        GT::IdentifierPtr* identifier
    );

    virtual GT::GTL::ParamPtr* get(
        GT::NumberPtr* number
    );

    inline unsigned int getUsedParameters();
}; /* END class TestValueDriverImpl */

////////////////////////////////////////////////////////////////////////////////

class TestDriverImpl : public GT::GTL::Driver {
    unsigned int shownErrors;
    
public:
    TestCoordinateDriverImpl                       coordinate;
    TestCollectionsDriverImpl<GT::GTL::Coordinate> coordinates;
    TestConditionDriverImpl                        condition;
    TestCollectionsDriverImpl<GT::GTL::Condition>  conditions;
    TestGameDriverImpl                             game;
    TestCollectionsDriverImpl<GT::Identifier>      identifiers;
    TestCollectionsDriverImpl<GT::GTL::Object>     objects;
    TestCollectionsDriverImpl<GT::GTL::Param>      params;
    TestValueDriverImpl                            value;
    TestStatementDriverImpl                        statement;

    TestDriverImpl();

    virtual GT::GTL::CoordinateDriver& forCoordinate();

    virtual GT::GTL::CollectionsDriver<GT::GTL::Coordinate>& forCoordinates();

    virtual GT::GTL::ConditionDriver& forCondition();
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Condition>& forConditions();

    virtual GT::GTL::GameDriver& forGame();
    
    virtual GT::GTL::CollectionsDriver<GT::Identifier>& forIdentifiers();
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Object>& forObjects();
    
    virtual GT::GTL::CollectionsDriver<GT::GTL::Param>& forParams();

    virtual GT::GTL::ValueDriver& forValue();

    virtual GT::GTL::StatementDriver& forStatement();

    virtual void showError(
        const GT::Message&
    );

    virtual void showError(
        GT::GTL::ValidableSymbol&
    );

    inline unsigned int getShownErrors();

    virtual GT::Message toString();
}; /* END class TestDriverImpl */

////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/test_parser_helpers.tpp"

////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/test_parser_helpers.ipp"

////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_GTL_TEST_PARSER_HELPERS_HPP__ */
