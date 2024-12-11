/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aluzingu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:28:07 by aluzingu          #+#    #+#             */
/*   Updated: 2024/12/11 12:28:14 by aluzingu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return Account::_nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return Account::_totalAmount;
}
int	Account::getNbDeposits( void )
{
	return Account::_totalNbDeposits;
}
int	Account::getNbWithdrawals( void )
{
	return Account::_totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount;
	Account::_amount += deposit;
	Account::_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << ";deposit:" << deposit << ";amount:" << Account::_amount << ";nb_deposits:" << Account::_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";p_amount:" << Account::_amount << ";withdrawal:";
	if (withdrawal > Account::_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	Account::_amount -= withdrawal;
	Account::_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << Account::_amount << ";nb_withdrawals:" << Account::_nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (Account::_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();

	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";deposits:" << Account::_nbDeposits << ";withdrawals:" << Account::_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	time_t timestamp;
	char output[50];
	struct tm * datetime;

	time(&timestamp);
	datetime = localtime(&timestamp);
	strftime(output, 50, "[%Y%m%d_%H%M%S] ", datetime);
	std::cout << output;
}

Account::Account( int initial_deposit )
{
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;

	Account::_amount = initial_deposit;
	Account::_accountIndex = Account::getNbAccounts();
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex << ";amount:" << Account::_amount << ";created" << std::endl;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex <<";amount:" << Account::_amount << ";closed" << std::endl;
}
