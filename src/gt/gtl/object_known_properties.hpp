#ifndef __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__
#define __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Describes Object's known properties.
 *
 * @author Mateusz Kubuszok
 *
 * @see Object
 */
class ObjectKnownProperties : public ObjectProperty {
    /**
     * @brief Described Object.
     */
    Object* object;

public:
    /**
     * @brief Initiates Property with Object it's describing.
     *
     * @param describedObject described Object
     */
    ObjectKnownProperties(
        Object* describedObject
    );

    /**
     * @brief Finds Object's known propertes.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ObjectKnownProperties */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__ */
