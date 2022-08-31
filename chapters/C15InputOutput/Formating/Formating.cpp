/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <ios>
#include <iomanip>

#include "Formating.h"


namespace C15Formating {
    void adjustmentExampleRight() {
        std::cout << std::right;
        std::cout << std::setw(20) << "text:" << std::setw(15) << 1 << std::endl;
        std::cout << std::setw(20) << "atext:" << std::setw(15) << 10 << std::endl;
        std::cout << std::setw(20) << "aatext:" << std::setw(15) << 100 << std::endl;
        std::cout << std::setw(20) << "aaatext:" << std::setw(15) << 1000 << std::endl;
        std::cout << std::setw(20) << "aaaatext:" << std::setw(15) << 10000 << std::endl;
        std::cout << std::setw(20) << "aaaaatext:" << std::setw(15) << 100000 << std::endl;
        std::cout << std::setw(20) << "aaaaaatext:" << std::setw(15) << 1000000 << std::endl;
        std::cout << std::setw(20) << "aaaaaaatext:" << std::setw(15) << 10000000 << std::endl;
        std::cout << std::setw(20) << "aaaaaaaatext:" << std::setw(15) << 100000000 << std::endl;
        
    }
    
    void adjustmentExampleLeft() {
        std::cout << std::left;
        std::cout << std::setw(20) << "text:" << std::setw(15) << 1 << std::endl;
        std::cout << std::setw(20) << "atext:" << std::setw(15) << 10 << std::endl;
        std::cout << std::setw(20) << "aatext:" << std::setw(15) << 100 << std::endl;
        std::cout << std::setw(20) << "aaatext:" << std::setw(15) << 1000 << std::endl;
        std::cout << std::setw(20) << "aaaatext:" << std::setw(15) << 10000 << std::endl;
        std::cout << std::setw(20) << "aaaaatext:" << std::setw(15) << 100000 << std::endl;
        std::cout << std::setw(20) << "aaaaaatext:" << std::setw(15) << 1000000 << std::endl;
        std::cout << std::setw(20) << "aaaaaaatext:" << std::setw(15) << 10000000 << std::endl;
        std::cout << std::setw(20) << "aaaaaaaatext:" << std::setw(15) << 100000000 << std::endl;
        
    }
}