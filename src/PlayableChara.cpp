#include "../includes/PlayableChara.hpp"
#include <iostream>

PlayableChara::PlayableChara(void): _origin("unknown"), _name("John Smith"), birth(), _equipped(nullptr) {}

PlayableChara::PlayableChara(std::string origin, std::string name, dVal bYear, dVal bMonth, dVal bDay): _origin(origin), _name(name), _equipped(nullptr)
{
	try
	{
		birth = Date(bYear, bMonth, bDay);
	}
	catch (std::exception& e)
	{
		std::cerr << "invalid birth date: " << e.what() << std::endl;
	}
}