/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:26:53 by aluzingu          #+#    #+#             */
/*   Updated: 2025/03/03 19:09:13 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **agrv)
{
    if (argc != 2)
    {
        std::cout << "Input Error" << std::endl;
        return (0);
    }
    RPN rpn(agrv[1]);
    return (0);
}

