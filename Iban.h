//
// Created by hugo on 11/10/2022.
//

#ifndef TD1_IBAN_H
#define TD1_IBAN_H

#include <string>

namespace iban {

    class Iban {

    public:
        Iban();

        [[nodiscard]] const std::string &getCp() const;
        [[nodiscard]] const std::string &getCc() const;
        [[nodiscard]] const std::string &getBban() const;

    private:
        std::string _cp;
        std::string _cc;
        std::string _bban;

    };

    bool isIban(const std::string& ibanToTest);
    std::string to_String(const Iban& iban);
    std::string randomBban(const int &len);
}

#endif //TD1_IBAN_H
