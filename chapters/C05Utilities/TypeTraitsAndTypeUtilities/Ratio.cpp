/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <ratio>
#include <iostream>

#include "Ratio.h"

namespace Ratio {
    void testRatio() {
//        typedef MyRatio<5, 3> FiveThirds;
        typedef std::ratio<5, 3> FiveThirds;
        std::cout << FiveThirds::num << "/" << FiveThirds::den << std::endl;
        
        typedef std::ratio<25, 15> AlsoFiveThirds;
        std::cout << AlsoFiveThirds::num << "/" << AlsoFiveThirds::den << std::endl;
        
        std::ratio<42, 42> one;
        std::cout << one.num << "/" << one.den << std::endl;
        
        std::ratio<0> zero;
        std::cout << zero.num << "/" << zero.den << std::endl;
        
        typedef std::ratio<7, -3> Neg;
        std::cout << Neg::num << "/" << Neg::den << std::endl;
    }
}