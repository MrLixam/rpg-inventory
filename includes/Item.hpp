#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item
{
	private:
		std::string _name;
		std::string symbol;
		bool _isWeapon;
	public:
		Item(void);
		~Item(void);
		Item(const std::string name);
		Item(const Item& copy);
		Item& operator=(const Item& copy);
		std::string getName(void);
		void setName(const std::string& name);
};

#endif