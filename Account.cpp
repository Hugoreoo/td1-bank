//
// Created by hugog on 15/10/2022.
//

#include "Account.h"
#include <cassert>



    Account::Account(int balance, consumer::Client& myClient) : _balance(balance), _myClient(myClient), _iban(iban::Iban()), _creationDate(nmsdate::getCurrentDate()), _statut(UNLOCKED)
    {
        bool statut = isAccount(balance, _iban, _creationDate);
        assert(statut && "Account is not valid");
    }

    const int &Account::getBalance() const {
        return _balance;
    }

    const iban::Iban &Account::getIban() const {
        return _iban;
    }

    const nmsdate::Date &Account::getCreationDate() const {
        return _creationDate;
    }

    const Statut &Account::getStatut() const {
        return _statut;
    }

    void Account::setBalance(int value) {
        this->_balance = _balance + value;
    }

    void Account::setStatut(const Statut& statut) 
    {
        this->_statut = statut;
    }

    Saving::Saving(int balance, float rate, consumer::Client& myClient) : Account(balance, myClient), _rate(rate)
    {
        bool statut = isAccount(balance, _iban, _creationDate);
        assert(statut && "Saving is not valid");
    }

    const float &Saving::getRate() const {
        return _rate;
    }

    bool isAccount(const int &balance, const iban::Iban &iban, const nmsdate::Date &creationDate) {

        if (balance < 0)
            return false;
        return true;

    }

    bool isAccountLocked(const Account &account) {

        if (account.getStatut() == LOCKED)
            return true;
        return false;

    }

