/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <forward_list>

#include "C06ForwardList.h"
#include "../Utils/Utils.h"

namespace C06STL {
    void testForwardList() {
        std::forward_list<long> myCont = {2, 3, 5, 7, 11, 13, 17};
        
        //resize 2 times
        //poor performance
        myCont.resize(9);
        myCont.resize(10, 99);
        
        Containers::printElements(myCont, "Forward List: ");
    }
}