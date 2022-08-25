/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <vector>
#include <random>
#include <iterator>
#include <deque>

#include "../Utils/C11Utils.h"
#include "SortedRangeAlgs.h"


namespace C11Algorithms {
    
    void binarySearchExample() {
        std::list<int> intList;
        
        C11Utils::insertElements(intList, 1, 9);
        C11Utils::printElements(intList);
        
        //check existence of element with value 5.
        if(std::binary_search(intList.cbegin(), intList.cend(),
                              5)) {
            std::cout << "elem 5 is present" << std::endl;
        }
        else {
            std::cout << "elem 5 is not present" << std::endl;
        }
        
        
        //check existence of element 45
        if(std::binary_search(intList.cbegin(), intList.cend(),
                              42)) {
            std::cout << "elem 42 is present" << std::endl;
        }
        else {
            std::cout << "elem 42 is not present" << std::endl;
        }
    }
    
    void includesExample() {
        std::list<int> coll;
        std::vector<int> search;
        
        C11Utils::insertElements(coll, 1, 9);
        C11Utils::printElements(coll,   "coll:   ");
        
        search.push_back(3);
        search.push_back(4);
        search.push_back(7);
        C11Utils::printElements(search, "search: ");
        
        //check whether all elements in search are also in coll
        if(std::includes(coll.cbegin(), coll.cend(),
                         search.cbegin(), search.cend())) {
            std::cout << "All elements of search are also in coll" << std::endl;
        }
        else {
            std::cout << "Not all elements of search are also in coll" << std::endl;
        }
    } 
    
    void boundExamples() {
        std::list<int> intList;
        C11Utils::insertElements(intList, 1, 9);
        C11Utils::insertElements(intList, 1, 9);
        intList.sort();
        
        C11Utils::printElements(intList);
        
        //print first and last position 5 could get inserted
        auto pos1 = std::lower_bound(intList.cbegin(), intList.cend(),
                                     5);
        auto pos2 = std::upper_bound(intList.cbegin(), intList.cend(),
                                     5);
        
        std::cout << "5 could get position "
                  << std::distance(intList.cbegin(), pos1) + 1 
                  << " up to "
                  << std::distance(intList.cbegin(), pos2) + 1
                  << " without breaking the sorting " << std::endl;
        
        //insert 3 at first possible position without breaking the sort
        intList.insert(std::lower_bound(intList.begin(), intList.end(),
                                        3),
                       3);
        
        //insert 7 at the last possible position without breaking the sort
        intList.insert(std::upper_bound(intList.begin(), intList.end(),
                                        7),
                       7);
        C11Utils::printElements(intList);
    }
    
    void equalRange() {
        std::list<int> intList;
        C11Utils::insertElements(intList, 1, 9);
        C11Utils::insertElements(intList, 1, 9);
        intList.sort();
        
        C11Utils::printElements(intList);
        
        //print first and last position 5 could get inserted
        std::pair<std::list<int>::const_iterator, std::list<int>::const_iterator> range;
        range = std::equal_range(intList.begin(), intList.end(),
                                 5);
        
        std::cout << "5 could get position "
                  << std::distance(intList.cbegin(), range.first) + 1 
                  << " up to "
                  << std::distance(intList.cbegin(), range.second) + 1
                  << " without breaking the sorting " << std::endl;
    }
    
    void mergeExample() {
        std::list<int> intList;
        std::set<int> intSet;
        
        //fill both collections with some sorted elements
        C11Utils::insertElements(intList, 1, 6);
        C11Utils::insertElements(intSet, 3, 8);
        
        C11Utils::printElements(intList, "intList: ");
        C11Utils::printElements(intSet,  "intSet:  ");
        
        //print merged sequence
        std::cout << "merged: ";
        std::merge(intList.cbegin(), intList.cend(),
                   intSet.cbegin(), intSet.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
        
        std::cout << std::endl;
    }
    
    void mergingExamples() {
        std::vector<int> c1 = {1, 2, 2, 4, 6, 7, 7, 9};
        std::deque<int> c2 = {2, 2, 2, 3, 6, 6, 8, 9};
        
        //print source ranges
        std::cout << "c1:                         ";
        std::copy(c1.cbegin(), c1.cend(),
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        std::cout << "c2:                         ";
        std::copy(c2.cbegin(), c2.cend(),
                  std::ostream_iterator<int>(std::cout, " "));
        std::cout << '\n' << std::endl;
        
        //sum the ranges by using merge()
        std::cout << "merge():                    ";
        std::merge(c1.cbegin(), c1.cend(),
                   c2.cbegin(), c2.cend(),
                   std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //unite the ranges by using set_union()
        std::cout << "set_union():                ";
        std::set_union(c1.cbegin(), c1.cend(),
                       c2.cbegin(), c2.cend(),
                       std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //intersect the ranges by using set_intersection()
        std::cout << "set_intersection():         ";
        std::set_intersection(c1.cbegin(), c1.cend(),
                              c2.cbegin(), c2.cend(),
                              std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //determine elements of first range without elements of second range by using set_difference()
        std::cout << "set_difference():           ";
        std::set_difference(c1.cbegin(), c1.cend(),
                            c2.cbegin(), c2.cend(),
                            std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
        
        //determine difference the ranges by using set_symmetric_difference()
        std::cout << "set_symmetric_difference(): ";
        std::set_symmetric_difference(c1.cbegin(), c1.cend(),
                                      c2.cbegin(), c2.cend(),
                                      std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    
    void inplaceMergeExample() {
        std::list<int> intList;
        
        C11Utils::insertElements(intList, 1, 7);
        C11Utils::insertElements(intList, 1, 8);
        C11Utils::printElements(intList, "intList: ");
        
        //find beginning of second part
        std::list<int>::iterator pos;
        pos = std::find(intList.begin(), intList.end(),     //range
                        7);                                 //value
        ++pos;
        
        //merge into one sorted range
        std::inplace_merge(intList.begin(), pos, 
                           intList.end());
        C11Utils::printElements(intList, "intList: ");
    }
}