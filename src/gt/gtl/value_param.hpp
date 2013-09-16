#ifndef __GT_GTL_VALUE_PARAM_HPP__
#define __GT_GTL_VALUE_PARAM_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class ValueParam : public virtual Param {
    NumberPtr value;

public:
    ValueParam(
        NumberPtr number
    );

    virtual ObjectPtr getObject(
        Context& context
    );

    virtual NumberPtr getValue(
        Context& context
    );

    virtual Message toString();
}; /* END class ValueParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_VALUE_PARAM_HPP__ */
