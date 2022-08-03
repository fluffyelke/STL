/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <list>
#include <iostream>
#include "../Utils/Utils.h"
#include "C06List.h"


namespace C06STL {
    void testList() {
        std::list<char> myCont;
        
        for(char c = 'a'; c <= 'z'; c++) {
            myCont.push_back(c);
        }
        
        Containers::printElements(myCont, "List: ");
        std::cout << std::endl;
        for(auto elem : myCont) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
        
        //another way to print all elements of list
        while(!myCont.empty()) {
            std::cout << myCont.front() << " ";
            myCont.pop_front();
            
        }
        std::cout << std::endl;
    }
}