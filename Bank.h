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

        void createClient(const std::string& name, const std::string& firstname, int birthMonth, int birthDay, int birthYear, const std::string& email, const std::string& phoneNumber, int addressNumber, std::string addressStreet, std::string addressCity, int addressZipCode);
        void createAccount(int balance, consumer::Client* client);

        [[maybe_unused]] void deleteClient(unsigned int id);
        [[maybe_unused]] void deleteAccount(const std::string& iban);

        [[maybe_unused]] void lockedAccount(const std::string& iban);
        [[maybe_unused]] void unlockedAccount(const std::string& iban);

        void accountPayment(const std::string& srcIban, const std::string& destIban, int value, std::string message = "none");
        void accountDeposit(const std::string& srcIban, int value);
        void accountWithdrawal(const std::string& srcIban, int value);

        void addTransaction(TransactionType transactionType, Account *srcAccount, Account *destAccount, Date date, Time time, unsigned int value, std::string message = "none", bool statut = true);

        consumer::Client* getClientById(const unsigned int& id);
        Account* getAccountByIban(const std::string& iban);

        void printMyClients();
        void printMyHistory();

    private:
        std::vector<consumer::Client *> _myClients;
        std::vector<Account *> _myAccounts;
        std::vector<Transaction *> _myHistory;

    };

}


#endif //TD1_BANK_H
