/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 17:59:04 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 13:06:24 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main()
{
    std::cout << "----------- 0 ----------" << std::endl;
    ScalarConverter::convertor("0");
    std::cout << "----------- nan ----------" << std::endl;
    ScalarConverter::convertor("nan");
    std::cout << "----------- 42.0f ----------" << std::endl;
    ScalarConverter::convertor("42.0f");
    std::cout << "----------- 67.5 ----------" << std::endl;
    ScalarConverter::convertor("67.5");
    return (0);
}

