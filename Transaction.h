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

        [[maybe_unused]] [[nodiscard]] TransactionType getTransactionType() const;
        [[nodiscard]] Account getSrcAccount() const;
        [[nodiscard]] Account getDestAccount() const;
        [[nodiscard]] nmsdate::Date getDate() const;
        [[nodiscard]] nmstime::Time getTime() const;
        [[nodiscard]] unsigned int getValue() const;
        [[nodiscard]] std::string getMessage() const;
        [[nodiscard]] bool getStatut() const;


    private:
        TransactionType _transactionType;
        Account *_srcAccount;
        Account *_destAccount;
        nmsdate::Date _date;
        nmstime::Time _time;
        unsigned int _value;
        std::string _message;
        bool _statut;

    };

    std::string to_String(const Transaction *transaction);

}

#endif //TD1_TRANSACTION_H
