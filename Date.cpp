//
// Created by hugo on 11/10/2022.
//

#include "Date.h"
#include <iostream>
#include <cassert>

namespace nmsdate {

    Date::Date(int month, int day, int year) : _month(month), _day(day), _year(year) {
        bool statut = isDate(month, day, year);
        assert(statut && "Date is not valid");
    }

    const int &Date::getYear() const {
        return _year;
    }

    const int &Date::getMonth() const {
        return _month;
    }

    const int &Date::getDay() const {
        return _day;
    }

    bool isDate(const int& month, const int& day, const int& year) {

        if ((day < 1 || day > 31) || (month < 1 || month > 12) || (month == 2 && day > 28) || ((month == 4 || month ==6 || month == 9 || month == 11 ) && day > 30) || (year < 1900))
            return false;

        return true;

    }

    std::string to_String(const Date &date) {
        return std::to_string(date.getMonth()) + "/" + std::to_string(date.getDay()) + "/" + std::to_string(date.getYear());
    }

    Date getCurrentDate() {

        time_t ttime = time(nullptr);
        tm *local_time = localtime(&ttime);

        int year = 1900 + local_time->tm_year;
        int month = 1 + local_time->tm_mon;
        int day = local_time->tm_mday;

        return Date(month, day, year);

    }
}