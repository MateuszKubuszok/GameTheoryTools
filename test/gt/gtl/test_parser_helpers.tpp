// class TestCollectionsDriverImpl  {
// public:

template<typename Content>
TestCollectionsDriverImpl<Content>::TestCollectionsDriverImpl() :
    GT::GTL::NullCollectionsDriver<Content>(),
    createdCollections(0),
    addedElements(0)
    {}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::empty() {
    createdCollections++;
    return GT::GTL::NullCollectionsDriver<Content>::empty();
}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::create(
    typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr* element
) {
    createdCollections++;
    addedElements++;
    return GT::GTL::NullCollectionsDriver<Content>::create(element);
}

template<typename Content>
typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::insert(
    typename GT::GTL::NullCollectionsDriver<Content>::ContentPtr*    element,
    typename GT::GTL::NullCollectionsDriver<Content>::CollectionPtr* collection
) {
    addedElements++;
    return GT::GTL::NullCollectionsDriver<Content>::insert(element, collection);
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getCreatedCollections() {
    return createdCollections;
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getAddedElements() {
    return addedElements;
}

// }
