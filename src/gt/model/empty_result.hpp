#ifndef __GT_MODEL_EMPTY_RESULT_HPP__
#define __GT_MODEL_EMPTY_RESULT_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains empty Message.
 *
 * <p>Implements Result interface.</p>
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
    virtual Message getResult() const override;
}; /* END class EmptyString */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_EMPTY_RESULT_HPP__ */
