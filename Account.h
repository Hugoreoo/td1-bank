//
// Created by hugo on 15/10/2022.
//

#ifndef TD1_ACCOUNT_H
#define TD1_ACCOUNT_H

#include "entity/Iban.h"
#include "entity/Date.h"
#include "Client.h"

enum Statut {Unlocked, Locked};

class Client;
class Account {

public:
    Account(int balance, Client myClient);

    [[nodiscard]] int getBalance() const;
    [[nodiscard]] const Iban &getIban() const;
    [[nodiscard]] const Date &getCreationDate() const;
    [[nodiscard]] Statut getStatut() const;
    void setBalance(unsigned int value);

private:
    Client _myClient;
    int _balance;
    const Iban _iban;
    const Date _creationDate;
    Statut _statut;

    void setStatut(Statut statut);
};

bool isAccount(const int &balance, const Iban &iban, const Date &creationDate);
bool isAccountLocked(const Account &account);


#endif //TD1_ACCOUNT_H
