#ifndef __GT_GTL_COLLECTIONS_DRIVER_HPP__
#define __GT_GTL_COLLECTIONS_DRIVER_HPP__

namespace GT {
namespace GTL {

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Used for handling collections via Driver.
 *
 * @author Mateusz Kubuszok
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
    virtual CollectionPtr* empty() = 0;

    /**
     * @brief Creates a collection with one element.
     *
     * @param element element to add
     * @return        pointer to collection
     */
    virtual CollectionPtr* create(
        ContentPtr* element
    ) = 0;

    /**
     * @brief Adds an element to the collection.
     *
     * @param element element to add
     * @return        pointer to collection
     */
    virtual CollectionPtr* insert(
        ContentPtr*    element,
        CollectionPtr* collection
    ) = 0;

    /**
     * @brief CollectionsDriver message.
     *
     * @return message
     */
    virtual Message toString() = 0;
}; /* END class CollectionsDriver*/

////////////////////////////////////////////////////////////////////////////////

#include "gt/gtl/collections_driver.tpp"

////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Null CollectionsDriver for handling invalid situations.
 *
 * @author Mateusz Kubuszok
 */
template <typename Content>
class NullCollectionsDriver : public CollectionsDriver<Content> {
public:
    NullCollectionsDriver() {}

    virtual typename CollectionsDriver<Content>::CollectionPtr* empty() {
        return new typename CollectionsDriver<Content>::CollectionPtr(
            new typename CollectionsDriver<Content>::Collection()
        );
    }

    virtual typename CollectionsDriver<Content>::CollectionPtr* create(
        typename CollectionsDriver<Content>::ContentPtr*
    ) {
        return empty();
    }

    virtual typename CollectionsDriver<Content>::CollectionPtr* insert(
        typename CollectionsDriver<Content>::ContentPtr*,
        typename CollectionsDriver<Content>::CollectionPtr* collection
    ) {
        return new typename CollectionsDriver<Content>::CollectionPtr(*collection);
    }

    virtual bool isNotNull() {
        return false;
    }

    virtual Message toString() {
        return Message("NullCollectionsDriver");
    }
}; /* END class NullCollectionsDriver */

////////////////////////////////////////////////////////////////////////////////

} /* END namespace GTL */
} /* END namespace GT */

#endif /* END #ifndef __GT_GTL_COLLECTIONS_DRIVER_HPP__ */
