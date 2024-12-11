/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:56:15 by aluzingu          #+#    #+#             */
/*   Updated: 2024/12/11 14:56:17 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	Zombie::name = name;
	std::cout << "Zombie (" << name << ") created" << std::endl;
}

void Zombie::announce()
{
	std::cout << Zombie::name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie (" << name << ") destroyed" << std::endl;
}
