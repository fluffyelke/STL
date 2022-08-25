/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <bitset>
#include <iostream>
#include <limits>

#include "Bitset.h"


namespace C12Containers {
    void bitsetExample() {
        //Enumeration type for the bits
        //each bir represent a color
        enum class Color {
            red, yellow, green, blue, white, black,
            numColors
        };
        
        //create bitset for all bits/colors
        std::bitset<static_cast<std::size_t>(Color::numColors)> usedColors;
        
        
        //set bits for 2 colors
        usedColors.set(static_cast<std::size_t>(Color::red));
        usedColors.set(static_cast<std::size_t>(Color::blue));
        
        //print some bitset data
        std::cout << "bitfield of used colors:   " << usedColors << std::endl;
        std::cout << "number   of used colors:   " << usedColors.count() << std::endl;
        std::cout << "bitfield of unused colors: " << ~usedColors << std::endl;
        
        //if any color is used
        if(usedColors.any()) {
            //loop over all colors
            for(int c = 0; c < static_cast<int>(Color::numColors); c++) {
                //if the actual color is used
                if(usedColors[static_cast<std::size_t>(c)]) {
                    //do something...
                    std::cout << "Color: " << (c + 1) << " used!\n";
                }
            }
        }
    }
    
    void bitsetExample2() {
        //print some number in binary representation
        std::cout << "267 as binary short:      " 
                  << std::bitset<std::numeric_limits<unsigned short>::digits>(267)
                  << std::endl;
        
        std::cout << "267 as binary long:       " 
                  << std::bitset<std::numeric_limits<unsigned long>::digits>(267)
                  << std::endl;
        
        std::cout << "10,000,000 with 24 bits:  " 
                  << std::bitset<24>(1e7)
                  << std::endl;
        
        //write binary representation into string
        std::string s = std::bitset<42>(12345678).to_string();
        std::cout << "12,345,678 with 42 bits:  " << s << std::endl;
        
        //transform binary representation into integer form
        std::cout << "\"1000101011\" as number: " 
                  << std::bitset<100>("1000101011").to_ullong() << std::endl;
    }
}