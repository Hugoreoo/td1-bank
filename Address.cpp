//
// Created by hugog on 15/10/2022.
//

#include "Address.h"
#include <utility>

namespace address {

    /**
     * Address Constructor
     * @param number
     * @param street
     * @param city
     * @param zipCode
     */
    Address::Address(unsigned int number, std::string street, std::string city, unsigned int  zipCode)
            : _number(number), _street(std::move(street)), _city(std::move(city)), _zipCode(zipCode) {}

    //GETTERS & SETTERS
    const unsigned int &Address::getNumber() const {
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

    //FRIEND FUNCTIONS
    /**
     * Convert an address to string
     * @param adress
     * @return
     */
    std::string to_String(const Address &adress) {
        return std::to_string(adress.getNumber()) + " " + adress.getStreet() + ", " + adress.getCity() + " " + std::to_string(adress.getZipCode());
    }
}