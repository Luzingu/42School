/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_unorder_set.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 17:01:17 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 17:08:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <unordered_set>

//Usa hash  e faz uma basca rapida dos valores...
int main()
{
    std::unordered_set<int> numeros = {0, 9, 4, 8};

    for (auto num : numeros)
    {
        std::cout << "Numero: " << num << std::endl;
    }

    if (numeros.find(9) != numeros.end())
    {
        std::cout << "Valor existe!" << std::endl;
    }

    return (0);
}