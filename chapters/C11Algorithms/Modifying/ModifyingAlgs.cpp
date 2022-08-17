/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <iterator>
#include <functional>
#include <deque>

#include "../Utils/C11Utils.h"
#include "ModifyingAlgs.h"

namespace C11Algorithms {
    void copyExample() {
        std::vector<std::string> strVec = {"Hello", "this", "is", "an", "example"};
        std::list<std::string> strList;
        
        //copy elements of strVec to strList
        // use back inserter to insert instead of overwrite
        std::copy(strVec.cbegin(), strVec.cend(),       //source range
                  std::back_inserter(strList));         //destination range
        
        //print elements of strList;
        //copy elements to std::cout using std::ostream_iterator
        std::copy(strList.cbegin(), strList.cend(),                     //source range
                  std::ostream_iterator<std::string>(std::cout, " "));  //destination range
        std::cout << std::endl;
        
        //copy elements of strVec into strList in reverse order
        //now overwriting
        std::copy(strVec.crbegin(), strVec.crend(),                       //source range
                 strList.begin());                                      //destination range
        
        //print elements of strList again   
        std::copy(strList.cbegin(), strList.cend(),                     //source range
                 std::ostream_iterator<std::string>(std::cout, " "));   //destination range
        std::cout << std::endl;
    }
    
    void copyExample2() {
        //initialize source collection with "........abcdef......."
        std::vector<char> source(10, '.');
        for(int c = 'a'; c <= 'f'; c++) {
            source.push_back(c);
        }
        source.insert(source.end(), 10, '.');
        
        C11Utils::printElements(source, "source: ");
        
        //copy all letters three elements infront of a
        std::vector<char> c1(source.cbegin(), source.cend());
        std::copy(c1.cbegin() + 10, c1.cbegin() + 16,           //source range
                 c1.begin() + 7);                               //destination range
        C11Utils::printElements(c1,     "c1      ");
        
        //copy all letters 3 elements behind 'f'
        std::vector<char> c2(source.cbegin(), source.cend());
        std::copy_backward(c2.cbegin() + 10, c2.cbegin() + 16,      //source range
                           c2.begin() + 19);                        //destination range
        C11Utils::printElements(c2,     "c2:     ");
    }
    
    
    void copyExample3() {
        std::copy(std::istream_iterator<std::string>(std::cin),             //source beg
                  std::istream_iterator<std::string>(),                     //source end
                  std::ostream_iterator<std::string>(std::cout, " "));      //destination source
    }
    
    void moveExample() {
        std::vector<std::string> strVec = {"Hello", "this", "is", "an", "example"};
        std::list<std::string> strList;
        
        //copy elements of strVec to strList
        //use back inserter instead of overwrite
        //use std::copy because elements of strVec are used again
        std::copy(strVec.cbegin(), strVec.cend(),     //source range      
                  std::back_inserter(strList));       //destination range
        
        //print elements of strList;
        //copy elements to std::cout using std::ostream_iterator
        //use std::move() because the elements of strList are not used again
        std::move(strList.cbegin(), strList.cend(),                     //source range      
                  std::ostream_iterator<std::string>(std::cout, " "));  //destination range
        std::cout << std::endl;
        
        //copy elements of strVec into strList in reverse order
        //now overwriting(strList.size(), still fits)
        //use std::move() vecause elements of strVec are not used again
        std::move(strVec.crbegin(), strVec.crend(),         //source range
                  strList.begin());                         //destination range
        
        //print elements of strList;
        //copy elements to std::cout using std::ostream_iterator
        //use std::move() because the elements of strList are not used again
        std::move(strList.cbegin(), strList.cend(),                     //source range      
                  std::ostream_iterator<std::string>(std::cout, " "));  //destination range
        std::cout << std::endl;
    }
    
