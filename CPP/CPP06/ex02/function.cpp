/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <aluzingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:29:29 by aluzingu          #+#    #+#             */
/*   Updated: 2025/02/24 15:43:47 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClassBase.hpp"
#include "ClassA.hpp"
#include "ClassB.hpp"
#include "ClassC.hpp"
#include <ctime> 

Base * generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
}

int try_catch(Base& p, int classe)
{
    try
    {
        if (classe == 0)
            dynamic_cast <A &>(p);
        else if (classe == 2)
            dynamic_cast <B &>(p);
        else if (classe == 3)
            dynamic_cast <C &>(p);
        return (1);
    }
    catch(const std::exception& e)
    {
        return (0);
    }
    
}

void identify(Base& p)
{
    if (try_catch(p, 0))
        std::cout << "A" << std::endl;
    else if (try_catch(p, 1))
        std::cout << "B" << std::endl;
    else if (try_catch(p, 2))
        std::cout << "C" << std::endl;
}