#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->atack_demage = 20;
	this->guarding_gate= false;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name): ClapTrap(_name)
{
	this->guarding_gate= false;
	std::cout << "ScavTrap Constructor for the name " << this->name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src):ClapTrap(src)
{
	this->guarding_gate= src.guarding_gate;
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Deconstructor for " << this->name << " called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
	ClapTrap::operator=(src);
	std::cout << "ScavTrap Copy Constructor called" << std::endl;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->atack_demage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ScavTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (this->guarding_gate == false)
	{
		this->guarding_gate = true;
		std::cout << "ScavTrap " << this->name << " is now guarding the gate." << std::endl;
	}
	else
		std::cout << "ScavTrap " << this->name << " is already guarding the gate." << std::endl;
}
