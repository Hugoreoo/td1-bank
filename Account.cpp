//
// Created by hugog on 15/10/2022.
//

#include "Account.h"
#include <cassert>

Account::Account(int balance, Client& myClient) : _balance(balance), _myClient(myClient), _iban(Iban()), _creationDate(getCurrentDate()),
                                                                     _statut(UNLOCKED) {

    bool statut = isAccount(balance, _iban, _creationDate);
    assert(statut && "Account is not valid");
}

int Account::getBalance() const {
    return _balance;
}

const Iban &Account::getIban() const {
    return _iban;
}

const Date &Account::getCreationDate() const {
    return _creationDate;
}

Statut Account::getStatut() const {
    return _statut;
}

[[maybe_unused]] void Account::setStatut(Statut statut) {
    _statut = statut;
}

void Account::setBalance(int value) {
    this->_balance = _balance + value;
}

void Account::setStatutt(const Statut& statut) 
{
    this->_statut = statut;
}

bool isAccount(const int &balance, const Iban &iban, const Date &creationDate) {

    if (balance < 0)
        return false;
    return true;

}

bool isAccountLocked(const Account &account) {

    if (account.getStatut() == LOCKED)
        return true;
    return false;

}