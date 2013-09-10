// class CollectionsDriver {
// public:

template<typename Content>
CollectionsDriver<Content>::CollectionsDriver() {}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::empty() {
	// TODO: realocate ptr to avoid object destruction
    return new CollectionsDriver<Content>::CollectionPtr(
        new CollectionsDriver<Content>::Collection()
    );
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::create(
    typename CollectionsDriver<Content>::ContentPtr* element
) {
	// TODO: realocate ptr to avoid object destruction
    CollectionsDriver<Content>::CollectionPtr* collection = empty();
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
typename CollectionsDriver<Content>::CollectionPtr* CollectionsDriver<Content>::insert(
    typename CollectionsDriver<Content>::ContentPtr*    element,
    typename CollectionsDriver<Content>::CollectionPtr* collection
) {
	// TODO: realocate ptr to avoid object destruction
    (*collection)->push_back(*element);
    return collection;
}

template<typename Content>
Message CollectionsDriver<Content>::toString() {
    return Message("CollectionsDriver");
}

// }