    void transformExample() {
        std::vector<int> intVec;
        std::list<int> intList;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec:  ");
        
        //negate all elements in intVec
        std::transform(intVec.begin(), intVec.end(),        //source range
                       intVec.begin(),                      //destination range
                       std::negate<int>());                 //operation
        C11Utils::printElements(intVec, "negated: ");
        
        
        //transform elements from intVec into intList with ten times their value
        std::transform(intVec.begin(), intVec.end(),                                //source range
                       std::back_inserter(intList),                                 //destination range
                       std::bind(std::multiplies<int>(),std::placeholders::_1, 10));//operation
        C11Utils::printElements(intList, "intList: ");
        
        //print intList negatively and in reverse order
        std::transform(intList.crbegin(), intList.crend(),
                      std::ostream_iterator<int>(std::cout, " "),
                      [](int elem) {
                          return -elem;
                      });
        std::cout << std::endl;
    }
    
    void transformExample2() {
        std::vector<int> intVec;
        std::list<int> intList;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::printElements(intVec, "intVec: ");
        
        //square each element
        std::transform(intVec.cbegin(), intVec.cend(),      //first source range
                       intVec.cbegin(),                     //second source range
                       intVec.begin(),                      //destination range
                       [](int first, int second) {          //operation    int first = intVec.begin() first source range, 
                          return first * second;            //operation    int second = intVec.begin() second source range.
                       });
        C11Utils::printElements(intVec, "squared: "); 
        
//        //square each element
//        std::transform(intVec.cbegin(), intVec.cend(),      //first source range
//                       intVec.cbegin(),                     //second source range
//                       intVec.begin(),                      //destination range
//                       std::multiplies<>());                //operation equals to the previous lambda example 
//        C11Utils::printElements(intVec, "squared: "); 
        
        //add each element traversed forward with each element traversed backward
        //and insert results into intList;
        std::transform(intVec.cbegin(), intVec.cend(),      //first source range
                        intVec.crbegin(),                   //second source range
                        std::back_inserter(intList),        //destination range
                        std::plus<>());                     //operation
        C11Utils::printElements(intList, "intList: ");
        
         //add each element traversed forward with each element traversed backward
        //and insert results into intList; lamda example
//        std::transform(intVec.cbegin(), intVec.cend(),      //first source range
//                        intVec.crbegin(),                   //second source range
//                        std::back_inserter(intList),        //destination range
//                        [](int first, int second) {         //operation
//                            return first + second;   
//                        });                     
//        C11Utils::printElements(intList, "intList: ");
        
        //print differences of two corresponding elements
        std::cout << "diff:     ";                      
        std::transform(intVec.cbegin(), intVec.cend(),                  //first source
                       intList.cbegin(),                                //second source
                       std::ostream_iterator<int>(std::cout, " "),      //destination
                       std::minus<>());                                 //operation
        std::cout << std::endl;
        
    }
    
    void swapRangesExample() {
        std::vector<int> intVec;
        std::deque<int> intDeq;
        
        C11Utils::insertElements(intVec, 1, 9);
        C11Utils::insertElements(intDeq, 11, 23);
        
        C11Utils::printElements(intVec, "intVec: ");
        C11Utils::printElements(intDeq, "intDeq: ");
        
        //swap elements of intVec with corresponding elements of intDeq
        std::deque<int>::iterator pos;
        pos = std::swap_ranges(intVec.begin(), intVec.end(),            //first range
                               intDeq.begin());                         //second range
        
        C11Utils::printElements(intVec, "\nintVec: ");
        C11Utils::printElements(intDeq, "intDeq: ");
        
        if(pos != intDeq.end()) {
            std::cout << "First element not modified: " << *pos << std::endl;
        }
        
        //mirror first 3 with last 3 element in intDeq;
        std::swap_ranges(intDeq.begin(), intDeq.begin() + 3,        //first range
                         intDeq.rbegin());                          //second range
        C11Utils::printElements(intDeq, "\nintDeq: ");
    }
    
