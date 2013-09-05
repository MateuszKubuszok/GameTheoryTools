#ifndef __GT_MODEL_RESULT_HPP__
#define __GT_MODEL_RESULT_HPP__

namespace GT {
namespace Model {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Root of all Resuts created by GTL parser.
 *
 * @author Mateusz Kubuszok
 */
class Result : public virtual Root {
public:
    /**
     * @brief Default destructor.
     */
    virtual ~Result() {}

    /**
     * @brief Returns Result in a form available to send on output stream.
     *
     * @return string with result
     */ 
    virtual Message getResult() = 0;

    /**
     * @brief Return message with results.
     *
     * @return Result as a Message
     */
    virtual Message toString() {
        return getResult();
    }
}; /* END class Result */

////////////////////////////////////////////////////////////////////////////////

class NullResult : public virtual Result {
public:
    virtual Message getResult() {
        return Message("NullResult");
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullResult");
    }
}; /* END class Result */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_HPP__ */
