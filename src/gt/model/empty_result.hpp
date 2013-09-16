#ifndef __GT_MODEL_EMPTY_RESULT_HPP__
#define __GT_MODEL_EMPTY_RESULT_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class EmptyResult : public Result {
public:
    EmptyResult();

    Message getResult();
}; /* END class EmptyString */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EMPTY_RESULT_HPP__ */
