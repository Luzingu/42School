/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:59 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 13:32:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string _name): name(_name), weapon(NULL)
{

}
	
HumanB::~HumanB()
{

}

void HumanB::setWeapon(Weapon &_weapon)
{
	this->weapon = &_weapon;
}

void HumanB::attack()
{

	if (this->weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with no weapon " << std::endl;
}