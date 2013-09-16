#ifndef __GT_GTL_PARAM_TYPE_PROPERTY_HPP__
#define __GT_GTL_PARAM_TYPE_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ParamTypeProperty : public ObjectProperty {
public:
    ParamTypeProperty();

    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ParamTypeProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_TYPE_PROPERTY_HPP__ */
