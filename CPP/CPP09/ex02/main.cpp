/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:58:44 by aluzingu          #+#    #+#             */
/*   Updated: 2025/03/04 18:52:20 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int   main(int argc, char **argv)
{
    if(argc <= 1)
    {
        std::cout << "Error" << std::endl;
        return (0);
    }
    PMergeMe perge(argc, argv);
    
    return (0);
}
