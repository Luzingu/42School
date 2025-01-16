/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:45 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/13 10:53:49 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
    Zombie::name = name;
    std::cout << "Zombie (" << name << ") created" << std::endl;
}

Zombie::Zombie()
{
    
}

Zombie::~Zombie()
{
    std::cout << "Zombie (" << Zombie::name << ") destroyed" << std::endl;
}

void Zombie::announce()
{
    std::cout << Zombie::name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
