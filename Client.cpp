//
// Created by hugo on 15/10/2022.
//

#include "Client.h"
#include "Account.h"
#include <cassert>

Client::Client(const std::string &name, const std::string &firstname, const Date &birthday,
               const std::string &email,
               const std::string &phoneNumber, const Address &address) :
        _name(name),
        _firstname(firstname),
        _birthday(birthday),
        _email(email),
        _phoneNumber(phoneNumber),
        _id(randomId()), _address(address),
        _creationDate(getCurrentDate()){

    bool statut = isClient(name, firstname, birthday, email, phoneNumber, _id, address);
    assert(statut && "Client is not valid");

}

Account* Client::addAccount(int balance, Client& client) {
    this->_myAccounts.emplace_back(balance, client);
    return &this->_myAccounts.at(this->_myAccounts.size()-1);
}

void Client::printMyAccounts() {

    for (auto & _myAccount : _myAccounts) {
        std::cout << std::endl << "------------| Account |------------" << std::endl;
        std::cout << "Balance: " << _myAccount.getBalance() << "E";
        std::cout << "  IBAN: " << to_String(_myAccount.getIban()) << std::endl;
        std::cout << "Creation: " << to_String(_myAccount.getCreationDate()) << std::endl;
        std::cout << "Name: " << this->getName() << "   Firstname: " << this->getFirstname() << "   ID: " << this->getId() << std::endl;

        if(isAccountLocked(_myAccount))
            std::cout << "Statut: Locked" << std::endl;
        else
            std::cout << "Statut: Unlocked" << std::endl;
    }

}

const std::string &Client::getName() const {
    return _name;
}
const std::string &Client::getFirstname() const {
    return _firstname;
}
const Date &Client::getBirthday() const {
    return _birthday;
}
const std::string &Client::getEmail() const {
    return _email;
}
const std::string &Client::getPhoneNumber() const {
    return _phoneNumber;
}
unsigned int Client::getId() const {
    return _id;
}
const Address &Client::getAddress() const {
    return _address;
}
const Date &Client::getCreationDate() const {
    return _creationDate;
}

const std::vector<Account> &Client::getMyAccounts() const {
    return _myAccounts;
}

bool isClient(const std::string &name, const std::string &firstname, const Date &birthday, const std::string &email,
              const std::string &phoneNumer, const unsigned int &id, const Address &address) {

    if (email.find('@') == std::string::npos)
        return false;

    return true;

}

unsigned int randomId(const int &len) {
    static const char alphanum[] = "0123456789";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return std::stoi(tmp_s);
}