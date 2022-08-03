/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DateAndTime.h
 * Author: default
 *
 * Created on August 1, 2022, 2:20 PM
 */

#ifndef DATEANDTIME_H
#define DATEANDTIME_H

#include <chrono>


namespace Chrono {
    inline std::chrono::system_clock::time_point makeTimePoint(int year, int mon, int day, int hour, int min, int sec = 0);
    
    extern void testMakeTimePoint();
}

#endif /* DATEANDTIME_H */

