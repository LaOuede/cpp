#include <iostream>
#include <iomanip> // std::setw
#include <string>
#include <ctime>
#include "Account.hpp"

#ifndef DEBUG
# define DEBUG 0
#endif

# define UTC (-4)

using std::cout;
using std::endl;
using std::setfill;
using std::setw;

/* ************************************************************************** */
/* Constructors and Destructors                                               */
/* ************************************************************************** */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	_totalAmount += checkAmount();
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex
		<< ";amount:" << checkAmount()
		<< ";created" << endl;
};

Account::~Account( void ) {
	_displayTimestamp();
	cout << "index:" << this->_accountIndex
		<< ";amount:" << checkAmount()
		<< ";closed" << endl;
};

/* ************************************************************************** */
/* Getters                                                                    */
/* ************************************************************************** */
int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }
int	Account::getTotalAmount( void ) { return Account::_totalAmount; }
int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }
int Account::checkAmount( void ) const { return this->_amount; };


/* ************************************************************************** */
/* Other functions                                                            */
/* ************************************************************************** */
void Account::displayAccountsInfos( void ) {
	Account::_displayTimestamp();
	cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals() << endl;
}

void Account::displayStatus( void ) const {
	Account::_displayTimestamp();
		cout << "index:" << this->_accountIndex
		<< ";amount:" << checkAmount()
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals << endl;
}

void Account::_displayTimestamp( void ) {
	if (DEBUG) {
		cout << "[19920104_091532]";
		return ;
	}
	time_t rawtime;
	struct tm * ptm;

	time ( &rawtime );
	ptm = gmtime ( &rawtime );
	cout << "[" << ptm->tm_year+1900 
	<< setfill( '0' ) << setw( 2 ) << ptm->tm_mon+1
	<< setfill( '0' ) << setw( 2 ) << ptm->tm_mday << "_"
	<< setfill( '0' ) << setw( 2 ) << (ptm->tm_hour+UTC)%24
	<< setfill( '0' ) << setw( 2 ) << ptm->tm_min
	<< setfill( '0' ) << setw( 2 ) << ptm->tm_sec << "] ";
}

void Account::makeDeposit( int deposit ) {
	int p_amount = checkAmount();
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";deposit:" << deposit
		<< ";amount:" << checkAmount()
		<< ";nb_deposits:" << this->_nbDeposits << endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
	int p_amount = checkAmount();
	if (withdrawal > checkAmount()) {
		_displayTimestamp();
		cout << "index:" << this->_accountIndex
			<< ";p_amount:" << p_amount
			<< ";withdrawal:refused" << endl;
		return false;
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_displayTimestamp();
	cout << "index:" << this->_accountIndex
		<< ";p_amount:" << p_amount
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << checkAmount()
		<< ";nb_withdrawals:" << this->_nbWithdrawals << endl;
	return true;
}