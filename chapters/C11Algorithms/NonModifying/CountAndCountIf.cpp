/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include "../Utils/C11Utils.h"
#include "CountAndCountIf.h"


namespace C11Algorithms {
    void testCount1() {
        std::vector<int> intVec;
        int num;
        C11Utils::insertElements(intVec,1 ,9);
        
        C11Utils::printElements(intVec, "intVec: ");
        
        //count elements with value 4
        num = std::count(intVec.cbegin(), intVec.cend(),        //range
            4);                                                 //value
        std::cout << "number of elements equal to 4: " << num << std::endl;
        
        //count elements with even value
        num = std::count_if(intVec.begin(), intVec.end(),   //range
                           [](int elem) {                   //criterion
                              return elem % 2 == 0; 
                           });
        std::cout << "number of elements with even value: " << num << std::endl;
        
        //count elements that are greater than 4
        num = std::count_if(intVec.cbegin(), intVec.cend(),
                            [](int elem) {
                               return elem > 4; 
                            });
        std::cout << "number of elements GREATER than 4: " << num << std::endl;
    }
}