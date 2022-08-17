/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <functional>
#include <deque>

#include "SearchingElements.h"
#include "../Utils/C11Utils.h"

namespace C11Algorithms {
    void exampleFind1() {
        std::list<int> intList;
        
        C11Utils::insertElements(intList, 1, 9);
        C11Utils::insertElements(intList, 1, 9);
        
        C11Utils::printElements(intList, "intList: ");
        
        //find first element with value 4
        std::list<int>::iterator pos1;
        pos1 = std::find(intList.begin(), intList.end(),    //range
                         4);                                //value
        
        //find second element with value 4
        std::list<int>::iterator pos2;
        if(pos1 != intList.end()) {
            pos2 = std::find(++pos1, intList.end(),     //range
                            4);                         //value
        }
        
        //print all elements from first to second 4(both included)
        //-note: we need the position of first 4 again.
        if(pos1 != intList.end() && pos2 != intList.end()) {
            std::copy(--pos1, ++pos2,
                     std::ostream_iterator<int>(std::cout, " "));
        }
        std::cout << std::endl;
    }
    
    void exampleFindIfNot() {
        std::vector<int> intVec;
        std::vector<int>::iterator pos;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        //find first element greater than 3
        pos = std::find_if(intVec.begin(), intVec.end(),
                          std::bind(std::greater<int>(),   //operation, in this case operator >, if default is operator < or std::less<int>()
                                    std::placeholders::_1, //this is the value which came from intVec.begin()
                                    3));                   //value which is used to compare (intVec.begin() > 3)
        
        //print its position
        std::cout << "the "
                  << std::distance(intVec.begin(), pos) + 1
                  << ". element is the first greater than 3" << std::endl;
        
        //find first element divisible by 3
        pos = std::find_if(intVec.begin(), intVec.end(),
                           [](int elem) {
                              return elem % 3 == 0; 
                           });
                           
        //print its position
        std::cout << "the "
                  << std::distance(intVec.begin(), pos) + 1
                  << ". element is first divisable by 3" << std::endl;
        
        //find first element not < 5
        pos = std::find_if_not(intVec.begin(), intVec.end(),
                              std::bind(std::less<int>(), std::placeholders::_1, 5));
        std::cout << "first value >= 5: " << *pos << std::endl;
    }
    
    void exampleSearchN1() {
        std::deque<int> intDeque;
        intDeque = {1, 2, 7, 7, 6, 3, 9, 5, 7, 7, 7, 3, 6};
        C11Utils::printElements(intDeque);
        
        //find three consecutive elements with value 7
        std::deque<int>::iterator pos;
        pos = std::search_n(intDeque.begin(), intDeque.end(),       //range
                            3,                                      //count
                            7);                                     //value
        
        //print result
        if(pos != intDeque.end()) {
            std::cout << "three consecutive elements with value 7 "
                      << "start with " << std::distance(intDeque.begin(), pos) + 1
                      << ". element" << std::endl;
        }
        else {
            std::cout << "no four elements with value 7 found" << std::endl;
        }
        
        //found 4 consecutive odd elements
        pos = std::search_n(intDeque.begin(), intDeque.end(),       //range
                            4,                                      //count
                            0,                                      //value
                            [](int elem, int value) {               //criterion
                               return elem % 2 == 1; 
                            });
                            
        //print result
        if(pos != intDeque.end()) {
            std::cout << "first four consecutive odd elements are: ";
            for(int i = 0; i < 4; ++i, ++pos) {
                std::cout << *pos << " ";
            }    
        }
        else {
            std::cout << "no four consecutive odd elements found";
        }
        std::cout << std::endl;
    }
    
    
    void exampleSearch1() {
        std::deque<int> intDeque;
        std::list<int> intList;
        
        C11Utils::insertElements(intDeque, 1, 7);
        C11Utils::insertElements(intDeque, 1, 7);
        C11Utils::insertElements(intList, 3, 6);
        
        C11Utils::printElements(intDeque, "intDeque: ");
        C11Utils::printElements(intList,  "intList:  ");
        
        //search first occurrence of intList, in intDeque
        std::deque<int>::iterator pos;
        pos = std::search(intDeque.begin(), intDeque.end(), //range
                         intList.begin(), intList.end());    //subrange
            
        //loop while intList found as subrange of intDeque
        while(pos != intDeque.end()) {
            //print position of the first element
            std::cout << "intList found starting with element "
                      << std::distance(intDeque.begin(), pos) + 1
                      << std::endl;
            
            //search next occurrence of intList
            ++pos;
            pos = std::search(pos, intDeque.end(),                  //range
                             intList.begin(), intList.end());       //subrange
        }
    }
    //checks whether element is even or odd
    bool checkEven(int elem, bool even) {
        if(even) {
            return elem % 2 == 0;       //even
        }       
        else {
            return elem % 2 == 1;       //odd
        }
    }
    
