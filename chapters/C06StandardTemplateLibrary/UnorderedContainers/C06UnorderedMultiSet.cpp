/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unordered_set>

#include "C06UnorderedMultiSet.h"
#include "../Utils/Utils.h"

namespace C06STL {
    void testUnorderedMultiSet() {
        std::unordered_multiset<std::string> cities = {
            "Chicago", "New York", "Sofia", "Moscow", "Toronto", "Sofia", "Plovdiv", "Burgas"  
        };
        
        Containers::printElements(cities, "Unordered Multiset: ");
        
        cities.insert({"London", "Berlin", "Sofia", "Toronto"});
        
        Containers::printElements(cities, "After Insert Unordered Multiset: ");
    }
}