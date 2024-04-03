#ifndef PLAYABLECHARA_HPP
#define PLAYABLECHARA_HPP

#include <string>
#include "Inventory.hpp"
#include "Item.hpp"
#include "Date.hpp"

typedef unsigned int dVal;

class PlayableChara
{
	private:
		std::string _origin;
		std::string _name;
		Date birth;
		Item* _equipped;
		Inventory* _inventory;
	public:
		PlayableChara(void);
		PlayableChara(std::string origin, std::string name, dVal bYear, dVal bMonth, dVal bDay);
		~PlayableChara(void);
};

#endif