    void fillExample() {
        //print ten times 7.7
        std::fill_n(std::ostream_iterator<double>(std::cout, " "), //beginning of destination
                    10,                                         //count 
                    7.7);                                       //new value.
        
        std::cout << std::endl;
        
        std::list<std::string> strList;
        //insert hello ten times
        std::fill_n(std::back_inserter(strList),    //beginning of destination
                   10,                              //count 
                   "Hello");                        //new value.
        C11Utils::printElements(strList, "strList: ");
        
        //overwrites all elements with "again"
        std::fill(strList.begin(), strList.end(),   //destination
                  "again");                         //new value
        C11Utils::printElements(strList, "strList: ");
        
        //replace all but 2 elements with "hi"
        std::fill_n(strList.begin(),            //beginning of destination
                    strList.size() - 2,          //count 
                    "hi");                      //new value.
        C11Utils::printElements(strList, "strList: ");
        
        //replace the second and up to the last element but one with "hmmm"
        std::list<std::string>::iterator pos1, pos2;
        pos1 = strList.begin();
        pos2 = strList.end();
        std::fill(++pos1, --pos2,       //destination
                 "hmmm");               //new value
        C11Utils::printElements(strList, "strList: ");
    }
    
    void generateExample() {
        std::list<int> intList;
        
        std::generate_n(std::back_inserter(intList),        //beginning of destination range
                        5,                                  //count
                        std::rand);                         //new value generator
        C11Utils::printElements(intList, "intList: ");
        
        //overwrite with five new random numbers
        std::generate(intList.begin(), intList.end(),       //destination
                      std::rand);                           //new value generator
        C11Utils::printElements(intList, "intList: ");
        
        //overwrite with five new random numbers
        std::generate(intList.begin(), intList.end(),       //destination
                      []() {
                          return std::rand() % 100;
                      });                           //new value generator
        C11Utils::printElements(intList, "intList: ");
    }
    
    void iotaExample() {
        std::array<int, 10> intArr;
        std::iota(intArr.begin(), intArr.end(),         //destination range
                  42);                                  //start value
        C11Utils::printElements(intArr, "intArr: ");
    }
    
    void replaceExample() {
        std::list<int> intList;
        
        C11Utils::insertElements(intList, 2, 7);
        C11Utils::insertElements(intList, 4, 9);
        
        C11Utils::printElements(intList, "intList: ");
        
        //replace all elements with value 6 with 42
        std::replace(intList.begin(), intList.end(),        //range
                     6,                                     //old value
                     42);                                   //new value
        C11Utils::printElements(intList, "intList: ");
        
        //replace all elements with value less than 5 with 0
        std::replace_if(intList.begin(), intList.end(),     //range
                        [](int elem) {                      //criterion for replacement
                            return elem < 5;            
                        },  
                        0);                                 // new value
        C11Utils::printElements(intList, "intList: ");
    }
    
    void replaceExample2() {
        std::list<int> intList;
        
        C11Utils::insertElements(intList, 2, 6);
        C11Utils::insertElements(intList, 4, 9);
        
        C11Utils::printElements(intList, "intList: ");
        
        //print all elements with value 5 replaced with 55.
        std::replace_copy(intList.begin(), intList.end(),               //source
                          std::ostream_iterator<int>(std::cout, " "),   //destination
                          5,                                            //old value
                          55);                                          //new value.
        std::cout << std::endl;
        //print all elements with a value less than 5 with 42
        std::replace_copy_if(intList.begin(), intList.end(),                        //source
                             std::ostream_iterator<int>(std::cout, " "),            //destination
                             std::bind(std::less<>(), std::placeholders::_1, 5),     //operation
                             42);                                                   //new value.
        std::cout << std::endl;
        //print each element while each odd element is replaced by 0
        std::replace_copy_if(intList.begin(), intList.end(),                //source
                             std::ostream_iterator<int>(std::cout, " "),    //destination
                             [](int elem) {                                 //operation
                                 return elem % 2 == 1;
                             },
                             0);                                            //new value.
        std::cout << std::endl;
    }
    
