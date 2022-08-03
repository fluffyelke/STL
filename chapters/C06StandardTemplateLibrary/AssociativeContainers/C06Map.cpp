/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "C06Map.h"
#include <map>

#include "../Utils/Utils.h"

namespace C06STL {
    void testMap() {
        
        std::map<int, std::string> myCont; //container for int/string values
        
        //insert some elements, a value with key 1 is insterted twice
        myCont = {
            {5, "tagged"},
            {2, "a"},
            {1, "this"},
            {4, "of"},
            {6, "string"},
            {1, "is"},
            {3, "map"},
        };
        
        for(auto& elem : myCont) {
            std::cout << elem.second << ' ';
        }
        
        Containers::printMaps(myCont, "Map: ");
        std::cout << std::endl;
        
    }
}