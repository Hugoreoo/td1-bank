#include "Bank.h"

int main() {

    Bank myBank;

    myBank.createClient("Goncalves", "Hugo", 03, 12, 2001, "oui@oui", "048975389", 5, "Rue Courtepee", "DIJON", 21000);
    myBank.createClient("Benameur", "Camil", 07, 23, 2001, "dhtzefzeeef@oui", "04897533389", 5, "Rue Courtepee", "DIJON", 21000);
    myBank.createClient("test", "test", 07, 23, 2001, "dhtzefzeeef@oui", "04897533389", 5, "Rue Courtepee", "DIJON", 21000);

    myBank.createAccount(2000, myBank.getClientById(36753562));
    myBank.createAccount(3000, myBank.getClientById(91270936));

    //myBank.lockedAccount("FR76QQQVJJ5IIU531GVYX99BWDEKBUTAJ8");

    myBank.accountPayment("FR76QQQVJJ5IIU531GVYX99BWDEKBUTAJ8" , "FR7689EE4DX9WFKHYLDT0RI92F2WFE7OOQ", 236, "kdo");
    myBank.accountDeposit("FR76QQQVJJ5IIU531GVYX99BWDEKBUTAJ8", 2000);
    myBank.accountWithdrawal("FR76QQQVJJ5IIU531GVYX99BWDEKBUTAJ8", 100);

    //myBank.deleteClient(17409488);

    myBank.printMyClients();
    myBank.printMyHistory();

    return 0;
}
