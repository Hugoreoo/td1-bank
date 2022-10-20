//
// Created by hugo on 15/10/2022.
//

#include <utility>
#include <cassert>
#include "Client.h"
#include "Account.h"
#include "Bank.h"

void Bank::createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear,
                        const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet,
                        std::string addressCity, int addressZipCode) {

    this->_myClients.emplace_back(name, firstname, Date(birthMonth, birthDay, birthYear), email, phoneNumber, Address(addressNumber, std::move(addressStreet), std::move(addressCity), addressZipCode));

}

void Bank::printMyClients() {

    for (auto & _myClient : _myClients) {
        std::cout << std::endl << "----------------| Client |----------------" << std::endl;
        std::cout << "ID: " << _myClient.getId();
        std::cout << "  Name: " << _myClient.getName();
        std::cout << "  Firstname: " << _myClient.getFirstname();
        _myClient.printMyAccounts();
        std::cout << std::endl << "-----------------| END |-----------------" << std::endl;
    }


}

void Bank::createAccount(int balance, Client& client) {
    _myAccounts.push_back(*client.addAccount(balance, client));
}

Client * Bank::getClientById(unsigned int id) {

    for (auto & _myClient : this->_myClients) {

        if(_myClient.getId() == id) {
            return &_myClient;
        }
    }
    assert(false && "Client does not exist");

}

Account *Bank::getClientByIban(const std::string& iban) {

    for (auto &_myAccount: this->_myAccounts) {

        if(to_String(_myAccount.getIban()) == iban) {
            return &_myAccount;
        }
    }
    assert(false && "Client does not exist");
}

