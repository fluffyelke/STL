/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ch03.h"

namespace Ch03 {
    void print(std::initializer_list<int> values) {
        for(auto p = values.begin(); p != values.end(); ++p) {
            std::cout << *p << " ";
        }
    }
    
    void rawStringLiterals() {
/**
 * Types of string literals
 * u8   - Defines a type with UTF-8 encoding  const char
 * u    - Defines a string literal with characters of type char16_t
 * U    - Defines a string literal with characters of type char32_t
 * L    - Defines a wide string literal with characters of type wchar_t
 * 
 */
        
        
        std::string raw = R"(\\n)";
        std::cout << raw;
        
        std::string raw2 = R"nc(a\
                                b\nc()"
                            )nc";
        std::cout << raw2;
    }
    
    void simpleLambdas() {
         //lambda notation
        /**  [...] (...) mutable(optional) throwSpec(optional) -> retType(optional) {...}; */
        /**
         * If there is not specific return type, return type is deduced from lamba return type.
         * 
         * [=] - means that the outer scope is passed to lambda by value, thus you can read, 
         *  but cant modify all the data where the lambda is defined.
         * 
         * [&] - means that the outer scope is passed by reference, thus you have 
         * write access to all data, that was valid when the lambda is defined, provided that you have write access there. 
         * 
         */
        
        
        
        //simple lambda
        [] {
            std::cout << "Hello Lambda!\n";
        };
        
        //simple lambda and call it
        [] {
           std::cout << "Hello Lambda Call!\n"; 
        } ();
        
        //or pass it to object for call it
        auto myLambda = [] {
          std::cout << "My Lambda !\n";  
        };
        myLambda();
        
        //lambda with parameters
        auto printString = [] (const std::string& str) {
          std::cout << str << std::endl;  
        };
        printString("Hello Print String");
        
        
        //Lambda that returns int
        [] {
            return 42;
        };
        
        /**lambda that returns double 42.0*/
        [] () -> double {
            return 42;
        };
        
        int x = 10;
        int y = 15;
        
        auto qqq = [x, &y] () {
            std::cout << "x: " << x << std::endl;
            std::cout << "y: " << y << std::endl;
            ++y;    //ok  by reference can be changed
//            ++x;    //error by value cant be changed
        };
        x = y = 20;
        qqq();
        qqq();
        std::cout << "Final y: " << y << std::endl;
        
        
        //To have mixture of passing by value , but inside the function objects can be changed, you can
        //declare lambda az mutable.
        int id = 10;
        auto funcOne = [id]() mutable {
            std::cout << "id: " << id << std::endl;
            ++id;   //ok now.
        };
        id = 42;
        funcOne();
        funcOne();
        funcOne();
        std::cout << "Final id: " << id << std::endl;
        
        /*lambda can be considered as a function object*/
        /**
         * class {
         *    private: 
         *       int id:
         *    public:
         *       void operator() () {
         *            std::cout << "id: " << id << std::endl;
         *            ++id;
         *       }
         * };
         */
        
        
        auto squareLambda = returnLambda();
        std::cout << squareLambda(10, 15) << std::endl;
    }
    
    //The only way to specify return type of a function, returning lambda.
    std::function<int(int, int)> returnLambda() {
        return [] (int x, int y) {
            return x * y;
        };
    }
}