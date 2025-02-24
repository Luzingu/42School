/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:22:30 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 15:36:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBase.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"

int main()
{
    Base *base = generate();
    identify(base);
    identify(base);
    return (0);
}