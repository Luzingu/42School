/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:54:27 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/13 10:54:29 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    int i;

    Zombie *zombieHorde;
    zombieHorde = new Zombie[N]; 
    i = 0;
    while (i < N)
    {
        zombieHorde[i] = Zombie(name);
        i++;
    }
    return (zombieHorde);
}
