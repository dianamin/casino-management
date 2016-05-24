//
//  Time.hpp
//  casino-management
//
//  Created by Florin Chirica on 24/05/16.
//  Copyright © 2016 Florin Chirica. All rights reserved.
//

#ifndef Time_h
#define Time_h

#include <stdio.h>
#include <cstring>
#include <sstream>
#include <time.h>

class Time {
private:
    static Time *s_instance;

    Time() {
    }

    std :: string to_string(int x) {
        std :: string s;
        int foo = 0;
        do {
            ++foo;
            s += ((x % 10) + '0');
            x /= 10;
        } while (x);
        if (foo == 1)
            s += '0';
        reverse(s.begin(), s.end());
        return s;
    }

    int hour, minute, second;
    int day, month, year;

    std :: string get_month(int month) {
        const std :: string romanian_months[] = {"mare b0$$", "Ianuarie", "Februarie", "Martie", "Aprilie", "Mai", "Iunie", "Iulie", "August", "Septembrie", "Octombrie", "Noiembrie", "Decembrie"};
        return romanian_months[month];
    }

    void set_variables() {
        time_t now = time(0);
        struct tm tstruct;
        char buf[69];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
        year = (buf[0] - '0') * 1000 + (buf[1] - '0') * 100 + (buf[2] - '0') * 10 + buf[3] - '0';
        month = (buf[5] - '0') * 10 + buf[6] - '0';
        day = (buf[8]-  '0') * 10 + buf[9] - '0';
        hour = (buf[11]-  '0') * 10 + buf[12] - '0';
        minute = (buf[14]-  '0') * 10 + buf[15] - '0';
        second = (buf[17]-  '0') * 10 + buf[18] - '0';
    }
public:
    static Time *instance() {
        if (!s_instance)
            s_instance = new Time;
        return s_instance;
    }
    std ::string get_time() {
        set_variables();
        std :: string res;
        res = to_string(day) + "/" + get_month(month) + "/" + to_string(year) + " " + to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
        return res;
    }
};



#endif /* Time_hpp */
