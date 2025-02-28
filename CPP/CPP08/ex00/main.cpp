/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:19:53 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/27 15:47:12 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

    std::cout << " Vector " << std::endl;
    std::vector<int> vector;
    vector.insert(vector.begin(), 1);
    vector.insert(vector.begin() + 1, -2);
    vector.insert(vector.begin() + 2, 10);
    vector.insert(vector.begin() + 3, 7);
    vector.insert(vector.begin() + 4, 0);
    try
    {
        std::vector<int>::iterator it = easyfind(vector, 10);
        std::cout << "Found in vector " << *it << std::endl;

        it = easyfind(vector, 17);
        std::cout << "Found in vector " << *it << std::endl;
    }
    catch (NotFoundException &e)
    {
        std::cout << "Error " << e.what() << std::endl;
    }
    std::cout << " List " << std::endl;
    std::list<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(-7);
    list.push_back(10);
    try
    {
        std::list<int>::iterator it = easyfind(list, 10);
        std::cout << "Found in list " << *it << std::endl;
        it = easyfind(list, 8);
        std::cout << "Found in list " << *it << std::endl;
    }
    catch(NotFoundException &e)
    {
        std::cout << "Error " << e.what() << std::endl;
    }

    return (0);
}