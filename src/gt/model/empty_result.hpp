#ifndef __GT_MODEL_EMPTY_RESULT_HPP__
#define __GT_MODEL_EMPTY_RESULT_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains empty Message.
 *
 * Implements Result interface.
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ConstResult
 * @see ResultFactory
 */
class EmptyResult : public Result {
public:
    /**
     * @brief Creates Result with empty Message.
     */
    EmptyResult();

    /**
     * Returns Result's Message.
     *
     * @return Results's Message
     */
    Message getResult();
}; /* END class EmptyString */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EMPTY_RESULT_HPP__ */
