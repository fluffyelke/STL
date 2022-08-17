/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <complex>
#include <deque>
#include <algorithm>

#include "../Utils/C11Utils.h"
#include "MinimumAndMaximum.h"

namespace C11Algorithms {
    
    bool absLess(int elem1, int elem2) {
        return std::abs(elem1) < std::abs(elem2);
    }
    
    void testMinMax1() {
        std::deque<int> intDeque;
        C11Utils::insertElements(intDeque, 2, 6);
        C11Utils::insertElements(intDeque, -3, 6);
        
        C11Utils::printElements(intDeque);
        
        //process and print minimum and maximum
        std::cout << "minimum:  " << *std::min_element(intDeque.cbegin(), intDeque.cend()) << std::endl;
        std::cout << "maximum:  " << *std::max_element(intDeque.cbegin(), intDeque.cend()) << std::endl;
        
        //print min and max and their distance using minmax_element();
        auto mm = std::minmax_element(intDeque.cbegin(), intDeque.cend());
        std::cout << "min:      " << *(mm.first) << std::endl;
        std::cout << "max:      " << *(mm.second) << std::endl;
        std::cout << "distance: " << std::distance(mm.first, mm.second) << std::endl;
        
        //process and print minimum and maximum of absolute values
        std::cout << "minimum of absolute values: " 
            << *std::min_element(intDeque.cbegin(), intDeque.cend(),
                                absLess) << std::endl;
        std::cout << "maximum of absolute values: " 
            << *std::max_element(intDeque.cbegin(), intDeque.cend(),
                                absLess) << std::endl;
    }
}
