#ifndef __GT_GTL_COLLECTIONS_DRIVER_HPP__
#define __GT_GTL_COLLECTIONS_DRIVER_HPP__

namespace GT {
namespace GTL {

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling collections via Driver.
 *
 * <p>Used by Parser to create collections of ValidableSymbols and insert elements into them. On Parser's they
 * are used wverywhere where some ValidableSymbols can be listed with <pre>,</pre> character.</p>
 *
 * <p>Example of piece of code recognized by Parser:</p>
 *
 * <p><pre>
 * identifier1, identifier2, identifier3
 * </pre></p>
 *
 * @author Mateusz Kubuszok
 *
 * @see Driver
 * @see Parser
 */
template<typename Content>
class CollectionsDriver : public virtual Root {
public:
    /**
     * @brief Pointer to template type.
     */
    typedef typename boost::shared_ptr<Content> ContentPtr;

    /**
     * @brief Collection of pointers.
     */
    typedef typename boost::container::vector<ContentPtr> Collection;

    /**
     * @brief Poiter to collection.
     */
    typedef typename boost::shared_ptr<Collection> CollectionPtr;

    /**
     * @brief Creates an empty collection.
     *
     * @return pointer to collection
     */
    virtual CollectionPtr* empty() const;

    /**
     * @brief Creates a collection with one element.
     *
     * @param element element to add
     * @return        pointer to collection
     */
    virtual CollectionPtr* create(
        const ContentPtr* element
    ) const;

    /**
     * @brief Adds an element to the collection.
     *
     * @param element    element to add
     * @param collection collection to increase
     * @return           pointer to collection
     */
    virtual CollectionPtr* insert(
        const ContentPtr*    element,
        const CollectionPtr* collection
    ) const;

    /**
     * @brief CollectionsDriver message.
     *
     * @return message
     */
    virtual Message toString() const override;
}; /* END class CollectionsDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/collections_driver.tpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null CollectionsDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
template <typename Content>
class NullCollectionsDriver final : public CollectionsDriver<Content> {
public:
    NullCollectionsDriver() {}

    virtual typename CollectionsDriver<Content>::CollectionPtr* empty() const override {
        return new typename CollectionsDriver<Content>::CollectionPtr(
            new typename CollectionsDriver<Content>::Collection()
        );
    }

    virtual typename CollectionsDriver<Content>::CollectionPtr* create(
        const typename CollectionsDriver<Content>::ContentPtr*
    ) const override {
        return empty();
    }

    virtual typename CollectionsDriver<Content>::CollectionPtr* insert(
        const typename CollectionsDriver<Content>::ContentPtr*,
        const typename CollectionsDriver<Content>::CollectionPtr* collection
    ) const override {
        return new typename CollectionsDriver<Content>::CollectionPtr(*collection);
    }

    virtual bool isNotNull() const override {
        return false;
    }

    virtual Message toString() const override {
        return Message("NullCollectionsDriver");
    }
}; /* END class NullCollectionsDriver */

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COLLECTIONS_DRIVER_HPP__ */
