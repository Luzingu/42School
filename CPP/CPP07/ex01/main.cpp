/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:22:29 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 19:16:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
    std::string numberes[3] = {"Afonso", "Luzingu", "Kunzambi"};

    iter(numberes, 3, static_cast<void(*) (const::std::string &)>(printValue));
    return (0);
}