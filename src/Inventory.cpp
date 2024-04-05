#include "../includes/Inventory.hpp"
#include <algorithm>

Inventory::Inventory(void) { }

Inventory::~Inventory(void) { }

Inventory::Inventory(const Inventory& copy): _inventory(copy._inventory) { }

Inventory& Inventory::operator=(const Inventory& copy)
{
	if (this != &copy)
	{
		_inventory = copy._inventory;
	}
	return (*this);
}

/**
 * @return pointer to Item object located at _inventory[index]
 * @throw Inventory::OutOfBoundsException() when index is bigger than the size of the list
*/
Item& Inventory::operator[](size_t index)
{
	if (index >= _inventory.size())
		throw Inventory::OutOfBoundsException();
	return (*_inventory[index]);
}

/**
 * @return constant pointer to Item object located at _inventory[index]
 * @throw Inventory::OutOfBoundsException() when index is bigger than the size of the list
*/
const Item& Inventory::operator[](size_t index) const
{
	if (index >= _inventory.size())
		throw Inventory::OutOfBoundsException();
	return (*_inventory[index]);
}

/**
 * @throw UniqueItemException() when trying to add an item that is already in the list
*/
void Inventory::push_back(Item* value)
{
	if (std::find(_inventory.begin(), _inventory.end(), value) != _inventory.end())
		throw UniqueItemException();
	_inventory.push_back(value);
}