    void exampleSearch2() {
        std::vector<int> intVec;
        C11Utils::insertElements(intVec, 1, 9);
        
        //arguments for checkEven()
        //-check for: "even odd even"
        bool checkEvenArgs[3] = {true, false, true};
        
        //search first subrange in intVec
        std::vector<int>::iterator pos;
        pos = std::search(intVec.begin(), intVec.end(),     //range
                         checkEvenArgs, checkEvenArgs + 3,  //subrange
                         checkEven);                        //subrange criterion
        
        //loop while subrange found
        while(pos != intVec.end()) {
            //print position of first elem
            std::cout << "subrange found starting with element: "
                      << std::distance(intVec.begin(), pos) + 1 << std::endl;
            //search next subrange in intVec
            pos = std::search(++pos, intVec.end(),              //range
                             checkEvenArgs, checkEvenArgs + 3,  //subrange value
                             [](int elem, bool even) {          //subrange criterion
                                 if(even) {
                                     return elem % 2 == 0;
                                 }
                                 else {
                                     return elem % 2 == 1;
                                 }
                             });                        
            
        }
    }
    
    void exampleFindEnd() {
        std::deque<int> intDeque;
        std::list<int> intList;
        
        C11Utils::insertElements(intDeque, 1, 7);
        C11Utils::insertElements(intDeque, 1, 7);
        
        C11Utils::insertElements(intList, 3, 6);
        
        C11Utils::printElements(intDeque, "intDeque: ");
        C11Utils::printElements(intList,  "intList:  ");
        
        
        //search last occurences of intList in intDeque
        std::deque<int>::iterator pos;
        pos = std::find_end(intDeque.begin(), intDeque.end(),     //range 
                            intList.begin(), intList.end());      //subrange
        
        //loop while intList found as subrange of intDeque
        std::deque<int>::iterator end(intDeque.end());
        while(pos != end) {
            //print position of first element
            std::cout << "intList found starting with element "
                      << std::distance(intDeque.begin(), pos) + 1 
                      << std::endl;
            
            //search next occurrences of intList.
            end = pos;
            pos = std::find_end(intDeque.begin(), end,              //range
                                intList.begin(), intList.end());    //subrange
        }
    }
    
    void exampleFindFirstOf() {
        std::vector<int> intVector;
        std::list<int> intList;
        
        C11Utils::insertElements(intVector, 1, 11);
        C11Utils::insertElements(intList, 3, 5);
        
        C11Utils::printElements(intVector, "intVector: ");
        C11Utils::printElements(intList,   "intList:   ");
        
        //search first occurrences of an element in intList in intVector.
        std::vector<int>::iterator pos;
        pos = std::find_first_of(intVector.begin(), intVector.end(),  //range  
                                 intList.begin(),                     //beginning of search set
                                 intList.end());                      //ending of search set.
        
        std::cout << "first element of intList in intVector is element: "
                  << std::distance(intVector.begin(), pos) + 1
                  << std::endl;
        
        //search last occurrence of an element of intList in intVector
        std::vector<int>::reverse_iterator rpos;
        rpos = std::find_first_of(intVector.rbegin(), intVector.rend(),         //range
                                 intList.begin(),                               //beginning of search set
                                 intList.end());                                //ending of search set.
        
        std::cout << "last element of intList in intVector is element: "
                  << std::distance(intVector.begin(), rpos.base())
                  << std::endl;
    }
    
    bool doubled(int elem1, int elem2) {
        return elem1 * 2 == elem2;
    }
    void exampleAdjacentFind() {
        std::vector<int> intVec = {1, 3, 2, 4, 5, 5, 0};;
        
        C11Utils::printElements(intVec, "intVec: ");
        
        //search first two elements with equal value
        std::vector<int>::iterator pos;
        pos = std::adjacent_find(intVec.begin(), intVec.end());
        
        if(pos != intVec.end()) {
            std::cout << "First two elements with equal values have position: "
                      << std::distance(intVec.begin(), pos) + 1 
                      << std::endl;
        }
        
        //search first two elements for which the second had double the value of the first
        pos = adjacent_find(intVec.begin(), intVec.end(),   //range
                           doubled);                        //criterion
        
        if(pos != intVec.end()) {
            std::cout << "First two elements with second value equal values twice the first: "
                      << std::distance(intVec.begin(), pos) + 1 
                      << std::endl;
        }
    }
    
