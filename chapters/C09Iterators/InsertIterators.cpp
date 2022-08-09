/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include "../C06StandardTemplateLibrary/Utils/Utils.h"
#include "InsertIterators.h"


namespace C09Iterators {
    void backInserterTest() {
        std::vector<int> intVec;
        
        //create back inserter
        // inconvenient way
        std::back_insert_iterator<std::vector<int>> iter(intVec);
        //insert elements with the usual iterator interface
        *iter = 1;
        iter++;
        *iter = 2;
        iter++;
        *iter = 3;
        iter++;
        Containers::printElements(intVec, "1 intVec: ");
        
        //create back inserter and insert elements
        //convenient way
        std::back_inserter(intVec) = 44;
        std::back_inserter(intVec) = 55;
        Containers::printElements(intVec, "2 intVec: ");
        
        // use back inserter to append all elements again
        // reserve enough memory to avoid reallocation
        intVec.reserve(2 * intVec.size());
        std::copy(intVec.begin(), intVec.end(),     //source
                 std::back_inserter(intVec));       //destination
        Containers::printElements(intVec, "3 intVec: ");
        
    }
}