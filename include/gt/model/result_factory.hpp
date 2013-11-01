#ifndef __GT_MODEL_RESULT_FACTORY_HPP__
#define __GT_MODEL_RESULT_FACTORY_HPP__

namespace GT {
namespace Model {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for configuring what kind of builders should be returned by ResultFactory.
 *
 * @author Mateusz Kubuszok
 */
enum class ResultBuilderMode { PLAIN, JSON, XML };

/**
 * @brief Used for configuring whether builders returned by ResultFacotry should use indentation and how.
 *
 * @author Mateusz Kubuszok
 */
enum class ResultIndentationMode { TABS, SPACES, NONE };

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Creates some simple Results as well as supplies builders for more complex of them.
 *
 * <p>The type of ResultBuilder returned by factory is determined by builderMode settings.</p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Result
 * @see ResultBuilder
 */
class ResultFactory {
    SINGLETON_DECLARATION(ResultFactory)

    /**
     * @brief Contains current Builder Mode setting.
     */
    ResultBuilderMode builderMode;

     /**
     * @brief Contains current Indentation Mode setting.
     */
    ResultIndentationMode indentationMode;

public:
    /**
     * @brief Returns the instance of a ResultFactory.
     *
     * @return ResultFactory instance
     */
    static ResultFactory& getInstance();

    /**
     * @brief Returns ResultBuilder.
     *
     * @return ResultBuilder
     */
    ResultBuilderPtr buildResult();

    /**
     * @brief Returns Results with predefined const content.
     *
     * @param content content to be contained by the Result
     * @return        Result with constant content
     */
    ResultPtr constResult(
        const Message& content
    );

    /**
     * @brief Returns empty Result.
     *
     * @return an empty result
     */
    ResultPtr emptyResult();

    /**
     * @brief Returns current builder mode.
     *
     * @return currently used builder mode
     */
    ResultBuilderMode getBuilderMode();

    /**
     * @brief Sets current builder mode.
     *
     * @param  builderMode new builder mode
     * @return             ResultsFactory for chaining
     */
    ResultFactory& setBuilderMode(
        const ResultBuilderMode builderMode
    );

    /**
     * @brief Returns current indentation mode.
     *
     * @return currently used indentation mode
     */
    ResultIndentationMode getIndentationMode();

     /**
     * @brief Sets current indentation mode.
     *
     * @param  indentationMode new indentation mode
     * @return                 ResultsFactory for chaining
     */
    ResultFactory& setIndentationMode(
        const ResultIndentationMode indentationMode
    );

private:
    /**
     * @brief Private constructor.
     */
    ResultFactory();

    /**
     * @brief Private copy constructor.
     */
    ResultFactory(
        const ResultFactory& resultFactory
    );

    /**
     * @brief Private destructor.
     */
    ~ResultFactory();
}; /* END class ResultFactory */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace Model */
} /* END namespace GT */

#endif /* END #ifndef __GT_MODEL_RESULT_FACTORY_HPP__ */
