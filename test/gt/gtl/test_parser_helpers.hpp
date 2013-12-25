#ifndef __GT_GTL_TEST_PARSER_HELPERS_HPP__
#define __GT_GTL_TEST_PARSER_HELPERS_HPP__

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<typename Content>
class TestCollectionsDriverImpl final : public GT::GTL::CollectionsDriver<Content> {
    mutable unsigned int createdCollections;
    mutable unsigned int addedElements;

public:
    TestCollectionsDriverImpl<Content>();

    virtual typename TestCollectionsDriverImpl<Content>::CollectionPtr* empty() const override;

    virtual typename TestCollectionsDriverImpl<Content>::CollectionPtr* create(
        const typename TestCollectionsDriverImpl<Content>::ContentPtr* element
    ) const override;

    virtual typename TestCollectionsDriverImpl<Content>::CollectionPtr* insert(
        const typename TestCollectionsDriverImpl<Content>::ContentPtr*    element,
        const typename TestCollectionsDriverImpl<Content>::CollectionPtr* collection
    ) const override;

    inline unsigned int getCreatedCollections() const;

    inline unsigned int getAddedElements() const;

    virtual GT::Message toString() const override;
}; /* END class TestCollectionsDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestConditionDriverImpl final : public GT::GTL::ConditionDriver {
    mutable unsigned int createdConditions;

public:
    TestConditionDriverImpl();

    virtual GT::GTL::ConditionPtr* informationSetChoosed(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::ObjectPtr*     player,
        const GT::GTL::ObjectPtr*     informationSet,
        const GT::GTL::ObjectPtr*     strategy
    ) const override;

    virtual GT::GTL::ConditionPtr* informationSetWithin(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::ObjectPtr*     player,
        const GT::GTL::ObjectPtr*     informationSet,
        const GT::GTL::ObjectsPtr*    strategies
    ) const override;

    virtual GT::GTL::ConditionPtr* playerChoosed(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::ObjectPtr*     player,
        const GT::GTL::ObjectPtr*     strategy
    ) const override;

    virtual GT::GTL::ConditionPtr* playerWithin(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::ObjectPtr*     player,
        const GT::GTL::ObjectsPtr*    strategies
    ) const override;

    inline unsigned int getCreatedConditions() const;

    virtual GT::Message toString() const override;
}; /* END class TestConditionDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestCoordinateDriverImpl final : public GT::GTL::CoordinateDriver {
    mutable unsigned int createdCoordinates;
    mutable unsigned int filledCoordinates;
    mutable unsigned int mergedCoordinates;

public:
    TestCoordinateDriverImpl();

    virtual GT::GTL::CoordinatePtr* create(
        const GT::GTL::InputLocation& inputLocation,
        const GT::IdentifierPtr*      player,
        const GT::IdentifierPtr*      strategy
    ) const override;

    virtual GT::GTL::CoordinatePtr* fillWithData(
        const GT::GTL::InputLocation&  inputLocation,
        const GT::GTL::CoordinatePtr*  coordinate,
        const GT::GTL::CoordinatesPtr* data
    ) const override;

    virtual GT::GTL::CoordinatePtr* fillWithData(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::CoordinatePtr* coordinate,
        const GT::GTL::ParamsPtr*     data
    ) const override;

    virtual GT::GTL::CoordinatePtr* merge(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::CoordinatePtr* coordinate1,
        const GT::GTL::CoordinatePtr* coordinate2
    ) const override;

    inline unsigned int getCreatedCoordinates() const;

    inline unsigned int getFilledCoordinates() const;

    inline unsigned int getMergeCoordinates() const;

    virtual GT::Message toString() const override;
}; /* END class TestCoordinateDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestGameDriverImpl final : public GT::GTL::GameDriver {
    mutable unsigned int createdStrategicGames;
    mutable unsigned int createdExtensiveGames;
    mutable unsigned int createdDetails;
    mutable unsigned int createdPlayers;

public:
    TestGameDriverImpl();

    virtual GT::GTL::GamePtr* createStrategic(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::DetailsPtr*    details
    ) const override;

    virtual GT::GTL::GamePtr* createExtensive(
        const GT::GTL::InputLocation& inputLocation,
        const GT::GTL::DetailsPtr*    details
    ) const override;

    virtual GT::GTL::DetailsPtr* createDetails(
        const GT::GTL::InputLocation&  inputLocation,
        const GT::GTL::ObjectsPtr*     players,
        const GT::GTL::CoordinatesPtr* data
    ) const override;

    virtual GT::GTL::PlayerPtr* createPlayer(
        const GT::GTL::InputLocation& inputLocation,
        const GT::IdentifierPtr*      player,
        const GT::IdentifiersPtr*     strategies
    ) const override;

    inline unsigned int getCreatedStrategicGames() const;

    inline unsigned int getCreatedExtensiveGames() const;

    inline unsigned int getCreatedDetails() const;

    inline unsigned int getCreatedPlayers() const;

    virtual GT::Message toString() const override;
}; /* END class TestGameDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestStatementDriverImpl final : public GT::GTL::StatementDriver {
    mutable unsigned int executedDefinitions;
    mutable unsigned int executedQueries;

public:
    TestStatementDriverImpl();

    virtual bool executeDefinition(
        const GT::GTL::DefinitionPtr* definition
    ) override;

    virtual bool executeQuery(
        const GT::GTL::QueryPtr* query
    ) override;

    virtual GT::GTL::DefinitionPtr* createDefinition(
        const GT::GTL::InputLocation& inputLocation,
        const GT::IdentifierPtr*      identifier,
        const GT::GTL::ObjectPtr*     object
    ) const;

    virtual GT::GTL::QueryPtr* createQuery(
        const GT::GTL::InputLocation& inputLocation,
        const GT::IdentifiersPtr*     identifiers,
        const GT::GTL::ObjectsPtr*    objects,
        const GT::GTL::ConditionsPtr* conditions
    ) const;

    inline unsigned int getExecutedDefinitions() const;

    inline unsigned int getExecutedQueries() const;

    virtual GT::Message toString() const override;
}; /* END class TestStatementDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestValueDriverImpl final : public GT::GTL::ValueDriver {
    mutable unsigned int usedParameters;

public:
    TestValueDriverImpl();

    virtual GT::GTL::ParamPtr* get(
        const GT::GTL::InputLocation& inputLocation,
        const GT::IdentifierPtr*      identifier
    ) const override;

    virtual GT::GTL::ParamPtr* get(
        const GT::GTL::InputLocation& inputLocation,
        const GT::NumberPtr*          number
    ) const override;

    virtual GT::GTL::ObjectPtr* toObject(
        const GT::GTL::GamePtr*
    ) const override;

    virtual GT::GTL::ObjectPtr* toObject(
        const GT::GTL::PlayerPtr*
    ) const override;

    virtual GT::GTL::ObjectPtr* toObject(
        const GT::GTL::ParamPtr*
    ) const override;

    inline unsigned int getUsedParameters() const;

    virtual GT::Message toString() const override;
}; /* END class TestValueDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class TestDriverImpl final : public GT::GTL::Driver {
    mutable unsigned int shownResults;
    mutable unsigned int shownErrors;

public:
    mutable TestCoordinateDriverImpl                       coordinate;
    mutable TestCollectionsDriverImpl<GT::GTL::Coordinate> coordinates;
    mutable TestConditionDriverImpl                        condition;
    mutable TestCollectionsDriverImpl<GT::GTL::Condition>  conditions;
    mutable TestGameDriverImpl                             game;
    mutable TestCollectionsDriverImpl<GT::Identifier>      identifiers;
    mutable TestCollectionsDriverImpl<GT::GTL::Object>     objects;
    mutable TestCollectionsDriverImpl<GT::GTL::Param>      params;
    mutable TestValueDriverImpl                            value;
    mutable TestStatementDriverImpl                        statement;

    TestDriverImpl();

    virtual GT::GTL::CoordinateDriver& forCoordinate() const override;

    virtual GT::GTL::CollectionsDriver<GT::GTL::Coordinate>& forCoordinates() const override;

    virtual GT::GTL::ConditionDriver& forCondition() const override;

    virtual GT::GTL::CollectionsDriver<GT::GTL::Condition>& forConditions() const override;

    virtual GT::GTL::GameDriver& forGame() const override;

    virtual GT::GTL::CollectionsDriver<GT::Identifier>& forIdentifiers() const override;

    virtual GT::GTL::CollectionsDriver<GT::GTL::Object>& forObjects() const override;

    virtual GT::GTL::CollectionsDriver<GT::GTL::Param>& forParams() const override;

    virtual GT::GTL::ValueDriver& forValue() const override;

    virtual GT::GTL::StatementDriver& forStatement() const override;

    virtual void showResult(
        const GT::GTL::ResultPtr result
    ) const override;

    virtual void showError(
        const GT::GTL::InputLocation&,
        const GT::Message&
    ) const override;

    virtual void showError(
        const GT::GTL::ValidableSymbol&
    ) const override;

    inline unsigned int getShownResults() const;

    inline unsigned int getShownErrors() const;

    virtual GT::Message toString() const override;
}; /* END class TestDriverImpl */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/test_parser_helpers.tpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/test_parser_helpers.ipp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* END #ifndef __GT_GTL_TEST_PARSER_HELPERS_HPP__ */
