#include <iostream>
#include "entity/Date.h"
#include "entity/Time.h"
#include "entity/Iban.h"
#include "entity/Address.h"
#include "Transaction.h"
#include "Client.h"
#include "Account.h"
#include "Bank.h"

int main() {

    Bank myBank;

    myBank.createClient("Goncalves", "Hugo", 03, 12, 2001, "oui@oui", "048975389", 5, "Rue Courtepee", "DIJON", 21000);
    myBank.createClient("ezef", "zef", 03, 12, 2001, "zefzef@oui", "04897533389", 5, "Rue Courtepee", "DIJON", 21000);

    myBank.createAccount(1000, *myBank.getClientById(36753562));
    myBank.createAccount(2000, *myBank.getClientById(36753562));

    //myBank.printMyClients();

    myBank.accountPayment("FR76OIGSZ8FXQQQVJJ5IIU531GVYX99BWD" , "FR76EKBUTAJ889EE4DX9WFKHYLDT0RI92F", 200);
    /*myBank.getAccountByIban("FR76OIGSZ8FXQQQVJJ5IIU531GVYX99BWD")->setBalance(20);
    std::cout << myBank.getAccountByIban("FR76OIGSZ8FXQQQVJJ5IIU531GVYX99BWD")->getBalance();*/
    myBank.printMyClients();

    return 0;
}
