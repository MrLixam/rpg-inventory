#ifndef INVENTORY_HPP
#define INVENTORY_HPP
#include <string>
#include <vector>
#include "Item.hpp"

class Inventory
{
	private:
		std::vector<Item *> _inventory;
	public:
		Inventory(void);
		Inventory(const Inventory& copy);
		~Inventory(void);
		Inventory& operator=(const Inventory& copy);
		Item& operator[](size_t index);
		const Item& operator[](size_t index) const;
		void print(void) const;

		typedef typename std::vector<Item *>::iterator iterator;
		iterator begin(void) { return _inventory.begin();};
		iterator end(void) {return _inventory.end();};

		typedef typename std::vector<Item *>::const_iterator const_iterator;
		const_iterator cbegin(void) const {return _inventory.begin();};
		const_iterator cend(void) const {return _inventory.end();};

		typedef typename std::vector<Item *>::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(void) {return _inventory.rbegin();};
		reverse_iterator rend(void) {return _inventory.rend();};

		typedef typename std::vector<Item *>::const_reverse_iterator const_reverse_iterator;
		reverse_iterator crbegin(void) const {return _inventory.rbegin();};
		reverse_iterator crend(void) const {return _inventory.rend();};

		void push_back(Item* value);
		std::vector<Item *>::size_type size(void) const {return _inventory.size();};

		class OutOfBoundsException: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Index out of bounds");
			}
		};
		class UniqueItemException: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("Item already in inventory");
			}
		};
};

#endif
