/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <iostream>
#include <algorithm>
#include "../C06StandardTemplateLibrary/Utils/Utils.h"
#include "AuxiliaryIterFunctions.h"


namespace C09Iterators {
    void advanceExample() {
        std::list<int> intList;
        
        for (int i = 1; i <= 9; ++i) {
            intList.push_back(i);
        }
        
        std::list<int>::iterator pos = intList.begin();
        //print actual element
        std::cout << *pos << std::endl;
        
        //step 3 elements forward
        std::advance(pos, 3);
        
        //print actual element
        std::cout << *pos << std::endl;
        
        //step 1 element backward
        std::advance(pos, -1);
        
        //print actual element
        std::cout << *pos << std::endl;
    }
    
    void distanceExample() {
        std::list<int> intList;
        
        for(int i = -3; i <= 9; ++i ) {
            intList.push_back(i);
        }
        
        //search element with value 5
        std::list<int>::iterator pos;
        pos = std::find(intList.begin(), intList.end(),
                        5);
        
        if(pos != intList.end()) {
            //process and print difference from the beginning
            std::cout << "difference between begining and 5 is: " << std::distance(intList.begin(), pos) << std::endl;
        }
        else {
            std::cout << "element 5 was not found.\n";
        }
    }
    
    void iterSwapExample() {
        std::list<int> intList;
        for(int i = 1; i <= 9; ++i){
            intList.push_back(i);
        }
        
        Containers::printElements(intList, "intList:                     ");
        
        //swap first and second value
        std::iter_swap(intList.begin(), std::next(intList.begin()));
        Containers::printElements(intList, "swap frist and second value: ");
        
        //swap first and last value
        std::iter_swap(intList.begin(), std::prev(intList.end()));
        Containers::printElements(intList, "swap frist and last value:   ");
    }
}