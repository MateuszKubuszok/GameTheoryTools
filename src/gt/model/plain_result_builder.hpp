#ifndef __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__
#define __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class PlainResultBuilder : public AbstractResultBuilder {
public:
    PlainResultBuilder(
        Message indentation
    );

    virtual ResultPtr build();

    virtual ResultPtr buildRaw();
}; /* END class PlainResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_PLAIN_RESULT_BUILDER_HPP__ */
