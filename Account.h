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
    //Constructor
        Account(int balance, consumer::Client& myClient);

    //GETTERS & SETTERS
        [[nodiscard]] const int &getBalance() const;
        [[nodiscard]] const iban::Iban &getIban() const;
        [[nodiscard]] const nmsdate::Date &getCreationDate() const;
        [[nodiscard]] const Statut &getStatut() const;

        void setBalance(int value);
        void setStatut(const Statut& statut);

protected:
    consumer::Client _myClient;
    int _balance;
    const iban::Iban _iban;
    const nmsdate::Date _creationDate;
    Statut _statut;
};

/**
 * Saving: Inherance from Account
 * A simple account with rate
 */
class Saving : public Account {

public:
    Saving(int balance, float rate, consumer::Client& myClient);

    [[nodiscard]] const float &getRate() const;

private:
    float _rate;
    
};

//FRIEND FUNCTIONS
bool isAccount(const int &balance, const iban::Iban &iban, const nmsdate::Date &creationDate);
bool isAccountLocked(const Account &account);



#endif //TD1_ACCOUNT_H
