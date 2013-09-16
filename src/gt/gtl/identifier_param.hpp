#ifndef __GT_GTL_IDENTIFIER_PARAM_HPP__
#define __GT_GTL_IDENTIFIER_PARAM_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

class IdentifierParam : public virtual Param {
    Identifier identifier;

public:
    IdentifierParam(
        Identifier& id
    );

    virtual ObjectPtr getObject(
        Context& context
    );

    virtual NumberPtr getValue(
        Context& context
    );

    virtual Message toString();
}; /* END class IdentifierParam */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* #ifndef __GT_GTL_IDENTIFIER_PARAM_HPP__ */
