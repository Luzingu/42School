/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:17:34 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/25 11:08:22 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
    {
        try
        {
            Array<int> my_ints(4);
            my_ints.my_array[0] = 100;
            my_ints.my_array[1] = 2;
            my_ints.my_array[2] = 32;
            my_ints.my_array[3] = 67;

            for (int i = 0; i <= 4; i++)
            {
                std::cout << "Array[" << i << "]: " << my_ints[i] << std::endl;
            }
        }
        catch(std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }
    {
         try
        {
            Array<std::string> my_str(7);
            my_str.my_array[0] = "Afonso";
            my_str.my_array[1] = "Luzingu";
            my_str.my_array[2] = "Liedson";
            my_str.my_array[3] = "Habacuc";
            my_str.my_array[4] = "Peixe";
            my_str.my_array[5] = "Sudo";
            my_str.my_array[6] = "Luzizila";

            for (int i = 0; i <=7; i++)
            {
                std::cout << "Array[" << i << "]: " << my_str[i] << std::endl;
            }
        }
        catch(std::exception &e)
        {
            std::cout << "Error: " << e.what() << std::endl;
        }
    }


    return (0);
}