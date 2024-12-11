/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:05:07 by aluzingu          #+#    #+#             */
/*   Updated: 2024/12/11 15:05:08 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *newZombie;
	newZombie = new Zombie("New Zombie");
	newZombie->announce();
	randomChump("Rando Zombie");
	delete newZombie;
	return (0);
}
