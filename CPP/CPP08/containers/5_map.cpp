/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_map.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:33:45 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/26 18:59:11 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Estrutura Chava-valor...

#include <iostream>
#include <map>

int main()
{
    std::map<std::string, int> idades;
    idades["Afonso"] = 12;
    idades["Luzingu"] = 7;
    idades["Ana Maria"] = 19;
    idades["Madalena"] = 21;
    idades["Madalena"] = 17;

    idades.erase("Madalena");
    idades.insert({"Daniel", 21});
    //std::cout << "Value: " << idades.at("Madalena") << std::endl;

    for(auto par : idades)
    {
        std::cout << "Nome: " << par.first << ", idade " << par.second << std::endl; 
    }
    return (0);
}