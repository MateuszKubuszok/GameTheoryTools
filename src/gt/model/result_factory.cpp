#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {

SINGLETON_DEFINITION(ResultFactory, getInstance, resultFactoryMutex)

// public:

ResultBuilderPtr ResultFactory::buildResult() {
    Message indent;
    switch (indentationMode) {
    case ResultIndentationMode::TABS:
        indent = Message("\t");
        break;
    case ResultIndentationMode::SPACES:
        indent = Message(" ");
    case ResultIndentationMode::NONE:
    default:
        break;
    }

    switch (builderMode) {
    case ResultBuilderMode::JSON:
        return ResultBuilderPtr(new JSONResultBuilder(indent));
    case ResultBuilderMode::XML:
        return ResultBuilderPtr(new XMLResultBuilder(indent));
    case ResultBuilderMode::PLAIN:
    default:
        return ResultBuilderPtr(new PlainResultBuilder(indent));
    }
}

ResultPtr ResultFactory::constResult(
    const Message& content
) {
    return ResultPtr(new ConstResult(content));
}

ResultPtr ResultFactory::emptyResult() {
    return ResultPtr(new EmptyResult());
}

ResultBuilderMode ResultFactory::getBuilderMode() {
    return builderMode;
}

ResultFactory& ResultFactory::setBuilderMode(
    ResultBuilderMode newBuilderMode
) {
    builderMode = newBuilderMode;
    return *this;
}

ResultIndentationMode ResultFactory::getIndentationMode() {
    return indentationMode;
}

ResultFactory& ResultFactory::setIndentationMode(
    ResultIndentationMode newIndentationMode
) {
    indentationMode = newIndentationMode;
    return *this;
}

// private:

ResultFactory::ResultFactory() {
    builderMode     = ResultBuilderMode::PLAIN;
    indentationMode = ResultIndentationMode::TABS;
}

ResultFactory::~ResultFactory() {}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
