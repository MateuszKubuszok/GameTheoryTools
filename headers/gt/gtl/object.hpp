#ifndef __GT_GTL_OBJECT_HPP__
#define __GT_GTL_OBJECT_HPP__ 1

#include <boost/container/map.hpp>

#include "gt/gtl/common.hpp"

namespace GT {
namespace GTL {

/* Class declarations */
class Object;
class ObjectProperty;
class ObjectKnownProperties;

/**
 * @brief Root of all objects used as a data in parsed by GTL.
 *
 * @author Mateusz Kubuszok
 */
class Object {
    /* Friends declarations */
    friend ObjectKnownProperties;

public:
    /**
     * @brief Object's constructor.
     * 
     * Initiates the properties' register.
     */
    Object() :
        registeredProperties();
        
    /**
     * @brief Object's destructor.
     *
     * Removes the properties' register.
     */
    virtual ~Object();

    /**
     * @brief Defines whether this Object's instance is a valid result.
     *
     * @return true if Object is a valid result 
     */
    virtual bool isValid();

    /**
     * @brief Whether Object responds to some property.
     *
     * @param  property property's name
     * @return          true if Object responds to such property 
     */
    bool respondsTo(
        Identifier &propertyName
    );

    /**
     * @brief Finds Objects' property and returns it as a result.
     *
     * @param  propertyName          property's name
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    Result& findProperty(
        Identifier &propertyName
    );

    /**
     * @brief Finds Objects' property for giver conditions and returns it as a result. 
     *
     * @param propertyName           property's name
     * @param conditions             conditions to consider
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    Result& findPropertyWithConditions(
        Identifier &propertyName,
        Conditions &conditions
    );

protected:
    /**
     * @brief Whether property is registered or not.
     *
     * @param propertyName name of a checked property
     * @return             true if property is registered
     */
    bool isPropertyRegistered(
        Identifier &propertyName
    );

    /**
     * @brief Obtains ObjectProperty by name under which it was registered.
     *
     * @param propertyName           name of a required property
     * @return                       required ObjectProperty
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    ObjectProperty getProperty(
        Identifier &propertyName
    );

    /**
     * @brief Registers property together with its name.
     *
     * @param propertyName property's name
     * @param property     property instance
     */
    void registerProperty(
        Identifier     &propertyName,
        ObjectProperty &property
    );

    /**
     * Used for queries without conditions.
     */
    static const Conditions &noConditions = new Conditions();

private:
    /**
     * @brief Map containing ObjectProperties bound to their name.
     */
    boost::containers::map<Identifier, ObjectProperty> registeredProperties;
} /* END class Object */

/**
 * @brief Root of all Object's properties that can be registered.
 *
 * @author Mateusz Kubuszok
 */
class ObjectProperty {
    /* Friends declarations */
    friend Object;

public:
    /**
     * @brief Finds results for given conditions.
     *
     * @param  conditions conditions to check
     * @result            search result
     */
    virtual Result& findForConditions(
        Conditions &conditions
    ) = 0;

protected:
    /**
     * @brief Constructor locked for all classes except Object (which can create it in its own constructor). 
     */
    ObjectProperty() {}
}

/**
 * @brief Lists all known properties of an Object.
 *
 * @author Mateusz Kubuszok
 */
class ObjectKnownProperties : ObjectProperty {
    /* Friends declarations */
    friend Object;

private:
    ObjectKnownProperties(Object &listedObject) :
        object(listedObject); // TODO: check whether this shit doesn't use copy constrictor by any chance

    const Object &object; 
}

} /* END namespace GTL */
} /* END namespace GT */
#endif /* END #ifndef __GTL_OBJECT_HPP__ */
