/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:14:51 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/25 11:25:58 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void pint_c1(int valor)
{
    std::cout << "1 Valor: " << valor << std::endl;
}
void pint_c2(int valor)
{
    std::cout << "2 Valor: " << valor << std::endl;
}

void pint_c3(int valor)
{
    std::cout << "3 Valor: " << valor << std::endl;
}

void pint_c4(int valor)
{
    std::cout << "4 Valor: " << valor << std::endl;
}

void print_values()
{
    void (*functions[4])(int) = {&pint_c1, &pint_c2, &pint_c3, &pint_c4};

    for(int i = 0; i <=3; i++)
    {
        functions[i](i);
    }
}




int main()
{
    


    print_values();
    return (0);
}