    void removeExample() {
        std::vector<int> intVec;
        
        C11Utils::insertElements(intVec, 2, 6);
        C11Utils::insertElements(intVec, 4, 9);
        C11Utils::insertElements(intVec, 1, 7);
        
        C11Utils::printElements(intVec, "intVec:           ");
        
        //remove all elements with 5
        std::vector<int>::iterator pos;
        pos = std::remove(intVec.begin(), intVec.end(),     //range 
                          5);                               //value to remove
        C11Utils::printElements(intVec, "size not changed: ");
        
        //erased the "removed" element in the container
        intVec.erase(pos, intVec.end());
        C11Utils::printElements(intVec, "size changed:     ");
        
        //remove all elements with less than 4
        intVec.erase(std::remove_if(intVec.begin(), intVec.end(),   //range
                                    [](int elem) {                  //remove criterion
                                        return elem < 4;
                                    }),
                     intVec.end());
        C11Utils::printElements(intVec, "4 < removed:      ");                            
    }
    
    void removeCopyExample() {
        std::list<int> intList;
        C11Utils::insertElements(intList, 1, 6);
        C11Utils::insertElements(intList, 1, 9);
        C11Utils::printElements(intList);
        
        //print elements without those having value 3
        std::remove_copy(intList.cbegin(), intList.cend(),              //source
                         std::ostream_iterator<int>(std::cout, " "),    //destination
                         3);                                            //removed value
        std::cout << std::endl;
        
        //copy all elements not less than 4 into the multiset
        std::multiset<int> intMultiSet;
        std::remove_copy_if(intList.cbegin(), intList.cend(),                   //source
                            std::inserter(intMultiSet, intMultiSet.end()),      //destination
                            std::bind(std::less<int>(), std::placeholders::_1, 4));    //operation
        C11Utils::printElements(intMultiSet);
    }
    
    void uniqueExample() {
        //source data
        int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
        
        std::list<int> intList;
        //initialize intList with elements from source
        std::copy(std::begin(source), std::end(source),     //source
                  std::back_inserter(intList));             //destination
        C11Utils::printElements(intList);
        
        //remove consecutive duplicates
        auto pos = std::unique(intList.begin(), intList.end());
        
        //print elements not removed
        //use new logical end
        std::copy(intList.begin(), pos,                             //source
                  std::ostream_iterator<int>(std::cout, " "));      //destination
        std::cout << std::endl << std::endl;
        
        //reinitialize intList with elements from source
        std::copy(std::begin(source), std::end(source),     //source
                  intList.begin());                         //destination
        C11Utils::printElements(intList);
        
        //remove elements if there was a previous greater element
        intList.erase(std::unique(intList.begin(), intList.end(),
                                  std::greater<int>()),
                      intList.end());
        C11Utils::printElements(intList);
    }
    
    bool differenceOne(int elem1, int elem2) {
        return elem1 + 1 == elem2 || elem1 - 1 == elem2;
    }
    
    void uniqueCopyExample() {
        //source data
        int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7, 5, 4, 4};
        
        //initialize intList with element from source
        std::list<int> intList;
        std::copy(std::begin(source), std::end(source),     //source
                  std::back_inserter(intList));                         //destination
        C11Utils::printElements(intList);
        
        //print elements with consecutive duplicates removed
        std::unique_copy(intList.begin(), intList.end(),                 //source
                         std::ostream_iterator<int>(std::cout, " "));       //destination
        std::cout << std::endl;
        
        //print elements without consecutive entries that differ by 1 
        std::unique_copy(intList.cbegin(), intList.cend(),              //source
                         std::ostream_iterator<int>(std::cout, " "),    //destination
                         differenceOne);                                //criterion
        std::cout << std::endl;
    }
    
    bool bothSpaces(char elem1, char elem2) {
        return elem1 == ' ' && elem2 == ' ';
    }
    
    void uniqueCopyExample2() {
        //dont skip leading whitespaces by default
        std::cin.unsetf(std::ios::skipws);
        
        //copy standard input to standard output
        //while compressing spaces
        std::unique_copy(std::istream_iterator<char>(std::cin),         //beginning of source std::cin
                         std::istream_iterator<char>(),                 //end of source end-of-life
                         std::ostream_iterator<char>(std::cout, " "),   //destination std::cout    
                         bothSpaces);                                   //duplicate criterion
    }
}