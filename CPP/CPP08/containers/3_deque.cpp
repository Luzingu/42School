/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:54:44 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 16:05:36 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <deque>

int main()
{
    //Eficiente para manipulacao nas extremidades, e semelhante ao vector..
    std::deque<int> numeros = {0, 9, 1};

    numeros.push_front(19);
    numeros.push_back(21);

    std::deque<int>::iterator it = numeros.begin();
    std::advance(it, 0);
    numeros.erase(it);
    it = numeros.begin();
    std::cout << "First value: " << *it << std::endl;

    std::cout << "Value: " << numeros.at(0) << std::endl;

    for (int num : numeros)
    {
        std::cout << "Numero: " << num << std::endl;
    }
    return (0);
}