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

namespace management {

    void Bank::createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear, const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet, std::string addressCity, int addressZipCode) 
    {
        this->_myClients.push_back(new consumer::Client(name, firstname, nmsdate::Date(birthMonth, birthDay, birthYear), email, phoneNumber, address::Address(addressNumber, std::move(addressStreet), std::move(addressCity), addressZipCode)));
    }

    void Bank::createAccount(const int balance, consumer::Client* client)
    {
        _myAccounts.push_back(new Account(balance, *client));
        client->setAccount(_myAccounts.at(_myAccounts.size() - 1));
    }

    void Bank::createSaving(const int balance, const float rate, consumer::Client* client) 
    {
        _myAccounts.push_back(new Saving(balance, rate, *client));
        client->setAccount(_myAccounts.at(_myAccounts.size() - 1));
    }

    [[maybe_unused]] void Bank::lockedAccount(const std::string& iban)
    {
        getAccountByIban(iban)->setStatut(LOCKED);
    }

    [[maybe_unused]] void Bank::unlockedAccount(const std::string& iban)
    {
        getAccountByIban(iban)->setStatut(UNLOCKED);
    }

    const std::vector<consumer::Client *> &Bank::getMyClients() const {
        return _myClients;
    }

    const std::vector<transaction::Transaction *> &Bank::getMyHistory() const {
        return _myHistory;
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

        addTransaction(transaction::PAYMENT, this->getAccountByIban(srcIban), this->getAccountByIban(destIban), nmsdate::getCurrentDate(), nmstime::getCurrentTime(), value, std::move(message));

    }

    void Bank::accountDeposit(const std::string& srcIban, int value) 
    {
        if (isAccountLocked(*this->getAccountByIban(srcIban)))
            assert(false && "Source account is locked.");

        if(value < 0)
            value *= -1;

        this->getAccountByIban(srcIban)->setBalance(value);

        addTransaction(transaction::DEPOSIT, this->getAccountByIban(srcIban), this->getAccountByIban(srcIban), nmsdate::getCurrentDate(), nmstime::getCurrentTime(), value);
    }

    void Bank::accountWithdrawal(const std::string& srcIban, int value) 
    {
        if (isAccountLocked(*this->getAccountByIban(srcIban)))
            assert(false && "Source account is locked.");

        if(value < 0)
            value *= -1;

        this->getAccountByIban(srcIban)->setBalance(-value);

        addTransaction(transaction::WITHDRAWAL, this->getAccountByIban(srcIban), this->getAccountByIban(srcIban), nmsdate::getCurrentDate(), nmstime::getCurrentTime(), value);
    }

    consumer::Client * Bank::getClientById(const unsigned int& id) {

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

    void Bank::addTransaction(transaction::TransactionType transactionType, Account *srcAccount, Account *destAccount, nmsdate::Date date, nmstime::Time time, unsigned int value, std::string message, bool statut) 
    {
        this->_myHistory.push_back(new transaction::Transaction(transactionType, destAccount, date, time, value, srcAccount, std::move(message), statut));
    }

    [[maybe_unused]] void Bank::deleteClient(const unsigned int id) {

        for (long unsigned int i = 0; i < _myClients.size(); ++i)
        {
            if(_myClients.at(i)->getId() == id)
            {
                for (auto j : _myClients.at(i)->getMyAccounts())
                {
                    deleteAccount(to_String(j->getIban()));
                }

                _myClients.erase(_myClients.begin() + i);
            }
        }

    }

    void Bank::deleteAccount(const std::string& iban) {

        for (auto & _myClient : _myClients)
        {
            for (long unsigned int j = 0; j < _myClient->getMyAccounts().size(); ++j)
            {
                if(to_String(_myClient->getMyAccounts().at(j)->getIban()) == iban)
                    _myClient->deleteAccount(iban);

            }
        }

        for (long unsigned int i = 0; i < _myAccounts.size(); ++i)
        {
            if(to_String(_myAccounts.at(i)->getIban()) == iban) {
                _myAccounts.erase(_myAccounts.begin() + i);
            }
        }

    }

    void printMyClients(const std::vector<consumer::Client *>& clients) {

        for (long unsigned int i = 0; i < clients.size(); ++i)
        {
            std::cout << "-------------------------------------------------------------------------------| Client |-------------------------------------------------------------------------------" << std::endl << std::endl;
            std::cout << "=====> ID: " << clients.at(i)->getId();
            std::cout << "  Name: " << clients.at(i)->getName();
            std::cout << "  Firstname: " << clients.at(i)->getFirstname();
            consumer::printMyAccounts(clients.at(i)->getMyAccounts());
            std::cout << std::endl << /*"--------------------------------------------------------------------------------| END |--------------------------------------------------------------------------------" <<*/ std::endl;
        }

    }

    void printMyHistory(const std::vector<transaction::Transaction *>& history) {

        std::cout << std::endl << "-----------------------------------------------------------------------------| History |-----------------------------------------------------------------------------" << std::endl << std::endl;

        for (long unsigned int i = 0; i < history.size(); ++i)
        {
            std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout << to_String(history.at(i)) << std::endl;
            std::cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------------" << std::endl;
        }

        std::cout << std::endl << "--------------------------------------------------------------------------------| END |---------------------------------------------------------------------------------" << std::endl << std::endl;

    }

}