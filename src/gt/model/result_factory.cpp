#include <boost/thread/mutex.hpp>

#include "gt/model/common.hpp"

namespace GT {
namespace Model {
    
////////////////////////////////////////////////////////////////////////////////

boost::mutex resultFactoryMutex;

////////////////////////////////////////////////////////////////////////////////

class ConstResult : public Result {
    Message result;

public:
    ConstResult(
        const Message& content
    ) :
        result(content)
        {}

    Message getResult() {
        return result;
    }
}; /* END class ConstResult */

////////////////////////////////////////////////////////////////////////////////

class EmptyResult : public Result {
public:
    EmptyResult() {}

    Message getResult() {
        return Message("");
    }
}; /* END class EmptyString */

////////////////////////////////////////////////////////////////////////////////

class AbstractResultBuilder : public ResultBuilder {
    typedef std::pair<Identifier, Messages>         PartialResult;
    typedef boost::container::vector<PartialResult> PartialResults;

    Identifiers    properties;
    PartialResults partialResults;

public:
    AbstractResultBuilder() :
        properties(),
        partialResults()
        {}

    virtual ResultBuilder& setHeaders(
        Identifiers& newProperties
    ) {
        properties = newProperties;
        return *this;
    }

    virtual ResultBuilder& addRecord(
        Identifier& object,
        Messages&   results
    ) {
        PartialResult partialResult = std::make_pair(object, results);
        return *this;
    }

    virtual ResultPtr build() = 0;

    virtual Message toString() {
        return (*build()).getResult();
    }
}; /* END class AbstractResultBuilder */

////////////////////////////////////////////////////////////////////////////////

// class ResultFactory {
ResultFactory* volatile ResultFactory::instance = 0;

// public:
ResultFactory& ResultFactory::getInstance() {
    // Singleton implemented according to:
    // "C++ and the Perils of Double-Checked Locking"
    // but without executing constructor inside getInstance() method
    // since it's an eyesore. 
    if (!instance) {
        boost::mutex::scoped_lock lock(resultFactoryMutex);
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
    builderMode     = PLAIN;
    indentationMode = TABS;
}
// }

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */
