/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktombola <ktombola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:17:30 by ktombola          #+#    #+#             */
/*   Updated: 2025/09/24 10:17:43 by ktombola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

// init static attr
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"amount:" << checkAmount() << ";" <<
	"created" <<
	std::endl;
}

// Destructor
Account::~Account()
{
    _displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"amount:" << checkAmount() << ";" <<
	"closed" <<
	std::endl;
}

// Methods static consult (getter)
int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

// getter for account info
void Account::displayAccountsInfos()
{
    _displayTimestamp();
	std::cout <<
	"accounts:" << getNbAccounts() << ";" <<
	"total:" << getTotalAmount() << ";" <<
	"deposits:" << getNbDeposits() << ";" <<
	"withdrawals:" << getNbWithdrawals() <<
	std::endl;
}

// instance methods
void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"p_amount:" << checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout <<
	"amount:" << checkAmount() << ";" <<
	"nb_deposits:" << _nbDeposits <<
	std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"p_amount:" << checkAmount() << ";";
	if (checkAmount() < withdrawal)
	{
		std::cout <<
		"withdrawal:refused" <<
		std::endl;
		return (false);
	}
	else
	{
		_amount -= withdrawal;
		_nbWithdrawals++;
	    _totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		std::cout <<
		"withdrawal:" << withdrawal << ";" <<
		"amount:" << checkAmount() << ";" <<
		"nb_withdrawals:" << _nbWithdrawals <<
		std::endl;
		return (true);
	}
}

int Account::checkAmount() const { return _amount; }

void Account::displayStatus() const
{
    _displayTimestamp();
	std::cout <<
	"index:" << _accountIndex << ";" <<
	"amount:" << checkAmount() << ";" <<
	"deposits:" << _nbDeposits << ";" <<
	"withdrawals:" << _nbWithdrawals <<
	std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = std::time(NULL);
    struct tm timenow = *std::localtime(&now);
    std::cout << "[" 
          << (timenow.tm_year + 1900)
          << std::setw(2) << std::setfill('0') << (timenow.tm_mon + 1)
          << std::setw(2) << std::setfill('0') << timenow.tm_mday
          << "_"
          << std::setw(2) << std::setfill('0') << timenow.tm_hour
          << std::setw(2) << std::setfill('0') << timenow.tm_min
          << std::setw(2) << std::setfill('0') << timenow.tm_sec
          << "] ";

}

// private constructor
Account::Account() {}

// make re && ./test_account >my.log && diff my.log 19920104_091532.log
