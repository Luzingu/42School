/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:19:00 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/28 15:00:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        BTC btc(argv[1]);
        (void) argc;
        (void) argv;
    }
    else
        std::cout << "Error: could not open file." << std::endl;
    return (0);
}