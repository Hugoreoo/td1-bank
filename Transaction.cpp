//
// Created by hugog on 15/10/2022.
//

#include "Transaction.h"
#include <iostream>
#include <cassert>

Transaction::Transaction(TransactionType transactionType, Account *account, Date date, Time time, unsigned int value, std::string message, bool statut) :
    _transactionType(transactionType), _account(account), _date(date), _time(time), _value(value), _message(message), _statut(statut) {
}

TransactionType Transaction::getTransactionType() const {
    return _transactionType;
}

Account Transaction::getAccount() const {
    return *_account;
}

Date Transaction::getDate() const {
    return _date;
}

Time Transaction::getTime() const {
    return _time;
}

unsigned int Transaction::getValue() const {
    return _value;
}

std::string Transaction::getMessage() const {
    return _message;
}

bool Transaction::getStatut() const {
    return _statut;
}

std::string to_String(const Transaction &transaction) {
    std::string transactionType, statut;
    
    if(transaction.getStatut() == PAYMENT)
        transactionType = "PAYMENT";
    else if (transaction.getStatut() == DEPOSIT)
        transactionType = "DEPOSIT";
    else if (transaction.getStatut() == WITHDRAWAL)
        transactionType = "WITHDRAWAL";
    else assert(false && "to_String() transaction error.");

    if(transaction.getStatut() == false)
        statut = "Echec";
    else statut = "Succes";

    return "| " + transactionType 
            + " | IBAN: " + to_String(transaction.getAccount().getIban()) 
            + " | Value: " + std::to_string(transaction.getValue())
            + " | At: " + to_String(transaction.getDate()) + " " + to_String(transaction.getTime())
            + " | Mess: " + transaction.getMessage()
            + " | Statut: " + statut + " |";
}