/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_set.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:09:34 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 19:00:37 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Os valores ja vem ordenados....

#include <iostream>
#include <set>

int main()
{
    std::set<int> numeros = {8, 1, 2, 17};
    std::set<int>::iterator it = numeros.begin();
        
    std::advance(it, 0);
    numeros.insert(it, 10);


    std::reverse(idades.begin(), idades.end());
    for(int num:numeros)
    {
        std::cout << num << std::endl;
    }
    return (0);
}