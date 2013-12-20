#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {

ResultFactory& ResultFactory::getInstance() {
    static ResultFactory instance;
    return instance;
}

// public:

ResultBuilderPtr ResultFactory::buildResult() const {
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
) const {
    return ResultPtr(new ConstResult(content));
}

ResultPtr ResultFactory::emptyResult() const {
    return ResultPtr(new EmptyResult());
}

ResultBuilderMode ResultFactory::getBuilderMode() const {
    return builderMode;
}

ResultFactory& ResultFactory::setBuilderMode(
    const ResultBuilderMode newBuilderMode
) {
    builderMode = newBuilderMode;
    return *this;
}

ResultIndentationMode ResultFactory::getIndentationMode() const {
    return indentationMode;
}

ResultFactory& ResultFactory::setIndentationMode(
    const ResultIndentationMode newIndentationMode
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

// }; /* END class ResultFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
