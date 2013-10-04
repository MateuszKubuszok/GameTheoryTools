#ifndef __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__
#define __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ObjectTypeProperty : public ObjectProperty {
    Object* object;

public:
    ObjectTypeProperty(
        Object* object
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ObjectTypeProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_TYPE_PROPERTY_HPP__ */
