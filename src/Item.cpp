#include "../includes/Item.hpp"

Item::Item(void): _name("placeholder"), _symbol("") { }

Item::Item(const std::string name, const std::string symbol): _name(name), _symbol(symbol) { }

Item::Item(const Item& copy): _name(copy._name), _symbol(copy._symbol) { }

Item::~Item(void) { }

Item& Item::operator=(const Item& copy)
{
	if (this != &copy)
	{
		_name = copy._name;
		_symbol = copy._symbol;
	}
	return (*this);
}

std::string Item::getName(void) const {return (_name);}

std::string Item::getSymbol(void) const {return (_symbol);}

void Item::setName(const std::string& name) {_name = name;}

void Item::setSymbol(const std::string& symbol) {_symbol = symbol;}