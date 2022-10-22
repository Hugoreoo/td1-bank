//
// Created by hugo on 21/10/2022.
//

#ifndef TD1_TRANSACTION_H
#define TD1_TRANSACTION_H

#include <iostream>
#include "Account.h"
#include "Date.h"
#include "Time.h"

enum TransactionType {PAYMENT, DEPOSIT, WITHDRAWAL};

class Transaction {

public:
    Transaction(TransactionType transactionType, Account *account, Date date, Time time, unsigned int value, std::string message, bool statut);

    [[nodiscard]] TransactionType getTransactionType() const;
    [[nodiscard]] Account getAccount() const;
    [[nodiscard]] Date getDate() const;
    [[nodiscard]] Time getTime() const;
    [[nodiscard]] unsigned int getValue() const;
    [[nodiscard]] std::string getMessage() const;
    [[nodiscard]] bool getStatut() const;


private:
    TransactionType _transactionType;
    Account *_account;
    Date _date;
    Time _time;
    unsigned int _value;
    std::string _message;
    bool _statut;

};

std::string to_String(const Transaction &transaction);

#endif //TD1_address_H
