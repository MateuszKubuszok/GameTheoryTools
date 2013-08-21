#ifndef __GTL_RESULT_HPP__
#define __GTL_RESULT_HPP__ 1

namespace GTL {

class Result {
public:
    Result() {}

    virtual ~Result() {}

    virtual std::string getResult() = 0;
} /* END class Result */

} /* END namespace GTL */
#endif /* END #ifndef __GTL_RESULT_HPP__ */
