//
// Created by hugo on 11/10/2022.
//

#include "Iban.h"
#include <cassert>

Iban::Iban() : _cp("FR"), _cc("76"), _bban(randomBban(30)){
    bool statut = isIban(_cp + _cc + _bban);
    assert(statut && "Iban is not valid");
}

const std::string &Iban::getCp() const {
    return _cp;
}

const std::string &Iban::getCc() const {
    return _cc;
}

const std::string &Iban::getBban() const {
    return _bban;
}

bool isIban(const std::string& ibanToTest) {
    if (ibanToTest.find("FR76") != std::string::npos)
        return true;

    return false;
}

std::string to_String(const Iban& iban) {
    return iban.getCp() + iban.getCc() + iban.getBban();
}

std::string randomBban(const int& len) {
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return tmp_s;
}