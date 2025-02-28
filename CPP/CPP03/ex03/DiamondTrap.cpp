/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:12:26 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 10:43:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("defaultDT_clap_trap")
{
	this->name = "defaultDT";
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->atack_demage = FragTrap::atack_demage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	*this = copy;
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name): ClapTrap(_name + "_clap_trap")
{
	this->name = _name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->atack_demage = FragTrap::atack_demage;
	std::cout << "DiamondTrap Constructor for the name " << this->name << " called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Deconstructor for " << this->name << " called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src)
{
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->name = src.name + "_clap_trap";
	this->hit_points = src.hit_points;
	this->energy_points = src.energy_points;
	this->atack_demage = src.atack_demage;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "Hello i am a DiamondTrap named " << this->name <<
	" and i am originated from the ClapTrap named " << ClapTrap::name << "." <<
	std::endl;
}
