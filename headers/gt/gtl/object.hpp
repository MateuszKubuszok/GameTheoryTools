#ifndef __GT_GTL_OBJECT_HPP__
#define __GT_GTL_OBJECT_HPP__

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
        const Identifier& propertyName
    );

    /**
     * @brief Finds Objects' property and returns it as a result.
     *
     * @param  context               context with values
     * @param  propertyName          property's name
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    Result findProperty(
        const Context&    context,
        const Identifier& propertyName
    );

    /**
     * @brief Finds Objects' property for giver conditions and returns it as a result. 
     *
     * @param context                context with values
     * @param conditions             conditions to consider
     * @return                       Result for sought property
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    Result findPropertyWithConditions(
        const Context&    context,
        const Identifier& propertyName,
        const Conditions& conditions
    );

protected:
    /**
     * @brief Used for queries without conditions.
     */
    static const Conditions noConditions = Conditions();

    /**
     * @brief Whether property is registered or not.
     *
     * @param propertyName name of a checked property
     * @return             true if property is registered
     */
    bool isPropertyRegistered(
        const Identifier& propertyName
    );

    /**
     * @brief Obtains ObjectProperty by name under which it was registered.
     *
     * @param propertyName           name of a required property
     * @return                       required ObjectProperty
     * @throws std::invalid_argument thrown when property is not available for an Object
     */
    ObjectProperty getProperty(
        const Identifier& propertyName
    );

    /**
     * @brief Registers property together with its name.
     *
     * @param propertyName property's name
     * @param property     property instance
     */
    void registerProperty(
        const Identifier&     propertyName,
        const ObjectProperty& property
    );

private:
    /**
     * @brief Map containing ObjectProperties bound to their name.
     */
    const boost::container::map<Identifier, ObjectProperty> registeredProperties;
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
     * @param  context    contxt with values
     * @param  conditions conditions to check
     * @result            search result
     */
    virtual Result findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) = 0;

protected:
    /**
     * @brief Constructor locked for all classes except Object (which can create it in its own constructor). 
     */
    ObjectProperty() {}
} /* END class ObjectProperty */

/**
 * @brief Lists all known properties of an Object.
 *
 * @author Mateusz Kubuszok
 */
class ObjectKnownProperties : ObjectProperty {
    /* Friends declarations */
    friend Object;

private:
    const Object object;

    ObjectKnownProperties(
        const Object& listedObject
    ) :
        object(listedObject);
} /* END class ObjectKnownProperties */

} /* END namespace GTL */
} /* END namespace GT */
#endif /* END #ifndef __GTL_OBJECT_HPP__ */
