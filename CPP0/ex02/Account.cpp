/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caguillo <caguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 03:00:18 by caguillo          #+#    #+#             */
/*   Updated: 2024/10/23 21:35:02 by caguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

// Static initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor overloaded
Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_totalAmount = _totalAmount + initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
	_nbAccounts++;
	return ;
}

// Destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return ;
}

void Account::_displayTimestamp(void)
{
	// get current_time in seconds since 01/01/1970
	std::time_t s = std::time(0);
	// convert the seconds into the structure format tm (adjusted for local system's time zone).
	std::tm *now = std::localtime(&s);	
	std::cout << "[";
	std::cout << (*now).tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << (*now).tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << (*now).tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << (*now).tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << (*now).tm_min;
	std::cout << std::setfill('0') << std::setw(2) << (*now).tm_sec;
	std::cout << "] ";
	return ;
}
// struct tm {
//     int tm_sec;   // seconds (0–60)
//     int tm_min;   // minutes (0–59)
//     int tm_hour;  // hours (0–23)
//     int tm_mday;  // day of the month (1–31)
//     int tm_mon;   // months since January (0–11)
//     int tm_year;  // years since 1900
//     int tm_wday;  // days since Sunday (0–6)
//     int tm_yday;  // days since January 1 (0–365)
//     int tm_isdst; // daylight saving time flag
// };

int Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

// [19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
	return ;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	std::cout << ";deposit:" << deposit;
	_amount = _amount + deposit;
	_totalAmount = _totalAmount + deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
	return ;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount;
	if (_amount < withdrawal)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << ";withdrawal:" << withdrawal;
		_amount = _amount - withdrawal;
		_totalAmount = _totalAmount - withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
	}
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount);
}

// [19920104_091532] index:0;amount:47;deposits:1;withdrawals:0
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return ;
}
