// template<typename Content>
// class TestCollectionsDriverImpl : public GT::GTL::NullCollectionsDriver<Content> {
// public:

template<typename Content>
TestCollectionsDriverImpl<Content>::TestCollectionsDriverImpl() :
    GT::GTL::NullCollectionsDriver<Content>(),
    createdCollections(0),
    addedElements(0)
    {}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::empty()
const {
    createdCollections++;
    return GT::GTL::NullCollectionsDriver<Content>::empty();
}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::create(
    const typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr* element
) const {
    createdCollections++;
    addedElements++;
    return GT::GTL::NullCollectionsDriver<Content>::create(element);
}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::insert(
    const typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr*    element,
    const typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* collection
) const {
    addedElements++;
    return GT::GTL::NullCollectionsDriver<Content>::insert(element, collection);
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getCreatedCollections() const {
    return createdCollections;
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getAddedElements() const {
    return addedElements;
}

// }; /* END class TestCollectionsDriver */
