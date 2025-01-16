/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:53:14 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/13 10:53:19 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie;
    int  i;
    zombie = zombieHorde(5, "Zombie");

    i = 0;
    while (i < 5)
    {
        zombie[i].announce();
        i++;
    }
    delete[] zombie;
    return (0);
}
