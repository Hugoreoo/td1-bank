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

namespace management {

    class Bank {

    public:

        //SETTERS
        void createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear, const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet, std::string addressCity, int addressZipCode);
        void createAccount(const int balance, consumer::Client* client);
        void createSaving(const int balance, const float rate, consumer::Client* client);
        
        [[maybe_unused]] void deleteClient(const unsigned int id);
        [[maybe_unused]] void deleteAccount(const std::string& iban);

        [[maybe_unused]] void lockedAccount(const std::string& iban);
        [[maybe_unused]] void unlockedAccount(const std::string& iban);

        //GETTERS
        [[nodiscard]] const std::vector<consumer::Client *> &getMyClients() const;
        [[nodiscard]] const std::vector<transaction::Transaction *> &getMyHistory() const;
        consumer::Client* getClientById(const unsigned int& id);
        Account* getAccountByIban(const std::string& iban);

        //METHODS
        void accountPayment(const std::string& srcIban, const std::string& destIban, int value, std::string message = "none");
        void accountDeposit(const std::string& srcIban, int value);
        void accountWithdrawal(const std::string& srcIban, int value);

        void addTransaction(transaction::TransactionType transactionType, Account *srcAccount, Account *destAccount, nmsdate::Date date, nmstime::Time time, unsigned int value, std::string message = "none", bool statut = true);

    private:
        std::vector<consumer::Client *> _myClients;
        std::vector<Account *> _myAccounts;
        std::vector<transaction::Transaction *> _myHistory;

    };

    //FRIENDS
    void printMyClients(const std::vector<consumer::Client *>& clients);
    void printMyHistory(const std::vector<transaction::Transaction *>& history);

}


#endif //TD1_BANK_H
