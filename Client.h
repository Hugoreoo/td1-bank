//
// Created by hugo on 15/10/2022.
//

#ifndef TD1_CLIENT_H
#define TD1_CLIENT_H

#include <iostream>
#include <vector>
#include "Address.h"
#include "Date.h"

class Account;

namespace consumer {

    class Client {

    public:
        Client(const std::string &name, const std::string &firstname, const nmsdate::Date &birthday, const std::string &email, const std::string &phoneNumber, const address::Address &address);

        [[nodiscard]] const std::string &getName() const;
        [[nodiscard]] const std::string &getFirstname() const;
        [[nodiscard]] const unsigned int &getId() const;
        [[nodiscard]] const nmsdate::Date &getBirthday() const;
        [[nodiscard]] const std::string &getEmail() const;
        [[nodiscard]] const std::string &getPhoneNumber() const;
        [[nodiscard]] const address::Address &getAddress() const;
        [[nodiscard]] const nmsdate::Date &getCreationDate() const;
        [[nodiscard]] const std::vector<Account *> &getMyAccounts() const;

        void setAccount(Account* account);
        void setName(const std::string &name);
        void deleteAccount(const std::string& iban);

    private:
        std::vector<Account *> _myAccounts;
        std::string _name;
        std::string _firstname;
        nmsdate::Date _birthday;
        std::string _email;
        std::string _phoneNumber;
        const unsigned int _id;
        address::Address _address;
        const nmsdate::Date _creationDate;

    };

    void printMyAccounts(const std::vector<Account *>& accounts);
    bool isClient([[maybe_unused]] const std::string &name, [[maybe_unused]] const std::string &firstname, [[maybe_unused]] const nmsdate::Date &birthday, const std::string &email, [[maybe_unused]] const std::string &phoneNumer, [[maybe_unused]] const unsigned int &id, [[maybe_unused]] const address::Address &address);
    unsigned int randomId(const int &len = 8);

}

#endif //TD1_CLIENT_H
