//
// Created by hugo on 21/10/2022.
//

#ifndef TD1_TRANSACTION_H
#define TD1_TRANSACTION_H

#include <iostream>
#include "Account.h"
#include "Date.h"
#include "Time.h"

namespace transaction {

    enum TransactionType {PAYMENT, DEPOSIT, WITHDRAWAL};

    class Transaction {

    public:
        Transaction(TransactionType transactionType, Account *destAccount, nmsdate::Date date, nmstime::Time time, unsigned int value, Account *srcAccount = nullptr, std::string message = "none", bool statut = true);

        [[nodiscard]] const TransactionType &getTransactionType() const;
        [[nodiscard]] const Account &getSrcAccount() const;
        [[nodiscard]] const Account &getDestAccount() const;
        [[nodiscard]] const nmsdate::Date &getDate() const;
        [[nodiscard]] const nmstime::Time &getTime() const;
        [[nodiscard]] const unsigned int &getValue() const;
        [[nodiscard]] const std::string &getMessage() const;
        [[nodiscard]] const bool &getStatut() const;


    private:
        TransactionType _transactionType;
        Account *_srcAccount;
        Account *_destAccount;
        nmsdate::Date _date;
        nmstime::Time _time;
        const unsigned int _value;
        std::string _message;
        bool _statut;

    };

    std::string to_String(const Transaction *transaction);

}

#endif //TD1_TRANSACTION_H
