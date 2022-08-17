/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <unordered_set>

#include "../C06StandardTemplateLibrary/Utils/Utils.h"
#include "OstreamIterators.h"
#include "UserDefinedIterator/UserDefinedIter.h"


namespace C09Iterators {
    void ostreamIterTest1() {
        //creates ostream iterator for stream cout
        //-values are separated by a newline character
        std::ostream_iterator<int> intWriter(std::cout, "\n");
        
        
        //write elements with the usual iterator interface
        *intWriter = 42;
        ++intWriter;
        *intWriter = 77;
        ++intWriter;
        *intWriter = -5;
        
        //create collection with elements from 1 to 9
        std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        //write all elements without delimiters
        std::copy(intVec.cbegin(), intVec.cend(),
                 std::ostream_iterator<int>(std::cout));
         std::cout << std::endl;
         
        //write all elements with " < " as delimiter
        //write all elements without delimiters
        std::copy(intVec.cbegin(), intVec.cend(),
                 std::ostream_iterator<int>(std::cout, " < "));
        std::cout << std::endl;
    }
    
    void ostreamIterTest2() {
        std::ofstream myFile("test.txt");
        std::ostream_iterator<int> intStream(myFile, " ");
        for(int i = 1; i <= 9; i++ ) {
            *intStream = i;
            ++intStream;
        }
        myFile.close();
    }
    
    void istreamIterTest() {
        //creates istream iterator that read integers fron cin
        std::istream_iterator<int> intReader(std::cin);
        
        //create end of istream iterator
        std::istream_iterator<int> intReaderEOF;
        
        //while able to read tokens with istream iterator
        //-write them twice
        while(intReader != intReaderEOF) {
            std::cout << "once       " << *intReader << std::endl;
            std::cout << "once again " << *intReader << std::endl;
            ++intReader;
        }
    }
    
    void streamIterAndAdvance() {
        std::istream_iterator<std::string> cinPos(std::cin);
        std::ostream_iterator<std::string> coutPos(std::cout, " ");
        
        //while output is not an end of the file
        // -write every third string
        while(cinPos != std::istream_iterator<std::string>()) {
            //ignore the following 2 strings
            std::advance(cinPos, 2);
            
            //read and write the third string
            if(cinPos != std::istream_iterator<std::string>()) {
                *coutPos++ = *cinPos++;
            }
        }
        std::cout << std::endl;
    }
    
    void testUserDefinedIter() {
        std::unordered_set<int> intSet;
        
        //create inserter for intSet
        // inconvenient way
        C09Iterators::AssociativeInsertIterator<decltype(intSet)> iter(intSet);
        *iter = 1;
        ++iter;
        *iter = 2;
        ++iter;
        *iter = 3;
        
        Containers::printElements(intSet, "intSet: ");
        
        //create inserter and insert convenient way
        C09Iterators::assoInserter(intSet) = 44;
        C09Iterators::assoInserter(intSet) = 55;
        
        Containers::printElements(intSet, "intSet: ");
        
        //use inserter with an algorithm
        std::vector<int> vals = {33, 67, -4, 13, 5, 2};
        std::copy(vals.cbegin(), vals.cend(),           //source
                 C09Iterators::assoInserter(intSet));   //destination
        
        Containers::printElements(intSet, "intSet: ");
    }
}