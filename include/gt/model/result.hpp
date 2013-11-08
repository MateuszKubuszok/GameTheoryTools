#ifndef __GT_MODEL_RESULT_HPP__
#define __GT_MODEL_RESULT_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Root of all Results created by GTL parser.
 *
 * <p>Since all classes of GT (except factories, Numbers, Identifiers and Messages) extend this one,
 * they are guaranteed to have toSting() and isEqual(Root&) methods as well as <pre>==</pre>, <pre>!=</pre>
 * and <pre><<</pre> operators overloaded.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see ResultBuilder
 * @see ResultFactory
 */
class Result : public virtual Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Result();

    /**
     * @brief Returns Result in a form available to send on output stream.
     *
     * @return string with result
     */
    virtual Message getResult() = 0;

    /**
     * @brief Defines equality relation.
     *
     * @param root another root to compare
     * @return     true if roots are equal
     */
    virtual bool isEqual(
        Root& root
    ) override;

    /**
     * @brief Return message with results.
     *
     * @return Result as a Message
     */
    virtual Message toString() override;

    /**
     * @brief Syntax sugar for isEqual method.
     *
     * @param result1 first Result to compare
     * @param result2 second Result to compare
     * @return        true if Results are equal
     */
    friend bool operator==(
        ResultPtr& result1,
        ResultPtr& result2
    );

    /**
     * @brief Syntax sugar for !isEqual method.
     *
     * @param result1 first Result to compare
     * @param result2 second Result to compare
     * @return        true if Results are not equal
     */
    friend bool operator!=(
        ResultPtr& result1,
        ResultPtr& result2
    );

    /**
     * @brief Syntax sugar for toStream method.
     *
     * @param stream stream to concatenate
     * @param result Result to concatenate
     * @return       stream for chaining
     */
    friend OutputStream& operator<<(
        OutputStream& stream,
        ResultPtr&    result
    );
}; /* END class Result */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null Result for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
class NullResult : public virtual Result {
public:
    virtual Message getResult() override {
        return Message("NullResult");
    }

    virtual bool isNotNull() override {
        return false;
    }

    virtual Message toString() override {
        return Message("NullResult");
    }
}; /* END class NullResult */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_HPP__ */
