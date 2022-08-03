/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

#include "C06FuncAsAlgArg.h"
#include "../../Utils/Utils.h"

namespace C06STL {
    void print(int elem) {
        std::cout << elem << " ";
    }
    
    void testFunctionAsAlgorithmArgument() {
        std::vector<int> myCont;
        for(int i = 1; i <= 9; ++i) {
            myCont.push_back(i);
        }
        
        //print all elements
        std::for_each(myCont.cbegin(), myCont.cend(),   //range
            print);         //operation
        std::cout << std::endl;
    }
    
    int square(int value) {
        return value * value;
    }
    void testTransform1() {
        std::set<int> setCont;
        std::vector<int> vecCont;
        
        for(int i = 1; i <= 9; i++) {
            setCont.insert(i);
        }
        
        Containers::printElements(setCont, "init set: ");
        
        //transform each element from setCont to vecCont,
        //- square transform values
        std::transform(setCont.cbegin(), setCont.cend(),    //source
                        std::back_inserter(vecCont),        //destination
                        square);                            //operation
        
        Containers::printElements(vecCont, "squared vector: ");
    }
}