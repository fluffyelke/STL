/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <set>

#include "../Utils/Utils.h"
#include "C06Multiset.h"

namespace C06STL {
    void testMultiset() {
        std::multiset<std::string> cities = {
          "Chicago", "New York", "Sofia", "Moscow", "Toronto", "Sofia", "Plovdiv", "Burgas"  
        };

        Containers::printElements(cities, "Multiset: ");

        cities.insert({"London", "Berlin", "Sofia", "Toronto"});

        Containers::printElements(cities, "After Insert Multiset: ");
    }
    
}