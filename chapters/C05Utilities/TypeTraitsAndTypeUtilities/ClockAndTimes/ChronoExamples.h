/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ChronoExamples.h
 * Author: default
 *
 * Created on July 29, 2022, 3:55 PM
 */

#ifndef CHRONOEXAMPLES_H
#define CHRONOEXAMPLES_H

#include <ostream>
#include <chrono>
#include <iostream>
#include <ios>
#include <ctime>
#include <string>

namespace Chrono {
    template<typename V, typename R>
    std::ostream& operator << (std::ostream& os, const std::chrono::duration<V, R>& d) {
        os << "[" << d.count() << " of " << R::num << "/" << R::den << "]";
        return os;
    }
    
    extern void splitIntoParts();
    
    
    template<typename C>
    void printClockData() {
        std::cout << "- precision: ";
        
        //if time unit is less or equal 1 millisecond
        typedef typename C::period P;   //type of time unit
        if(std::ratio_less_equal<P, std::milli>::value) {
            //convert to and print as milliseconds
            typedef typename std::ratio_multiply<P, std::kilo>::type TT;
            std::cout << std::fixed << double(TT::num)/TT::den << " milliseconds" << std::endl;
        }
        else {
            //print as seconds
            std::cout << std::fixed << double(P::num)/P::den << " seconds" << std::endl;
        }
        
        std::cout << "- is_steady: " << std::boolalpha << C::is_steady << std::endl; 
        
    }
    extern void testPrintClockData();
 
    
    
    extern std::string timePointAsString(const std::chrono::system_clock::time_point& tp);
    extern void testTimePoint();
    
    extern void testTimePoint2();
}

#endif /* CHRONOEXAMPLES_H */

