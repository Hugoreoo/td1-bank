//
// Created by hugo on 15/10/2022.
//

#include <utility>
#include <cassert>
#include <algorithm>
#include "Client.h"
#include "Account.h"
#include "Bank.h"
#include "Date.h"
#include "Time.h"

void Bank::createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear,
                        const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet,
                        std::string addressCity, int addressZipCode) {

    this->_myClients.push_back(new Client(name, firstname, Date(birthMonth, birthDay, birthYear), email, phoneNumber, Address(addressNumber, std::move(addressStreet), std::move(addressCity), addressZipCode)));

}

void Bank::createAccount(int balance, Client* client){

    _myAccounts.push_back(new Account(balance, *client));
    client->setAccount(_myAccounts.at(_myAccounts.size() - 1));
}

void Bank::lockedAccount(const std::string& iban) 
{
    getAccountByIban(iban)->setStatutt(LOCKED);
}

void Bank::unlockedAccount(const std::string& iban) 
{
    getAccountByIban(iban)->setStatutt(UNLOCKED);
}

void Bank::printMyClients() {

    for (long unsigned int i = 0; i < this->_myClients.size(); ++i)
    {
        std::cout << "-------------------------------------------------------------------------------| Client |-------------------------------------------------------------------------------" << std::endl << std::endl;
        std::cout << "=====> ID: " << _myClients.at(i)->getId();
        std::cout << "  Name: " << _myClients.at(i)->getName();
        std::cout << "  Firstname: " << _myClients.at(i)->getFirstname();
        _myClients.at(i)->printMyAccounts();
        std::cout << std::endl << /*"--------------------------------------------------------------------------------| END |--------------------------------------------------------------------------------" <<*/ std::endl;
    }

}


void Bank::accountPayment(const std::string& srcIban, const std::string& destIban, int value, std::string message)
{
    if (isAccountLocked(*this->getAccountByIban(srcIban)))
        assert(false && "Source account is locked.");
    if (isAccountLocked(*this->getAccountByIban(destIban)))
        assert(false && "Destination account is locked.");

    if(value < 0)
        value *= -1;

    if(this->getAccountByIban(srcIban)->getBalance() - value < 0)
        assert(false && "Balance account insufficient.");

    this->getAccountByIban(srcIban)->setBalance(-value);
    this->getAccountByIban(destIban)->setBalance(value);

    addTransaction(PAYMENT, this->getAccountByIban(srcIban), this->getAccountByIban(destIban), getCurrentDate(), getCurrentTime(), value, message);

}

void Bank::accountDeposit(const std::string& srcIban, int value) 
{
    if (isAccountLocked(*this->getAccountByIban(srcIban)))
        assert(false && "Source account is locked.");

    if(value < 0)
        value *= -1;

    this->getAccountByIban(srcIban)->setBalance(value);

    addTransaction(DEPOSIT, this->getAccountByIban(srcIban), this->getAccountByIban(srcIban), getCurrentDate(), getCurrentTime(), value);
}

void Bank::accountWithdrawal(const std::string& srcIban, int value) 
{
    if (isAccountLocked(*this->getAccountByIban(srcIban)))
        assert(false && "Source account is locked.");

    if(value < 0)
        value *= -1;

    this->getAccountByIban(srcIban)->setBalance(-value);

    addTransaction(WITHDRAWAL, this->getAccountByIban(srcIban), this->getAccountByIban(srcIban), getCurrentDate(), getCurrentTime(), value);
}

Client * Bank::getClientById(const unsigned int& id) {

    for (long unsigned int i = 0; i < this->_myClients.size(); ++i)
    {
        if(_myClients.at(i)->getId() == id) {
            return _myClients.at(i);
        }
    }
    assert(false && "Client does not exist");

    return nullptr;
}

Account * Bank::getAccountByIban(const std::string& iban) {

    for (long unsigned int i = 0; i < this->_myAccounts.size(); ++i)
    {
        if(to_String(_myAccounts.at(i)->getIban()) == iban) {
            return _myAccounts.at(i);
        }
    }
    assert(false && "Account does not exist");
    return nullptr;
}


void Bank::printMyHistorical() {

    std::cout << std::endl << "-----------------------------------------------------------------------------| Historical |-----------------------------------------------------------------------------" << std::endl << std::endl;

    for (long unsigned int i = 0; i < this->_myHistorical.size(); ++i)
    {
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << to_String(_myHistorical.at(i)) << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
    }

    std::cout << std::endl << "--------------------------------------------------------------------------------| END |---------------------------------------------------------------------------------" << std::endl << std::endl;

}

void Bank::addTransaction(TransactionType transactionType, Account *srcAccount, Account *destAccount, Date date, Time time, unsigned int value, std::string message, bool statut) 
{
    this->_myHistorical.push_back(new Transaction(transactionType, destAccount, date, time, value, srcAccount, message, statut));
}