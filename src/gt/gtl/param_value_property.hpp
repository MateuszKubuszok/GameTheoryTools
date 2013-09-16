#ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__
#define __GT_GTL_PARAM_VALUE_PROPERTY_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ParamValueProperty : public ObjectProperty {
    Param* param;
    
public: 
    ParamValueProperty(
        Param* owner
    );
 
    virtual ResultPtr findForConditions(
        const Context&    context,
        const Conditions& conditions
    );
}; /* END class ParamTypeProperty */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_PARAM_VALUE_PROPERTY_HPP__ */
