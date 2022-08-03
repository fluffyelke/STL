/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PairsExamples.h"
#include <utility>
#include <iostream>
#include <array>
#include <functional>
#include <../6.3.0/bits/stl_pair.h>

namespace Pairs {
    
    void testPairFunctionality() {   
        using IntFloatPair = std::pair<int, float>;

        IntFloatPair myPair(5, 3.14);
        
        std::cout << std::get<0>(myPair) << std::endl;
        std::cout << std::get<1>(myPair) << std::endl;
        std::cout << std::tuple_size<IntFloatPair>::value << std::endl;
//        std::cout << std::tuple_element<0, IntFloatPair>::type << std::endl;
//        std::cout << std::tuple_element<1, IntFloatPair>::type << std::endl;
    }
    
    Foo::Foo(std::tuple<int, float>) {
        std::cout << "Foo::Foo(tuple)\n";
    }
    void testPairOne() {
        //create tuple t
        std::tuple<int, float> t(1, 2.22);
        
        //Pass the tuple as a whole to the constructor of Foo
        std::pair<int, Foo> p1(22, t);
        
        //Pass the elements of the tuple to the constructor of Foo
        std::pair<int, Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
    }

    void pairRefSemantic() {
        int i = 0;
        //std::ref()   <<< creats a ref to a variable.
        auto p = std::make_pair(std::ref(i), std::ref(i));  //creates std::pair<int&, int&>
        
        ++p.first;      //increment i;
        ++p.second;     //increment i again;
        std::cout << "i: " << i << std::endl;
    }
    
    void extractElementFromPair() {
        std::pair<char, char> p = std::make_pair('x', 'y');
        
        char c;
        std::tie(std::ignore, c) = p;       //extract second value into char c, (ignore first element)
    }
    
}