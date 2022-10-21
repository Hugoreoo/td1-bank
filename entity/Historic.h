//
// Created by hugog on 21/10/2022.
//

#ifndef TD1_HISTORIC_H
#define TD1_HISTORIC_H

#include <iostream>
#include "../Account.h"
#include "Date.h"
#include "Time.h"

enum Transaction {VIREMENT, RETRAIT, DEPOT};

class Historic {

public:

    Historic();

private:
    Transaction _transaction;
    Account *_account;
    unsigned int _value;
    Date _date;
    Time _time;
    std::string _message;
    bool _statut;

};


#endif //TD1_HISTORIC_H
