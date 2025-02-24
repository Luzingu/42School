/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:53:09 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 13:52:26 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data dados;
    dados.idade = 19;
    dados.nome = "Afonso";
    Data *ptr = &dados;
    uintptr_t ref_ptr = Serializer::serialize(ptr);
    Data *new_ptr = Serializer::deserialize(ref_ptr);

    std::cout << "----------- (ptr) -------- " << std::endl;
    std::cout << "Nome: " << ptr->nome << std::endl;
    std::cout << "Idade: " << ptr->idade << std::endl;
    std::cout << "----------- (new_ptr) -------- " << std::endl;
    std::cout << "Nome: " << new_ptr->nome << std::endl;
    std::cout << "Idade: " << new_ptr->idade << std::endl;
    return (0);
}