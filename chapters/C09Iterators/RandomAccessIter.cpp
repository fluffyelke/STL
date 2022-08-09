/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <iostream>

#include "RandomAccessIter.h"


namespace C09Iterators {
    void randAccessIterExample() {
        std::vector<int> intVec;
        
        //insert elements from -3 to 9
        for(int i = -3; i <= 9; ++i) {
            intVec.push_back(i);
        }
        
        //print number of elements by processing distances between begin and end
        //-Note use operator - for iterators
        std::cout << "number/distance: " << intVec.end() - intVec.begin() << std::endl;
        
        //print all elements
        std::vector<int>::iterator pos;
        for(pos = intVec.begin(); pos != intVec.end(); ++pos) {
            std::cout << *pos << " ";
        }
        std::cout << std::endl;
        
        //print all elements
        //using operator [] instead operator *
        for(int i = 0; i < intVec.size(); ++i) {
            std::cout << intVec.begin()[i] << " ";
        }
        std::cout << std::endl;
        
        //print every second element
        //note uses operator +=
        for(pos = intVec.begin(); pos < intVec.end() - 1; pos += 2) {
            std::cout << *pos << " ";
        }
        std::cout << std::endl;
    }
}