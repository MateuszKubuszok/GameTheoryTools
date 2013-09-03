#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex resultFactoryMutex;

class EmptyResult;
class ConstResult;

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
ResultFactory ResultFactory::instance = 0;

// public:
static ResultFactory& ResultFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock;
        if (!instance) {
            ResultFactory* volatile tmp = new ResultFactory();
            instance = tmp;
        }
    }
    return *instance;
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
    builderMode = PLAIN;
    indentationMode = INDENTED;
}
// }

////////////////////////////////////////////////////////////////////////////////

class EmptyResult : public Result {
public:
    std::string getResult() {
        return "";
    }
} /* END class EmptyString */

////////////////////////////////////////////////////////////////////////////////

class ConstResult : public Result {
public:
    ConstResult(const std::string &content) :
        result(content)
        {}

    ~ConstResult() {
        delete result;
    }

    std::string getResult() {
        return result;
    }

private:
    const std::string result; 
} /* END class ConstResult */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
