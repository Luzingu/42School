/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:35:21 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 15:52:43 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stdexcept>

void change_value(std::list<int> &numeros, int posicao, int valor)
{
    std::list<int>::iterator it = numeros.begin();
    std::advance(it, posicao);
    *it = valor;
}

void detele_value(std::list<int> &numeros, int posicao)
{
    std::list<int>::iterator it = numeros.begin();
    std::advance(it, posicao);
    numeros.erase(it);
}


int main()
{
    std::list<int> numeros = {0, 1, 19};
    
    try
    {
        std::list<int>::iterator it = numeros.begin();
        change_value(numeros, 1, 1999);
        numeros.push_front(12);
        numeros.push_back(17);
        numeros.pop_back();
        detele_value(numeros, 1);
        std::advance(it, 3);
        numeros.insert(it, 20);
        for (int num: numeros)
        {
            std::cout << "Numero: " << num << std::endl;
        }
    }
    catch(std::out_of_range &e)
    {
        std::cout << "Error " << e.what() << std::endl;
    }
    
    return (0);
}