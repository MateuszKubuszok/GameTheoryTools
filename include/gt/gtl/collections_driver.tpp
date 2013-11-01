// template<typename Content>
// class CollectionsDriver : public virtual Root {
// public:

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::empty() {
    return new CollectionsDriver<Content>::CollectionPtr(
        new CollectionsDriver<Content>::Collection()
    );
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::create(
    typename CollectionsDriver<Content>::ContentPtr* element
) {
    CollectionsDriver<Content>::CollectionPtr* collection = empty();
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::insert(
    typename CollectionsDriver<Content>::ContentPtr*    element,
    typename CollectionsDriver<Content>::CollectionPtr* collection
) {
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
Message CollectionsDriver<Content>::toString() {
    return Message("CollectionsDriver");
}

// }; /* END class CollectionsDriver */
