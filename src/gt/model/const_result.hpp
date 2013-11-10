#ifndef __GT_MODEL_CONST_RpropertiesESULT_HPP__
#define __GT_MODEL_CONST_RESULT_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Contains const Result Message.
 *
 * <p>Implements Result interface.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see EmptyResult
 * @see ResultFactory
 */
class ConstResult : public Result {
    /**
     * @brief Result to return.
     */
    const Message result;

public:
    /**
     * @brief Initiates Result with a Message.
     *
     * @param content message that should be stored as a Result
     */
    explicit ConstResult(
        const Message& content
    );

    /**
     * Returns Result's Message.
     *
     * @return Results's Message
     */
    virtual Message getResult() const override;
}; /* END class ConstResult */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* #ifndef __GT_MODEL_CONST_RESULT_HPP__ */