    bool bothEvenOrOdd(int elem1, int elem2) {
        return elem1 % 2 == elem2 % 2;
    }
    
    void exampleEqual1() {
        std::vector<int> intVec;
        std::list<int> intList;
        
        C11Utils::insertElements(intVec, 1, 7);
        C11Utils::insertElements(intList, 3, 9);
        
        C11Utils::printElements(intVec,  "intVec:  ");
        C11Utils::printElements(intList, "intList: ");
        
        //check whether both collection are equal
        if(std::equal(intVec.cbegin(), intVec.cend(),           //first range
                      intList.cbegin())) {                      //second range
            std::cout << "intVec == intList" << std::endl;
        } 
        else {
            std::cout << "intVec != intList" << std::endl;
        }
        
        //check for correspondending even and odd elements
        if(std::equal(intVec.cbegin(), intVec.cend(),
                     intList.cbegin(),
                     bothEvenOrOdd)) {
            std::cout << "Even and odd elements correspond" << std::endl;
        }
        else {
            std::cout << "Even and odd elements do not correspond" << std::endl;
        }
    }
    
    void isPermutationTest() {
        std::vector<int> intVec;
        std::list<int> intList;
        std::deque<int> intDeque;
        
        intVec = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        intList = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1};
        intDeque = {11, 12, 13, 19, 18, 17, 16, 15, 14, 11};
        
        C11Utils::printElements(intVec,   "vector: ");
        C11Utils::printElements(intList,  "list:   ");
        C11Utils::printElements(intDeque, "deque:  ");
        
        //check whether both collections have euqals elements in any order
        if(std::is_permutation(intVec.cbegin(), intVec.cend(),
                               intList.cbegin())) {
            std::cout << "intVec and intList have equal elements" << std::endl;
        }
        else {
            std::cout << "intVec and intList don't have equal elements" << std::endl;
        }
        
