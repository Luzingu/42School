/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:53:56 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 16:03:31 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}
ScalarConverter::~ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return (*this);
}

void ScalarConverter::convertor(std::string valor)
{
    float f_number = std::atof(valor.c_str());
    int i_number = std::atoi(valor.c_str());

    if(valor == "nan" || valor == "-inf" || valor == "+inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << valor << "f" << std::endl;
        std::cout << "double: " << valor << std::endl;
    }
    else
    {
        if(i_number > 0 && i_number <= 255)
            std::cout << "char: " << static_cast <char> (i_number) << std::endl;
        else
            std::cout << "char: " << "Non displayable" << std::endl;
        std::cout << "int: " << i_number << std::endl;

         std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f_number << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f_number) << std::endl;
    }
}

