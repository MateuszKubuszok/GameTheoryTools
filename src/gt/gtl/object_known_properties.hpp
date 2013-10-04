#ifndef __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__
#define __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ObjectKnownProperties : public ObjectProperty {
    Object* object;

public:
    ObjectKnownProperties(
        Object* describedObject
    );

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ObjectKnownProperties */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_OBJECT_KNOWN_PROPERTIES_HPP__ */
