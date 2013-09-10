#ifndef __GT_GTL_DRIVER_HPP__
#define __GT_GTL_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class Driver : public virtual Root {
    CoordinateDriver              coordinate;
    CollectionsDriver<Coordinate> coordinates;
    ConditionDriver               condition;
    CollectionsDriver<Condition>  conditions;
    GameDriver                    game;
    CollectionsDriver<Identifier> identifiers;
    CollectionsDriver<Object>     objects;
    CollectionsDriver<Param>      params;
    ValueDriver                   value;

public:
    Driver();

    virtual ~Driver();

    virtual CoordinateDriver& forCoordinate();

    virtual CollectionsDriver<Coordinate>& forCoordinates();
    
    virtual ConditionDriver& forCondition();

    virtual CollectionsDriver<Condition>& forConditions();

    virtual GameDriver& forGame();
    
    virtual CollectionsDriver<Identifier>& forIdentifiers();
    
    virtual CollectionsDriver<Object>& forObjects();
    
    virtual CollectionsDriver<Param>& forParams();

    virtual ValueDriver& forValue();

    virtual void storeDefinedObject(
        const DefinitionPtr* definition
    );

    virtual void executeQuery(
        const QueryPtr* query
    );

    virtual DefinitionPtr* createDefinition(
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    );

    virtual QueryPtr* createQuery(
        const IdentifiersPtr* identifiers,
        const ObjectsPtr*     objects,
        const ConditionsPtr*  conditions
    );

    virtual void showError(
        const std::string& message
    );

    virtual Message toString();
}; /* END class Driver */

////////////////////////////////////////////////////////////////////////////////

class NullDriver : public Driver {
    NullCoordinateDriver              coordinate;
    NullCollectionsDriver<Coordinate> coordinates;
    NullConditionDriver               condition;
    NullCollectionsDriver<Condition>  conditions;
    NullGameDriver                    game;
    NullCollectionsDriver<Identifier> identifiers;
    NullCollectionsDriver<Object>     objects;
    NullCollectionsDriver<Param>      params;
    NullValueDriver                   value;

public:
    NullDriver() :
        Driver()
        {}

    virtual CoordinateDriver& forCoordinate() {
        return coordinate;
    }

    virtual CollectionsDriver<Coordinate>& forCoordinates() {
        return coordinates;
    }

    virtual ConditionDriver& forCondition() {
        return condition;
    }
    
    virtual CollectionsDriver<Condition>& forConditions() {
        return conditions;
    }

    virtual GameDriver& forGame() {
        return game;
    }
    
    virtual CollectionsDriver<Identifier>& forIdentifiers() {
        return identifiers;
    }
    
    virtual CollectionsDriver<Object>& forObjects() {
        return objects;
    }
    
    virtual CollectionsDriver<Param>& forParams() {
        return params;
    }

    virtual void storeDefinedObject(
        const DefinitionPtr* definition
    ) {}

    virtual void executeQuery(
        const QueryPtr* query
    ) {}

    virtual DefinitionPtr* createDefinition(
        const IdentifierPtr* identifier,
        const ObjectPtr*     object
    ) {
        return new DefinitionPtr(NullFactory::getInstance().createDefinition());
    }

    virtual QueryPtr* createQuery(
        const IdentifiersPtr* identifiers,
        const ObjectsPtr*     objects,
        const ConditionsPtr*  conditions
    ) {
        return new QueryPtr(NullFactory::getInstance().createQuery());
    }

    virtual void showError(
        const std::string& message
    ) {}

    virtual Message toString() {
        return Message("NullDriver");
    }
}; /* END class NullDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END __GT_GTL_DRIVER_HPP__ */
