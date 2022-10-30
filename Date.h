//
// Created by hugo on 11/10/2022.
//

#ifndef TD1_DATE_H
#define TD1_DATE_H

#include <iostream>

namespace nmsdate {

    class Date {

    public:
        explicit Date(int month = 01, int day = 01, int year = 2000);

        [[nodiscard]] const int &getYear() const;
        [[nodiscard]] const int &getMonth() const;
        [[nodiscard]] const int &getDay() const;

    private:
        int _year;
        int _month;
        int _day;

    };

    bool isDate(const int& month, const int& day, const int& year);
    std::string to_String(const Date &date);
    Date getCurrentDate();
}


#endif //TD1_DATE_H
