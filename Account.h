//
// Created by hugo on 15/10/2022.
//

#ifndef TD1_ACCOUNT_H
#define TD1_ACCOUNT_H

#include "Iban.h"
#include "Date.h"
#include "Client.h"

enum Statut {UNLOCKED, LOCKED};

class Client;

    class Account {

    public:
        Account(int balance, consumer::Client& myClient);

        [[nodiscard]] int getBalance() const;
        [[nodiscard]] const iban::Iban &getIban() const;
        [[nodiscard]] const nmsdate::Date &getCreationDate() const;
        [[nodiscard]] Statut getStatut() const;
        void setBalance(int value);
        void setStatut(const Statut& statut);

    private:
        consumer::Client _myClient;
        int _balance;
        const iban::Iban _iban;
        const nmsdate::Date _creationDate;
        Statut _statut;
    };

    bool isAccount(const int &balance, const iban::Iban &iban, const nmsdate::Date &creationDate);
    bool isAccountLocked(const Account &account);



#endif //TD1_ACCOUNT_H
