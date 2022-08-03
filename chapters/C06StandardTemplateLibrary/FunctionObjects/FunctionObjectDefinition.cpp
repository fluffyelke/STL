/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "FunctionObjectDefinition.h"
#include "../Utils/Utils.h"

namespace C06STL {
    void exampleAddValueFuncCall() {
        std::list<int> myCont;
        for(int i = 1; i <= 9; i++) {
            myCont.push_back(i);
        }
        Containers::printElements(myCont, "initial list: ");
        
        //add value to each element
        std::for_each(myCont.begin(), myCont.end(), //range
                    AddValue(33));                  //operation 
        
        Containers::printElements(myCont, "after adding 33 to list: ");
        
        //add value of first element to all elements in list
        std::for_each(myCont.begin(), myCont.end(),     //range
                    AddValue(*myCont.begin()));         //operation
        
        Containers::printElements(myCont, "after adding first element list: ");
    }
}