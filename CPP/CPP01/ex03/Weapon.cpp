/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:31:04 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 13:31:06 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{

}

Weapon:: ~Weapon(void)
{
	
}

std::string Weapon::getType()
{
	return (Weapon::type);
}

void Weapon::setType(std::string _type)
{
	this->type = _type;
}