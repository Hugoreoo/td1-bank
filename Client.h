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
        [[nodiscard]] unsigned int getId() const;
        [[maybe_unused]] [[nodiscard]] const nmsdate::Date &getBirthday() const;
        [[maybe_unused]] [[nodiscard]] const std::string &getEmail() const;
        [[maybe_unused]] [[nodiscard]] const std::string &getPhoneNumber() const;
        [[maybe_unused]] [[nodiscard]] const address::Address &getAddress() const;
        [[maybe_unused]] [[nodiscard]] const nmsdate::Date &getCreationDate() const;
        [[maybe_unused]] [[nodiscard]] const std::vector<Account *> &getMyAccounts() const;
        [[maybe_unused]] void setName(const std::string &name);

        void setAccount(Account* account);
        void deleteAccount(const std::string& iban);
        void printMyAccounts();

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

    unsigned int randomId(const int &len = 8);
    bool isClient(const std::string &name, const std::string &firstname, const nmsdate::Date &birthday, const std::string &email, const std::string &phoneNumer, const unsigned int &id, const address::Address &address);

}

#endif //TD1_CLIENT_H
