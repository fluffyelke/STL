/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <deque>
#include <algorithm>
#include <functional>

#include "PreDefinedExamples.h"
#include "../../Utils/Utils.h"

namespace C06STL {
    void negateExample() {
        std::deque<int> myCont{1, 3, 5, 7, 11, 13, 17, 19};
        Containers::printElements(myCont, "init Deque: ");
        
        //negate all values in myCont
        std::transform(myCont.begin(), myCont.end(),    //source
            myCont.begin(),                             //destination
            std::negate<>());                           //operation
        Containers::printElements(myCont, "After negate Deque: ");
        
        //square all values in myCont
        std::transform(myCont.cbegin(), myCont.cend(),    //first source
            myCont.cbegin(),                             //second source
            myCont.begin(),                             //destination
            std::multiplies<int>());                    //operation
        
        Containers::printElements(myCont, "After Square Deque: ");
        
    }
}