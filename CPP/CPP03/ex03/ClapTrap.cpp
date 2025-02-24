/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:19 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/27 11:12:20 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), atack_demage(10)
{
	std::cout << "ClapTrap construct for the name " << name << " called." << std::endl;
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
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap Assignment operator called" << std::endl;
	if ( this != &other)
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
	if (this->energy_points > 0 && this->hit_points > 0)
	{
		std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->atack_demage << " points of damage!" << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has no energy points left." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " is not able to attack " << target << ", because he has not enough hit points." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points > amount)
		this->hit_points -= amount;
	else if (this->hit_points > 0)
		this->hit_points = 0;
	else
	{
		std::cout << "ClapTrap " << this->name << " is already dead, stop beating it." << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " was attacked and lost " << amount << " hit points, he now has " << this->hit_points << " hit points." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{ 
	if (this->energy_points > 0 && this->hit_points > 0 && (this->hit_points + amount) <= 10)
	{
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << " repaired itself and gained " << amount << " of hit points, he now has " << this->hit_points << "hit points." << std::endl;
		this->energy_points--;
	}
	else if (this->energy_points == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (this->hit_points == 0)
		std::cout << "ClapTrap " << this->name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " can't be repaired to have more than 10 hit points." << std::endl;
}
