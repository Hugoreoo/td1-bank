//
// Created by hugog on 15/10/2022.
//

#include "Transaction.h"

Transaction::Transaction(TransactionType transactionType, Account *account, Date date, Time time, unsigned int value, bool statut) :
    _transactionType(transactionType), _account(account), _date(date), _time(time), _value(value), _statut(statut) {
}