#ifndef __GT_GTL_RESULT_HPP__
#define __GT_GTL_RESULT_HPP__ 1

namespace GT {
namespace GTL {

class Result {
public:
    Result() {}

    virtual ~Result() {}

    virtual std::string getResult() = 0;
} /* END class Result */

} /* END namespace GTL */
} /* END namespace GT */
#endif /* END #ifndef __GT_GTL_RESULT_HPP__ */
