/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include "../C06StandardTemplateLibrary/Utils/Utils.h"
#include "InsertIterators.h"


namespace C09Iterators {
    void backInserterTest() {
        std::vector<int> intVec;
        
        //create back inserter
        // inconvenient way
        std::back_insert_iterator<std::vector<int>> iter(intVec);
        //insert elements with the usual iterator interface
        *iter = 1;
        iter++;
        *iter = 2;
        iter++;
        *iter = 3;
        iter++;
        Containers::printElements(intVec, "1 intVec: ");
        
        //create back inserter and insert elements
        //convenient way
        std::back_inserter(intVec) = 44;
        std::back_inserter(intVec) = 55;
        Containers::printElements(intVec, "2 intVec: ");
        
        // use back inserter to append all elements again
        // reserve enough memory to avoid reallocation
        intVec.reserve(2 * intVec.size());
        std::copy(intVec.begin(), intVec.end(),     //source
                 std::back_inserter(intVec));       //destination
        Containers::printElements(intVec, "3 intVec: ");
        
    }
    
    void frontInserterTest() {
        std::list<int> intList;
        
        //create front inserter
        // inconvenient way
        std::front_insert_iterator<std::list<int>> iter(intList);
        //insert elements with the usual iterator interface
        *iter = 1;
        iter++;
        *iter = 2;
        iter++;
        *iter = 3;
        iter++;
        Containers::printElements(intList, "1 intVec: ");
        
        //create front inserter and insert elements
        //convenient way
        std::front_inserter(intList) = 44;
        std::front_inserter(intList) = 55;
        Containers::printElements(intList, "2 intVec: ");
        
        // use front inserter to append all elements again
        std::copy(intList.begin(), intList.end(),     //source
                 std::front_inserter(intList));       //destination
        Containers::printElements(intList, "3 intVec: ");
        
    }
    
    void inserterTest() {
        std::set<int> intSet;
        
        //create insert iterator for intSet
        // inconvenient way
        std::insert_iterator<std::set<int>> iter(intSet, intSet.begin());
        //insert elements with the usual iterator interface
        *iter = 1;
        iter++;
        *iter = 2;
        iter++;
        *iter = 3;
        iter++;
        Containers::printElements(intSet, "1 intSet: ");
        
        //create front inserter and insert elements
        //convenient way
        std::inserter(intSet, intSet.begin()) = 44;
        std::inserter(intSet, intSet.begin()) = 55;
        Containers::printElements(intSet, "2 intSet: ");
        
        
        //use insterter to insert all elements into list
        std::list<int> intList;
        std::copy(intSet.begin(), intSet.end(),             //source
                 std::inserter(intList, intList.begin()));  //destination
        Containers::printElements(intList, "3 intList: ");
        
        // use inserter to reinsert all elements into the list before second element.
        std::copy(intSet.begin(), intSet.end(),     //source
                 std::inserter(intList, ++intList.begin()));       //destination
        Containers::printElements(intList, "4 intList: ");
    }
}