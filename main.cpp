#include <iostream>
#include "entity/Date.h"
#include "entity/Time.h"
#include "entity/Iban.h"
#include "entity/Address.h"
#include "Client.h"
#include "Account.h"
#include "Bank.h"

int main() {

    Bank myBank;

    myBank.createClient("Goncalves", "Hugo", 03, 12, 2001, "oui@oui", "048975389", 5, "Rue Courtepee", "DIJON", 21000);
    myBank.createClient("ezef", "zef", 03, 12, 2001, "zefzef@oui", "04897533389", 5, "Rue Courtepee", "DIJON", 21000);

    myBank.createAccount(1000, *myBank.getClientById(17409488));

    std::cout << to_String(myBank.getClientByIban("FR767Q30ROE94YXWQNBIBIX4ZJ7UBF2LXK")->getCreationDate());

    myBank.printMyClients();

    return 0;
}
