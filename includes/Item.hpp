#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>
#include "PlayableChara.hpp"

/**
 * A simple Interface for items
 * not meant to be instanciated alone, it won't do anything
*/
class Item
{
	protected:
		std::string _name;
		std::string _symbol;
	public:
		Item(void);
		virtual ~Item(void);
		Item(const std::string name, const std::string symbol);
		Item(const Item& copy);
		Item& operator=(const Item& copy);
		
		std::string getName(void) const;
		std::string getSymbol(void) const;

		void setName(const std::string& name);
		void setSymbol(const std::string& symbol);
};

#endif