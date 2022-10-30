//
// Created by hugog on 11/10/2022.
//

#include "Time.h"
#include <ctime>
#include <cassert>

namespace nmstime {

    Time::Time(unsigned int hour, unsigned int minute, unsigned int second) : _hour(hour), _minute(minute), _second(second) {
        bool statut = isTime(hour, minute, second);
        assert(statut && "Time is not valid");
    }

    const unsigned int &Time::getHour() const {
        return _hour;
    }

    const unsigned int &Time::getMinute() const {
        return _minute;
    }

    const unsigned int &Time::getSecond() const {
        return _second;
    }

    bool isTime(const unsigned int& hour, const unsigned int& min, const unsigned int& sec) {
        if((hour > 23) || (min > 59) || (sec > 59))
            return false;
        return true;
    }

    std::string to_String(const Time &time) {
        return std::to_string(time.getHour()) + ":" + std::to_string(time.getMinute()) + ":" + std::to_string(time.getSecond());
    }

    Time getCurrentTime() {

        time_t ttime = time(nullptr);
        tm *local_time = localtime(&ttime);

        int hour = local_time->tm_hour;
        int min = local_time->tm_min;
        int sec = local_time->tm_sec;

        return {static_cast<unsigned int>(hour), static_cast<unsigned int>(min), static_cast<unsigned int>(sec)};

    }
}