//
// Created by hugo on 15/10/2022.
//

#include "Client.h"
#include "Account.h"
#include <cassert>

namespace consumer {

    Client::Client(const std::string &name, const std::string &firstname, const nmsdate::Date &birthday,
                   const std::string &email,
                   const std::string &phoneNumber, const address::Address &address) :
            _name(name),
            _firstname(firstname),
            _birthday(birthday),
            _email(email),
            _phoneNumber(phoneNumber),
            _id(randomId()), _address(address),
            _creationDate(nmsdate::getCurrentDate()){

        bool statut = isClient(name, firstname, birthday, email, phoneNumber, _id, address);
        assert(statut && "Client is not valid");

    }

    const std::string &Client::getName() const {
        return _name;
    }
    const std::string &Client::getFirstname() const {
        return _firstname;
    }

    const nmsdate::Date &Client::getBirthday() const {
        return _birthday;
    }

    const std::string &Client::getEmail() const {
        return _email;
    }

    const std::string &Client::getPhoneNumber() const {
        return _phoneNumber;
    }
    const unsigned int &Client::getId() const {
        return _id;
    }

    const address::Address &Client::getAddress() const {
        return _address;
    }

    const nmsdate::Date &Client::getCreationDate() const {
        return _creationDate;
    }

    const std::vector<Account *> &Client::getMyAccounts() const {
        return _myAccounts;
    }

    void Client::setAccount(Account * account) {
        this->_myAccounts.push_back(account);
    }

    void Client::setName(const std::string &name) {
        _name = name;
    }

    void Client::deleteAccount(const std::string& iban) {

        for (long unsigned int i = 0; i < _myAccounts.size(); ++i)
        {
            if(to_String(_myAccounts.at(i)->getIban()) == iban) {
                _myAccounts.erase(_myAccounts.begin() + i);

            }
        }
    }

    void printMyAccounts(const std::vector<Account *>& accounts) {

        //std::cout << "RATE: " << accounts.at(2)->getRate() << std::endl;

        for (long unsigned int i = 0; i < accounts.size(); ++i)
        {
            std::cout << std::endl << std::endl << "-------------------------------| Account |-------------------------------" << std::endl;
            std::cout << "\tBalance: " << accounts.at(i)->getBalance() << "e";
            std::cout << "  IBAN: " << to_String(accounts.at(i)->getIban()) << std::endl;
            std::cout << "\tCreation: " << to_String(accounts.at(i)->getCreationDate()) << std::endl;

            if(isAccountLocked(*accounts.at(i)))
                std::cout << "\tStatut: Locked" << std::endl;
            else
                std::cout << "\tStatut: Unlocked" << std::endl;

            std::cout << "-------------------------------------------------------------------------";
        }

    }

    bool isClient([[maybe_unused]] const std::string &name, [[maybe_unused]] const std::string &firstname, [[maybe_unused]] const nmsdate::Date &birthday, const std::string &email, [[maybe_unused]] const std::string &phoneNumer, [[maybe_unused]] const unsigned int &id, [[maybe_unused]] const address::Address &address) {

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
}