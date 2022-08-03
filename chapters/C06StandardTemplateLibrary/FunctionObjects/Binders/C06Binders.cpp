/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <set>
#include <deque>
#include <algorithm>
#include <functional>

#include "C06Binders.h"
#include "../../Utils/Utils.h"

namespace C06STL {
    void bindersExample() {
        std::set<int, std::greater<int>> mySetCont{1, 2, 3, 4, 5, 6, 7, 8, 9};
        std::deque<int> myDequeCont;
        
        //due to sort criterion greater<int> elements are in reverse order
        Containers::printElements(mySetCont, "init set: ");
        
        //transform all elements into myDequeCont, by multiply by 10
        std::transform(mySetCont.cbegin(), mySetCont.cend(),        //source
                        std::back_inserter(myDequeCont),            //destination
                        std::bind(std::multiplies<int>(),std::placeholders::_1, 10));   //operation
        Containers::printElements(myDequeCont, "transformed deque: ");
        
        //replace value equal to 70 with 42
        std::replace_if(myDequeCont.begin(), myDequeCont.end(),                     //range
                        std::bind(std::equal_to<int>(), std::placeholders::_1, 70), //replace criterion
                        42);                    //new value
        
        Containers::printElements(myDequeCont, "replaced with 42 deque: ");
        
        //remove all elements between 50 and 80
        myDequeCont.erase(std::remove_if(myDequeCont.begin(), myDequeCont.end(),                    //source
                                         std::bind(std::logical_and<bool>(),
                                                std::bind(std::greater_equal<int>(), std::placeholders::_1, 50),
                                                std::bind(std::less_equal<int>(), std::placeholders::_1, 80))),
                         myDequeCont.end());
        
        Containers::printElements(myDequeCont, "removed deque: ");
    }
}