/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <cryptopp/queue.h>

#include "VectorInSTD.h"


namespace C07Containers {
    void vectorExample() {
        
        //create empty vector for string
        std::vector<std::string> sentence;
        
        //reserve memory for five elements to avoid reallocation
        sentence.reserve(5);
        
        //append some elements
        sentence.push_back("Hello");
        sentence.insert(sentence.end(), {"how", "are", "you", "?"});
        
        //print element separated by spaces
        std::copy(sentence.cbegin(), sentence.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
        
        std::cout << std::endl;
        //print technical data
        std::cout << "  max_size(): " << sentence.max_size() << std::endl;
        std::cout << "      size(): " << sentence.size() << std::endl;
        std::cout << "  capacity(): " << sentence.capacity() << std::endl;
        
        //swap second and forth element
        std::swap(sentence[1], sentence[3]);
        
        //insert element "always" before element "?"
        sentence.insert(std::find(sentence.begin(), sentence.end(), 
                                    "?"),
                        "always");
        
        //assign "!" to the last element
        sentence.back() = "!";
        //print element separated by spaces
        std::copy(sentence.cbegin(), sentence.cend(),
            std::ostream_iterator<std::string>(std::cout, " "));
        std::cout << std::endl;
        
        //print some technical data again
        std::cout << "      size(): " << sentence.size() << std::endl;
        std::cout << "  capacity(): " << sentence.capacity() << std::endl;
        
        //delete last 2 elements
        sentence.pop_back();
        sentence.pop_back();
        //shrink capacity C++11
        sentence.shrink_to_fit();
        
        //print some technical data again
        std::cout << "      size(): " << sentence.size() << std::endl;
        std::cout << "  capacity(): " << sentence.capacity() << std::endl;
    }
}