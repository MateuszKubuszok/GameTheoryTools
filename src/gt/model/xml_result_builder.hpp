#ifndef __GT_MODEL_XML_RESULT_BUILDER_HPP__
#define __GT_MODEL_XML_RESULT_BUILDER_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class XMLResultBuilder : public AbstractResultBuilder {
public:
    XMLResultBuilder(
        Message indentation
    );

    virtual ResultPtr build();

    virtual ResultPtr buildRaw();
}; /* END class XMLResultBuilder */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_XML_RESULT_BUILDER_HPP__ */
