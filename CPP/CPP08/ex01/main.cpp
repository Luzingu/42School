/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:21:33 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/27 18:10:25 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    int numAleat [100000];
    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        numAleat[i] = std::rand();
    }
    std::set<int> numeros(numAleat, numAleat + 10000);
    Span sp(10000);
    try
    {
        sp.addNumbers(numeros.begin(), numeros.end());
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(Span::AllReadyExist &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(Span::StorageSpan &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    catch(Span::InsuficentNumber &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return (0);
}