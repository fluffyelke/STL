/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>
#include <chrono>

#include "ChronoExamples.h"

namespace Chrono {
    void splitIntoParts() {
        std::chrono::milliseconds ms(7255042);
        
        //split milliseconds into minutes, hours, and seconds
        std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(ms);
        std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(ms);
        std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(ms);
        std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));
        
        //and print
        std::cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << std::endl;
        std::cout << "     " << std::setfill('0') << std::setw(2) << hh.count() << "::"
                                                  << std::setw(2) << mm.count() << "::"
                                                  << std::setw(2) << ss.count() << "::"
                                                  << std::setw(3) << msec.count() << std::endl;
        
    }
    
    void testPrintClockData() {
        std::cout << "system_clock: " << std::endl;
        printClockData<std::chrono::system_clock>();
        
        std::cout << "\nhigh_resolution_clock:" << std::endl;
        printClockData<std::chrono::high_resolution_clock>();
        
        std::cout << "\nsteady_clock:" << std::endl;
        printClockData<std::chrono::steady_clock>();
    }
    
    std::string timePointAsString(const std::chrono::system_clock::time_point& tp) {
        //convert to system time
        std::time_t t = std::chrono::system_clock::to_time_t(tp);
        //for universel time use
//        std::string ts = std::asctime(std::gmtime(&t));
        std::string ts = std::ctime(&t); //convert to calendar time
        ts.resize(ts.size() - 1);   //skip trailing new line
        
        return ts;
    }
    
    void testTimePoint() {
        //print the epoch of this system clock
        std::chrono::system_clock::time_point tp;
        std::cout << "epoch: " << timePointAsString(tp) << std::endl;
        
        //print current time
        tp = std::chrono::system_clock::now();
        std::cout << "now:   " << timePointAsString(tp) << std::endl;
        
        //print minimum time of this system clock
        tp = std::chrono::system_clock::time_point::min();
        std::cout << "min:   " << timePointAsString(tp) << std::endl;
        
        //print maximum time of this system clock
        tp = std::chrono::system_clock::time_point::max();
        std::cout << "max:   " << timePointAsString(tp) << std::endl;
        
    }
    
    void testTimePoint2() {
        //Define type for durations that represents Days
//        typedef std::chrono::duration<int, std::ratio<3600 * 24>> Days;
        using Days = std::chrono::duration<int, std::ratio<3600 * 24>>;
        
        //process the epoch of this sytem_clock
        std::chrono::time_point<std::chrono::system_clock> tp;
        std::cout << "epoch:     " << timePointAsString(tp) << std::endl;
        
        //add one day, 23 hours and 55 minuts
        tp += Days(1) + std::chrono::hours(23) + std::chrono::minutes(55);
        std::cout << "later:     " << timePointAsString(tp) << std::endl;
        
        //process difference from epoch in minutes and days
        auto diff = tp - std::chrono::system_clock::time_point();
        std::cout << "diff:      " << std::chrono::duration_cast<std::chrono::minutes>(diff).count() 
                  << " minute(s)" << std::endl;
        
        Days days = std::chrono::duration_cast<Days>(diff);
        std::cout << "diff:      " << days.count() 
                  << " day(s)" << std::endl;
        
        //substract 1 year hoping is valid and not leap
        tp -= std::chrono::hours(24 * 365);
        std::cout << "-1 year:   " << timePointAsString(tp) << std::endl;
        
        //substract 50 years hoping is valid and ignoring leap years 
        tp -= std::chrono::duration<int, std::ratio<3600 * 24 * 365>>(150);
        std::cout << "-150 year: " << timePointAsString(tp) << std::endl;
        
        //substract 50 years hoping is valid and ignoring leap years 
        tp -= std::chrono::duration<int, std::ratio<3600 * 24 * 365>>(150);
        std::cout << "-150 year: " << timePointAsString(tp) << std::endl;
    }
}