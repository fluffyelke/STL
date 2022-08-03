/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <chrono>
#include <iostream>

#include "DateAndTime.h"
#include "ChronoExamples.h"


namespace Chrono {
    std::chrono::system_clock::time_point makeTimePoint(int year, int mon, int day, int hour, int min, int sec) {
        struct std::tm t;
        t.tm_sec = sec;         //second of minutes(0...59 and 60 for leap seconds)
        t.tm_min = min;         //minute of hour(0-59)
        t.tm_hour = hour;       //hour of day(0-23)
        t.tm_mday = day;        //day of month(0-31)
        t.tm_mon = mon;         //month of year(0-11) 
        t.tm_year = year - 1900;       //year since 1900
        t.tm_isdst = -1;        //determine whether daylight saving time 
        std::time_t tt = std::mktime(&t);
        
        if(tt == -1){
            throw "No Valid system time";
        }
        return std::chrono::system_clock::from_time_t(tt);
    }
    
    void testMakeTimePoint() {
        auto tp1 = makeTimePoint(2010, 01, 01, 00, 00);
        std::cout << timePointAsString(tp1) << std::endl;
        
        auto tp2 = makeTimePoint(2011, 05, 23, 13, 44);
        std::cout << timePointAsString(tp2) << std::endl;
    }
}
