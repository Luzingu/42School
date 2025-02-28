/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_vector.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:01:31 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 18:56:02 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

void manipulador(int &number)
{
    number += 10;
    std::cout << "Numero: " << number << std::endl;
}


int main()
{
    std::vector<int> numeros  = {0, 100, 210};

    //numeros.clear();
    if (numeros.empty())
        std::cout << "A lista esta vazia " << std::endl;
    numeros.insert(numeros.begin(), -1);
    numeros.insert(numeros.begin() + 1, 19);
    numeros.insert(numeros.begin()  + 2, 2);
    numeros.insert(numeros.begin()  + 3, 21);

    std::vector<int>::iterator it = numeros.begin();
    it = std::next(it);
        
    std::cout << "Saida: " << *it << std::endl;

    try
    {

        //std::reverse(numeros.begin(), numeros.end());
       // std::sort(numeros.begin(), numeros.end());

        // /std::cout << "Times " << std::count(numeros.begin(), numeros.end(), 100);
        /*if (std::find(numeros.begin(), numeros.end(), -1) != numeros.end())
        {
            std::cout << "Yes" << std::endl;
        }*/


        //numeros.erase(numeros.begin() + 1);
        //std::cout << "Numero " << numeros.at(0) << std::endl;

        std::for_each(numeros.begin(), numeros.end(), manipulador);
        /*for (auto num : numeros)
        {
            std::cout << "Out: " << num << std::endl;
        }*/
    }
    catch(std::out_of_range &e)
    {
        std::cout << "Error " << e.what() << std::endl;
    }

    
    return (0);
}