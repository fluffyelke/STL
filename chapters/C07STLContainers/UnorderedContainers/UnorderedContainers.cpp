/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <numeric>

#include "UnorderedContainers.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"
#include "Utils/BucketInterface.h"

namespace C07Containers {
    void exampleOfUnorderedSet() {
        //create and initialize unordered set
        std::unordered_set<int> myUnorderedSet = {1, 3, 5, 7, 11, 13, 17, 19, 77};
        
        //print elements
        //- elements are at arbitrary orders
        Containers::printElements(myUnorderedSet, "myUnorderedSet init: ");
        
        //insert some additional elements
        //-might cause rehashing and create different order
        myUnorderedSet.insert({-7, 17, 33, -11, 17, 19, 1, 13});
        Containers::printElements(myUnorderedSet, "myUnorderedSet insert: ");
        
        //remove element with specific value
        myUnorderedSet.erase(33);
        
        //insert sum of all existing values
        myUnorderedSet.insert(std::accumulate(myUnorderedSet.begin(), myUnorderedSet.end(), 0));
        Containers::printElements(myUnorderedSet, "myUnorderedSet sum insert: ");
        
        //check if value 19 is in the set
        if(myUnorderedSet.find(19) != myUnorderedSet.end()) {
            std::cout << "19 is avaible" << std::endl;
        }
        
        //remove all negative values
        std::unordered_set<int>::iterator pos;
        for(pos = myUnorderedSet.begin(); pos != myUnorderedSet.end(); ) {
            if(*pos < 0) {
                pos = myUnorderedSet.erase(pos);
            }
            else {
                ++pos;
            }
        }
        Containers::printElements(myUnorderedSet, "myUnorderedSet end: ");
    }
    
    void exampleOfUnorderedMultiset() {
        //create initialize expand and print unordered multiset
        std::unordered_multiset<int> myUnordMultiSet = {1, 2, 3, 5, 7, 11, 13, 17, 19, 77};
        myUnordMultiSet.insert({-7, 17, 33, -11, 17, 19, 1, 13});
        Containers::printElements(myUnordMultiSet, "1 myUnordMultiSet: ");
        
        //remove all elements with specific value
        myUnordMultiSet.erase(17);
        
        //remove one element with specific value
        auto pos = myUnordMultiSet.find(13);
        if(pos != myUnordMultiSet.end()) {
            myUnordMultiSet.erase(pos);
        }
        Containers::printElements(myUnordMultiSet, "2 myUnordMultiSet: ");
    }
    
    void testBucketInterface() {
        std::unordered_set<int> mySet = {1, 2, 3, 5, 7, 11, 13, 17, 19};
        C07Containers::printHashTableState(mySet);
        
        //insert some aditional data, can cause rehashing
        mySet.insert({-7, 17, 33, 4}); 
        C07Containers::printHashTableState(mySet);
    }
    
    void unordMultiMapHash() {
        //create and init unordered map as dictionary
        std::unordered_multimap<std::string, std::string> dict = {
            {"day", "Tag"},
            {"strange", "fremd"},
            {"car", "Auto"},
            {"smart", "elegant"},
            {"trait", "Merkmal"},
            {"strange", "seltsam"},
        };
        C07Containers::printHashTableState(dict);
        std::cout << "\n\n===============\n\n";
        
        dict.insert({
            {"smart", "raffiniert"},
            {"smart", "klug"},
            {"clever", "raffiniert"},
        });
        C07Containers::printHashTableState(dict);
        std::cout << "\n\n===============\n\n";
        
        //modify maximum load factor, can cause rehashing
        dict.max_load_factor(0.7);
        C07Containers::printHashTableState(dict);
    }
}