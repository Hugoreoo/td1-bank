//
// Created by hugog on 15/10/2022.
//

#include "Address.h"
#include <utility>

namespace address {

    Address::Address(unsigned int number, std::string street, std::string city, unsigned int  zipCode)
            : _number(number), _street(std::move(street)), _city(std::move(city)), _zipCode(zipCode) {}

    unsigned int Address::getNumber() const {
        return _number;
    }

    const std::string &Address::getStreet() const {
        return _street;
    }

    const std::string &Address::getCity() const {
        return _city;
    }

    const unsigned int  &Address::getZipCode() const {
        return _zipCode;
    }

    std::string to_String(const Address &adress) {
        return std::to_string(adress.getNumber()) + " " + adress.getStreet() + ", " + adress.getCity() + " " + std::to_string(adress.getZipCode());
    }
}