//
// Created by hugog on 15/10/2022.
//

#ifndef TD1_BANK_H
#define TD1_BANK_H

#include <iostream>
#include "entity/Date.h"
#include "entity/Address.h"
#include <vector>

class Account;
class Client;
//class History;

class Bank {

public:

    void createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear, const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet, std::string addressCity, int addressZipCode);

    Client * getClientById(unsigned int id);
    Account * getClientByIban(const std::string& iban);
    void createAccount(int balance, Client& client);
    void printMyClients();

private:
    std::vector<Client> _myClients;
    std::vector<Account> _myAccounts;
    //std::list<History> _myHistory;

};


#endif //TD1_BANK_H
