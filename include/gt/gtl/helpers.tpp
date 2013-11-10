template<typename Symbol>
boost::shared_ptr<Symbol> setupLocation(
    boost::shared_ptr<Symbol> symbol,
    const InputLocation&      inputLocation
) {
    symbol->setInputLocation(InputLocationPtr(new InputLocation(inputLocation)));
    return symbol;
}
