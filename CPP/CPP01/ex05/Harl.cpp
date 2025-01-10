/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:29:59 by aluzingu          #+#    #+#             */
/*   Updated: 2025/01/09 17:30:00 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my";
	std::cout << " 7XL-double-cheese-triple-pickle-specialketchup burger.";
	std::cout << " I really do!";
	std::cout << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn’t put enough bacon in my burger!";
	std::cout << " If you did, I wouldn’t be asking for more!";
	std::cout << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free.";
	std::cout << " I’ve been coming for years whereas you";
	std::cout << " started working here since last month.";
	std::cout << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want";
	std::cout << " to speak to the manager now.";
	std::cout << std::endl;
}

Harl::Harl(void)
{

}

Harl::~Harl(void)
{
	
}

void Harl::complain(std::string level)
{
	void (Harl::*ptr_fuctions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int int_level = -1;
	if (level == "DEBUG")
		int_level = 0;
	else if (level == "INFO")
		int_level = 1;
	else if (level == "WARNING")
		int_level = 2;
	else if (level == "ERROR")
		int_level = 3;
	else
		return ;
	(this->*ptr_fuctions[int_level])();
}