        //check for corresponding number of even and odd elements
        if(std::is_permutation(intVec.cbegin(), intVec.cend(),
                               intDeque.cbegin(),
                               bothEvenOrOdd)) {
            std::cout << "numbers of even and odd elements match" << std::endl;
        }
        else {
            std::cout << "numbers of even and odd elements don't match" << std::endl;
        }
    }
    
    void mismatchExample() {
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6};
        std::list<int> intList = {1, 2, 4, 8, 16, 3};
        
        C11Utils::printElements(intVec,  "intVec:  ");
        C11Utils::printElements(intList, "intList: ");
        
        //find first mismatch
        auto values = std::mismatch(intVec.cbegin(), intVec.cend(),     //first range
                                    intList.cbegin());                  //second range
        
        if(values.first == intVec.end()) {
            std::cout << "no mismatch" << std::endl;
        }
        else {
            std::cout << "first mismatch: " 
                      << *values.first << " and "
                      << *values.second << std::endl;
        }
        
        
        //find first position where the element of intVec is not 
        //less than the corresponding element of intList
        values = std::mismatch(intVec.cbegin(), intVec.cend(),
                               intList.cbegin(), 
                               std::less_equal<int>());
        
        if(values.first == intVec.end()) {
            std::cout << "always less or equal" << std::endl;
        }
        else {
            std::cout << "not less or equal " 
                      << *values.first  << " and "
                      << *values.second << std::endl;
        }
    }
    
    
    void printCollection(const std::list<int>& l) {
        C11Utils::printElements(l, "list: ");
    }
    
    bool lessForCollection(const std::list<int>& l1, std::list<int>& l2) {
        return std::lexicographical_compare(l1.cbegin(), l1.cend(),
                                            l2.cbegin(), l2.cend());
    }
    
    void LexicoGraphicalCompareTest() {
        std::list<int> c1, c2, c3, c4;
        
        //fill all collections with the same starting values
        C11Utils::insertElements(c1, 1, 5);
        c4 = c3 = c2 = c1;
        
        c1.push_back(7);
        c3.push_back(2);
        c3.push_back(0);
        c4.push_back(2);
        
        
        //create collection of collections
        std::vector<std::list<int>> collVec;
        collVec.insert(collVec.begin(), {c1, c2, c3, c4, c3, c1, c4, c2} ); 
        
        //print all collections
        std::for_each(collVec.cbegin(), collVec.cend(),             //range       iterator returns std::list<int> object and pass it to printCollection
                      printCollection);                             //operation  printCollection(std::list<int>)
        
        std::cout << std::endl;
        
        //sort collection lexicographically
        std::sort(collVec.begin(), collVec.end(),       //range
                 lessForCollection);                    //sorting criterion
        
        
        //print all collections again
        std::for_each(collVec.cbegin(), collVec.cend(),
                     printCollection);
    }
    
    void isSortedExample() {
        std::vector<int> intVec = {1, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        C11Utils::printElements(intVec, "intVec: ");
        
        //check whether intVec is sorted
        if(std::is_sorted(intVec.cbegin(), intVec.cend())) {
            std::cout << "intVec is sorted!\n";
        }
        else {
            std::cout << "intVec is not sorted!\n";
        }
        
        std::map<int, std::string> mapColl;
        mapColl = {
            {1, "Bill"},
            {2, "Jim"},
            {3, "Nico"},
            {4, "Liu"},
            {5, "Ai"},
        };
        
        //define binary predicate to compare names
        auto compareName = [](const std::pair<int, std::string>& p1, const std::pair<int, std::string>& p2) {
            return p1.second < p2.second;
        };
        
        //check whether the names in mapColl are sorted
        if(std::is_sorted(mapColl.cbegin(), mapColl.cend(),
                         compareName)) {
            std::cout << "Names in mapColl are sorted!\n";
        }
        else {
            std::cout << "Names in mapColl are NOT sorted!\n";
        }
        
        //print first unsorted name
        auto pos = std::is_sorted_until(mapColl.cbegin(), mapColl.cend(),
                                        compareName);
        if(pos != mapColl.end()) {
            std::cout << "First unsorted name: " << pos->second << std::endl;
        }
    } 
    
    void isPartitionedExample() {
        std::vector<int> intVec = {5, 3, 9, 1, 3, 4, 8, 2, 6};
        C11Utils::printElements(intVec, "intVec: ");
        
        //define unary predicate check whether element is odd
        auto isOdd = [](int elem) {
            return elem % 2 == 1;
        };
        
        //check whether intVec is partitioned in odd and even elements;
        if(std::is_partitioned(intVec.cbegin(), intVec.cend(),  //range
                              isOdd)){                          //predicate
            std::cout << "intVec is partitioned\n";
            
            //find first even element
            auto pos = std::partition_point(intVec.cbegin(), intVec.cend(),
                                           isOdd);
            std::cout << "First even element: " << *pos << std::endl;
        }
        else {
            std::cout << "intVec is not partitioned\n";
        }
    }
    
    void isHeapExample() {
        std::vector<int> intVec1 = {9, 8, 7, 7, 7, 5, 4, 2, 1};
        std::vector<int> intVec2 = {5, 3, 2, 1, 4, 7, 9, 8, 6};
        
        C11Utils::printElements(intVec1, "intVec1: ");
        C11Utils::printElements(intVec2, "intVec2: ");
        
        //check whether collections are heap
        std::cout << std::boolalpha << "intVec1 is heap: " << std::is_heap(intVec1.cbegin(), intVec1.cend()) << std::endl;
        std::cout << std::boolalpha << "intVec2 is heap: " << std::is_heap(intVec2.cbegin(), intVec2.cend()) << std::endl;
        
        //print first element that is not heap
        auto pos = std::is_heap_until(intVec2.cbegin(), intVec2.cend());
        if(pos != intVec2.end()) {
            std::cout << "first non-heap element: " << *pos << std::endl;
        }
    }
    
    void allAnyNoneTest() {
        std::vector<int> intVec;
        std::vector<int>::iterator pos;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        //define a object for the predicate
        auto isEven = [](int elem) {
            return elem % 2 == 0;
        };
        
        //print whether all, any or none of the elements are even
        std::cout << std::boolalpha << "all even? "
                  << std::all_of(intVec.cbegin(), intVec.cend(),
                                 isEven) << std::endl;
        
        std::cout << std::boolalpha << "any even? "
                  << std::any_of(intVec.cbegin(), intVec.cend(),
                                 isEven) << std::endl;
        
        std::cout << std::boolalpha << "none even? "
                  << std::none_of(intVec.cbegin(), intVec.cend(),
                                 isEven) << std::endl;

    }
}