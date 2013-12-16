// template<typename Content>
// class TestCollectionsDriverImpl final : public GT::GTL::CollectionsDriver<Content> {
// public:

template<typename Content>
TestCollectionsDriverImpl<Content>::TestCollectionsDriverImpl() :
    createdCollections(0),
    addedElements(0)
    {}

template<typename Content>
typename TestCollectionsDriverImpl<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::empty()
const {
    createdCollections++;
    return new typename TestCollectionsDriverImpl<Content>::CollectionPtr(
        new typename TestCollectionsDriverImpl<Content>::Collection()
    );
}

template<typename Content>
typename TestCollectionsDriverImpl<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::create(
    const typename TestCollectionsDriverImpl<Content>::ContentPtr*
) const {
    createdCollections++;
    addedElements++;
    return empty();
}

template<typename Content>
typename TestCollectionsDriverImpl<Content>::CollectionPtr* TestCollectionsDriverImpl<Content>::insert(
    const typename TestCollectionsDriverImpl<Content>::ContentPtr*,
    const typename TestCollectionsDriverImpl<Content>::CollectionPtr* collection
) const {
    addedElements++;
    return new typename TestCollectionsDriverImpl<Content>::CollectionPtr(*collection);
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getCreatedCollections() const {
    return createdCollections;
}

template<typename Content>
inline unsigned int TestCollectionsDriverImpl<Content>::getAddedElements() const {
    return addedElements;
}

template<typename Content>
GT::Message TestCollectionsDriverImpl<Content>::toString() const {
    return GT::Message("TestCollectionsDriver");
}

// }; /* END class TestCollectionsDriver */
