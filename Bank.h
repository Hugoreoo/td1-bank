//
// Created by hugo on 15/10/2022.
//

#ifndef TD1_BANK_H
#define TD1_BANK_H

#include <iostream>
#include "Date.h"
#include "Address.h"
#include "Transaction.h"
#include <vector>

class Account;
class Client;
class Transaction;

class Bank {

public:

    void createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear, const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet, std::string addressCity, int addressZipCode);
    void createAccount(int balance, Client* client);
    void deleteClient(const unsigned int& id);
    void deleteAccount(const std::string& iban);
    void lockedAccount(const std::string& iban);
    void unlockedAccount(const std::string& iban);

    void accountPayment(const std::string& srcIban, const std::string& destIban, int value, std::string message = "none");
    void accountDeposit(const std::string& srcIban, int value);
    void accountWithdrawal(const std::string& srcIban, int value);

    void addTransaction(TransactionType transactionType, Account *srcAccount, Account *destAccount, Date date, Time time, unsigned int value, std::string message = "none", bool statut = true);

    Client* getClientById(const unsigned int& id);
    Account* getAccountByIban(const std::string& iban);

    void printMyClients();
    void printMyHistorical();

private:
    std::vector<Client *> _myClients;
    std::vector<Account *> _myAccounts;
    std::vector<Transaction *> _myHistorical;

};



#endif //TD1_BANK_H
