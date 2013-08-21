#include "gt/model/common.hpp"

namespace GT {
namespace Model {

class EmptyResult;
class ConstResult;

// class ResultFactory {
// public:
static ResultFactory& ResultFactory::getInstance() {
    if (!instance) {
        Lock lock;
        if (!instance) {
            ResultFactory* volatile tmp = new ResultFactory();
            instance = tmp;
        }
    }
    return (*instance);
}

Result& ResultFactory::constResult(
    const std::string &content
) {
    return new ConstResult(content);
}

Result& ResultFactory::emptyResult() {
    return new EmptyResult();
}

ResultBuilderMode ResultFactory::getBuilderMode() {
    return builderMode;
}

ResultFactory& ResultFactory::setBuilderMode(
    ResultBuilderMode newBuilderMode
) {
    builderMode = newBuilderMode;
    return this;
}

ResultIndentationMode ResultFactory::getIndentationMode() {
    return indentationMode;
}

ResultFactory& ResultFactory::setIndentationMode(
    ResultIndentationMode newIndentationMode
) {
    indentationMode = newIndentationMode;
    return this;
}

// private:
ResultFactory::ResultFactory() {
    builderMode = PLAIN;
    indentationMode = INDENTED;
}
// }

class EmptyResult : Result {
public:
    std::string& getResult() {
        return "";
    }
} /* END class EmptyString */

class ConstResult : Result {
public:
    ConstResult(const std::string &content) :
        result(content)
        {}

    ~ConstResult() {
        delete result;
    }

    std::string& getResult() {
        return result;
    }

private:
    const std::string &result; 
} /* END class ConstResult */

} /* END namespace Model */
} /* END namespace GT */
