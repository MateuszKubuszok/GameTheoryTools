#ifndef __GT_MODEL_JSON_RESULT_BUILDER_HPP__
#define __GT_MODEL_JSON_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class JSONResultBuilder : public AbstractResultBuilder {
public:
    JSONResultBuilder(
        Message indentation
    );

    virtual ResultPtr build();

    virtual ResultPtr buildRaw();
}; /* END class JSONResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_JSON_RESULT_BUILDER_HPP__ */
