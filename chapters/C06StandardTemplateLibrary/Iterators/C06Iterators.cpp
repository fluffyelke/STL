/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <iterator>

#include "C06Iterators.h"
#include "../Utils/Utils.h"

namespace C06STL {
    void testIterators() {
        std::list<char> myCont;
        for(char c = 'a'; c <= 'z'; c++) {
            myCont.push_back(c);
        }
        
        //print all elements, iterate over all elements
        std::list<char>::const_iterator pos;
        for(pos = myCont.begin(); pos != myCont.end(); pos++) {
            std::cout << *pos << " ";
        }
        std::cout << std::endl;
    }
    
    void setsBeforeCpp11() {
        using IntSet = std::set<int>;
        
        IntSet myIntSet;
        myIntSet.insert(3);
        myIntSet.insert(1);
        myIntSet.insert(5);
        myIntSet.insert(4);
        myIntSet.insert(1);
        myIntSet.insert(6);
        myIntSet.insert(2);
        
        IntSet::const_iterator pos;
        for(pos = myIntSet.begin(); pos != myIntSet.end(); ++pos) {
            std::cout << *pos << " ";
        }
        std::cout << std::endl;
    }
    
    void multiSetExample1() {
        std::unordered_multiset<int> myCont;
        myCont.insert({1, 3, 5, 7, 11, 13, 17,19, 23, 27, 1});
        
        Containers::printElements(myCont, "Unordered MultiSet:");
        
        myCont.insert(25);
        Containers::printElements(myCont, "After Insert Unordered MultiSet:");
    }
    
    void reverseIterators() {
        std::vector<int> myCont;
        for(int i = 1; i <= 9; ++i) {
            myCont.push_back(i);
        }
        
        //print elements in reverse orders
        std::copy(myCont.crbegin(), myCont.crend(),             //source
            std::ostream_iterator<int>(std::cout, " "));        //destination
        std::cout << std::endl;
    }
 
}