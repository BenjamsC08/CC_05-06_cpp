#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;


Account::Account(int initital_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_totalAmount += initital_deposit;
	this->_amount = initital_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	/*this->displayStatus();*/
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";created" << std::endl;
};

Account::~Account(void)
{
	/*this->displayStatus();*/
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount;
	std::cout << ";closed" << std::endl;

};

void Account::_displayTimestamp(void)
{
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);

	char output[50];

	strftime(output, 50, "[%Y%m%d_%H%M%S]", &datetime);
	std::cout << output << " ";
	// std::cout << "["<< datetime.tm_year + 1900 << datetime.tm_mon + 1 << datetime.tm_mday << "_";
	// std::cout << datetime.tm_hour << datetime.tm_min << datetime.tm_sec <<"] ";
};

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
};

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
};

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:"<< getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
};

void Account::makeDeposit(int deposit)
{
	int	p_amount = _amount;
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"<< p_amount;
	std::cout << ";deposits:" << deposit << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
};

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:"<< _amount;
	std::cout << ";withdrawal:" ;
	if (_amount < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return(true);
};

int	Account::checkAmount(void) const
{
	return (_amount);
};

void Account::displayStatus(void) const
{
	this->_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:";
	std::cout << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
};
