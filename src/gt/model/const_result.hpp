#ifndef __GT_MODEL_CONST_RESULT_HPP__
#define __GT_MODEL_CONST_RESULT_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

class ConstResult : public Result {
    Message result;

public:
    ConstResult(
        const Message& content
    );

    Message getResult();
}; /* END class ConstResult */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_CONST_RESULT_HPP__ */
