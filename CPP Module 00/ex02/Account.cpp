#include <iostream>
#include <iomanip> // std::setw
#include <string>
#include <ctime>
#include "Account.hpp"

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

Account::Account( void ) { };

Account::Account( int initial_deposit ) : _amount(initial_deposit) {
	this->_accountIndex = _nbAccounts;
	_amount = _totalAmount;
	_nbDeposits = _totalNbDeposits;
	_nbWithdrawals = _totalNbWithdrawals;
    Account::_displayTimestamp();
	
};

Account::~Account( void ) { };

	int	Account::getNbAccounts( void ) { return Account::_nbAccounts; }
	int	Account::getTotalAmount( void ) { return Account::_totalAmount; }
	int	Account::getNbDeposits( void ) { return Account::_totalNbDeposits; }
	int	Account::getNbWithdrawals( void ) { return Account::_totalNbWithdrawals; }

#define UTC (-4)
void Account::_displayTimestamp( void ) {
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

void Account::displayAccountsInfos( void ) {
  for (int i = 0; i < 8; i++) {
    Account::_displayTimestamp();
    cout << "index:" << i << ";amount"
      << Account::getTotalAmount() << endl;
  }
}


