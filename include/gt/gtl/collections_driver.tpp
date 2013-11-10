// template<typename Content>
// class CollectionsDriver : public virtual Root {
// public:

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::empty() const {
    return new CollectionsDriver<Content>::CollectionPtr(
        new CollectionsDriver<Content>::Collection()
    );
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::create(
    const typename CollectionsDriver<Content>::ContentPtr* element
) const {
    CollectionsDriver<Content>::CollectionPtr* collection = empty();
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::insert(
    const typename CollectionsDriver<Content>::ContentPtr*    element,
    const typename CollectionsDriver<Content>::CollectionPtr* collection
) const {
    (*collection)->push_back(*element);
    return new CollectionsDriver<Content>::CollectionPtr(
        *collection
    );
}

template<typename Content>
Message CollectionsDriver<Content>::toString() const {
    return Message("CollectionsDriver");
}

// }; /* END class CollectionsDriver */
