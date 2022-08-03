/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <unordered_set>

#include "../Utils/Utils.h"
#include "C06UnorderedSet.h"


namespace C06STL {
    void testUnorderedSet() {
        std::unordered_set<std::string> cities = {
            "Chicago", "New York", "Sofia", "Moscow", "Toronto", "Sofia", "Plovdiv", "Burgas"  
        };
        
        Containers::printElements(cities, "Unordered Set: ");
        
        cities.insert({"London", "Berlin", "Sofia", "Toronto"});
        
        Containers::printElements(cities, "After Insert Unordered Set: ");
    }
}