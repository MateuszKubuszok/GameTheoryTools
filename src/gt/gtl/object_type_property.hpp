#ifndef __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__
#define __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Describes Object's type.
 *
 * @author Mateusz Kubuszok
 *
 * @see Object
 */
class ObjectTypeProperty : public ObjectProperty {
    /**
     * @brief Described Object.
     */
    const Object* object;

public:
    /**
     * @brief Initiates Property with Object it's describing.
     *
     * @param describedObject described Object
     */
    explicit ObjectTypeProperty(
        const Object* describedObject
    );

    /**
     * @brief Finds Object's type.
     *
     * @param  context    Context with values
     * @param  conditions Conditions to check
     * @result            search Result
     */
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    ) const override;
}; /* END class ObjectTypeProperty */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__ */
