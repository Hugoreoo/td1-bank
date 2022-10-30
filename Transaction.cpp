//
// Created by hugog on 15/10/2022.
//

#include "Transaction.h"
#include <iostream>
#include <cassert>
#include <utility>

namespace transaction {

    Transaction::Transaction(TransactionType transactionType, Account *destAccount, nmsdate::Date date, nmstime::Time time, unsigned int value, Account *srcAccount, std::string message, bool statut) :
        _transactionType(transactionType), _destAccount(destAccount), _date(date), _time(time), _value(value), _srcAccount(srcAccount), _message(std::move(message)), _statut(statut) {
    }

    const TransactionType &Transaction::getTransactionType() const {
        return _transactionType;
    }

    const Account &Transaction::getSrcAccount() const {
        return *_srcAccount;
    }

    const Account &Transaction::getDestAccount() const {
        return *_destAccount;
    }

    const nmsdate::Date &Transaction::getDate() const {
        return _date;
    }

    const nmstime::Time &Transaction::getTime() const {
        return _time;
    }

    const unsigned int &Transaction::getValue() const {
        return _value;
    }

    const std::string &Transaction::getMessage() const {
        return _message;
    }

    const bool &Transaction::getStatut() const {
        return _statut;
    }

    std::string to_String(const Transaction *transaction) {
        std::string transactionType, statut;

        if(transaction->getTransactionType() == PAYMENT)
            transactionType = "PAYMENT";
        else if (transaction->getTransactionType() == DEPOSIT)
            transactionType = "DEPOSIT";
        else if (transaction->getTransactionType() == WITHDRAWAL)
            transactionType = "WITHDRAWAL";
        else assert(false && "to_String() transaction error.");

        if(!transaction->getStatut())
            statut = "Echec";
        else statut = "Succes";

        return "| " + transactionType 
                + " | From: " + to_String(transaction->getSrcAccount().getIban()) 
                + " | To: " + to_String(transaction->getDestAccount().getIban()) 
                + " | Value: " + std::to_string(transaction->getValue())
                + " | At: " + to_String(transaction->getDate()) + " " + to_String(transaction->getTime())
                + " | Mess: " + transaction->getMessage()
                + " | Statut: " + statut + " |";
    }
}