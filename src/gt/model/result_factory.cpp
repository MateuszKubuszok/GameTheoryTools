#include "gt/model/inner_common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex resultFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {

ResultFactory* volatile ResultFactory::instance = 0;

// public:

ResultFactory& ResultFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking".
    if (!instance) {
        boost::mutex::scoped_lock lock(resultFactoryMutex);
        if (!instance) {
            ResultFactory* volatile tmp = (ResultFactory*) malloc(sizeof(ResultFactory));
            new (tmp) ResultFactory; // placement new
            instance = tmp;
        }
    }
    return *instance;
}

ResultBuilderPtr ResultFactory::buildResult() {
    Message indent;
    switch (indentationMode) {
    case TABS:
        indent = Message("\t");
        break;
    case SPACES:
        indent = Message(" ");
    case NONE:
    default:
        break;
    }

    switch (builderMode) {
    case JSON:
        return ResultBuilderPtr(new JSONResultBuilder(indent));
    case XML:
        return ResultBuilderPtr(new XMLResultBuilder(indent));
    case PLAIN:
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
    builderMode     = PLAIN;
    indentationMode = TABS;
}

// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
