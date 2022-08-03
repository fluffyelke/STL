/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <iomanip>

#include "Utils.h"

//namespace ChronoSpace {
//    void splitIntoParts() {
//        std::chrono::milliseconds ms(7255042);
//        
//        //split into minutes, hours, and seconds
//        std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(ms);
//        std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(ms);
//        std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(ms);
//        std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(ms % std::chrono::seconds(1));
//        
//        //and print
//        std::cout << "raw: " << hh << "::" << mm << "::" << ss << "::" << msec << std::endl;
//        std::cout << "     " << std::setfill('0') << std::setw(2) << hh.count() << "::"
//                                                  << std::setw(2) << mm.count() << "::"
//                                                  << std::setw(2) << ss.count() << "::"
//                                                  << std::setw(2) << msec.count() << std::endl;
//        
//    }
//}