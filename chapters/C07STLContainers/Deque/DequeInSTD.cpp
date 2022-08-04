/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <deque>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "DequeInSTD.h"


namespace C07Containers {
    void dequeExample() {
        //create empty deque of string
        std::deque<std::string> strDeque;
        
        //insert several elements
        strDeque.assign(3, std::string("string"));
        strDeque.push_back("last string");
        strDeque.push_front("first string");
        
        std::copy(strDeque.begin(), strDeque.end(),
                 std::ostream_iterator<std::string>(std::cout, "\n"));
        std::cout << std::endl;
        
        //remove first and last element
        strDeque.pop_back();
        strDeque.pop_front();
        
        //insert 'another' in every element but the first
        for(unsigned int i = 1; i < strDeque.size(); ++i) {
            strDeque[i] = "another " + strDeque[i];
        }
        //change size to 4 elements
        strDeque.resize(4, "resized string");
        std::copy(strDeque.begin(), strDeque.end(),
                 std::ostream_iterator<std::string>(std::cout, "\n"));
        std::cout << std::endl;
        
        //using for each
        for(auto& elem : strDeque) {
            elem = "changed " + elem;
        }
        std::copy(strDeque.begin(), strDeque.end(),
                 std::ostream_iterator<std::string>(std::cout, "\n"));
        std::cout << std::endl;
    }
}