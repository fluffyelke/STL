/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unordered_map>
#include "../Utils/Utils.h"
#include "C06UnorderedMultiMap.h"


namespace C06STL {
    void testUnorderedMultiMap() {
        std::unordered_multimap<std::string, double> myCont {
            {"tim", 9.9},
            {"struppi", 11.77},
            {"tim", 19.9},
        };
        
        Containers::printMaps(myCont, "Before Square MultiMap: ");
        //square the value of each element
        for(std::pair<const std::string, double>& elem : myCont) {
            elem.second *= elem.second;
        }
        Containers::printMaps(myCont, "After Square MultiMap: ");
    }
}