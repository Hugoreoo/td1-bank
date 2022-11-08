//
// Created by hugog on 15/10/2022.
//

#ifndef TD1_ADDRESS_H
#define TD1_ADDRESS_H

#include <iostream>

namespace address {

    class Address {

    public:
        //Constructor
            Address(unsigned int number, std::string street, std::string city, unsigned int  zipCode);

        //GETTERS & SETTERS
            [[nodiscard]] const unsigned int &getNumber() const;
            [[nodiscard]] const std::string &getStreet() const;
            [[nodiscard]] const std::string &getCity() const;
            [[nodiscard]] const unsigned int  &getZipCode() const;

    private:
        unsigned int _number;
        std::string _street;
        std::string _city;
        unsigned int _zipCode;

    };

    //FRIEND FUNCTIONS
    std::string to_String(const Address &address);
}

#endif //TD1_address_H
