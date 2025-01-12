#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name): name(_name), hit_points(10), energy_points(10), atack_demage(10)
{
	std::cout << "ClapTrap construct for the name " << _name << " called." << std::endl;
}

ClapTrap::ClapTrap(): name("default"), hit_points(10), energy_points(10), atack_demage(10)
{
	std::cout << "ClapTrap default construct called." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destruct for the name " << this->name << " called." << std::endl;
}

ClapTrap::ClapTrap (const ClapTrap &other)
{
	std::cout << "ClapTrap copy construct" << std::endl;
	&this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	if ( this != other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->atack_demage = other.atack_demage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{

}

void	ClapTrap::takeDamage(unsigned int amount)
{

}

void	beRepaired(unsigned int amount)
{

}
