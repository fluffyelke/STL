/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <array>
#include <numeric>
#include <algorithm>

#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "ArrayInSTD.h"


namespace C07Containers {
    void arraysExample() {
        std::array<int, 10> myArr = {11, 22, 33, 44};
        
        Containers::printElements(myArr, "init array: ");
        
        //modify last 2 elements
        myArr.back() = 9999999;
        myArr[myArr.size() - 2] = 42;
        
        Containers::printElements(myArr, "after modify array: ");
        
        //process sum of all elements
        std::cout << "sum: " << std::accumulate(myArr.begin(), myArr.end(), 0) << std::endl;
        
        //negate all elements
        std::transform(myArr.begin(), myArr.end(),      //source
                       myArr.begin(),                   //destination
                       std::negate<int>());             //operation
        
        Containers::printElements(myArr, "After negate: ");
    }
}