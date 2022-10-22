//
// Created by hugo on 11/10/2022.
//

#ifndef TD1_TIME_H
#define TD1_TIME_H

#include <iostream>

class Time {

public:

    Time(unsigned int hour, unsigned int minute, unsigned int second = 0);

    [[nodiscard]] unsigned int getHour() const;
    [[nodiscard]] unsigned int getMinute() const;
    [[nodiscard]] unsigned int getSecond() const;

private:
    unsigned int _hour;
    unsigned int _minute;
    unsigned int _second;

};

bool isTime(const unsigned int& hour, const unsigned int& min, const unsigned int& sec);
std::string to_String(const Time &time);
Time getCurrentTime();

#endif //TD1_TIME_H
