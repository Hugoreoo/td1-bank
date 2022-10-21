//
// Created by hugo on 15/10/2022.
//

#include <utility>
#include <cassert>
#include <algorithm>
#include "Client.h"
#include "Account.h"
#include "Bank.h"

void Bank::createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear,
                        const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet,
                        std::string addressCity, int addressZipCode) {

    this->_myClients.emplace_back(name, firstname, Date(birthMonth, birthDay, birthYear), email, phoneNumber, Address(addressNumber, std::move(addressStreet), std::move(addressCity), addressZipCode));

}

void Bank::createAccount(int balance, Client& client) {
    Account *test = client.addAccount(balance, client);
    std::cout << "create: " << test << std::endl;
    _myAccounts.push_back(*test);
}



//TO DO LATER
/*void Bank::deleteClient(Client* client) {
    delete(client);
    std::vector<Client>::iterator position = std::find(_myClients.begin(), _myClients.end(), client);
    if(position != _myClients.end())
        _myClients.erase(position);

    //_myClients.erase(std::remove(_myClients.begin(), _myClients.end(), client), _myClients.end());
}

void Bank::deleteAccount(Account& account) {
    //delete(Account);
}*/

void Bank::printMyClients() {

    for (int i = 0; i < this->_myClients.size(); ++i)
    {
        std::cout << std::endl << "----------------| Client |----------------" << std::endl;
        std::cout << "ID: " << _myClients.at(i).getId();
        std::cout << "  Name: " << _myClients.at(i).getName();
        std::cout << "  Firstname: " << _myClients.at(i).getFirstname();
        _myClients.at(i).printMyAccounts();
        std::cout << std::endl << "-----------------| END |-----------------" << std::endl;
    }


}


void Bank::accountPayment(std::string srcIban, std::string destIban, const unsigned int& value) {
    Account *srcAccount = nullptr;
    Account *destAccount = nullptr;

    for (int i = 0; i < this->_myAccounts.size(); ++i)
    {
        if(to_String(_myAccounts.at(i).getIban()) == srcIban)
            srcAccount = &_myAccounts.at(i);
        if(to_String(_myAccounts.at(i).getIban()) == destIban)
            destAccount = &_myAccounts.at(i);
    }

    srcAccount->setBalance(-value);
    destAccount->setBalance(value);

    std::cout << std::endl << "srcAccount: " << &srcAccount << std::endl;
    std::cout << std::endl << "destAccount: " << &destAccount << std::endl;
}

Client * Bank::getClientById(const unsigned int& id) {

    for (int i = 0; i < this->_myClients.size(); ++i)
    {

        if(_myClients.at(i).getId() == id) {
            return &_myClients.at(i);
        }
    }
    assert(false && "Client does not exist");

}

Account *Bank::getAccountByIban(const std::string& iban) {

    for (int i = 0; i < this->_myAccounts.size(); ++i)
    {
        if(to_String(_myAccounts.at(i).getIban()) == iban) {
            return &_myAccounts.at(i);
        }
    }
/*
    for (auto &_myAccount: this->_myAccounts) {
        std::cout << "getAccountByIban: " << &this->_myAccounts.at(1) << std::endl;
        if(to_String(_myAccount.getIban()) == iban) {
            return &_myAccount;
        }
    }*/
    assert(false && "Account does not exist");
}

