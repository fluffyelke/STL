/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.hpp
 * Author: default
 *
 * Created on August 24, 2022, 2:38 PM
 */

#ifndef STACK_HPP
#define STACK_HPP

#include <deque>


/*********************************************
 * Stack.hpp
 * - safer and more convenient stack class
 * 
 *********************************************/

namespace C11Containers {

    template<typename T>
    class Stack {
        protected:
            std::deque<T> c;        //container for elements

        public:
            //exception class for top() and pop() for empty stack
            class ReadEmptyStack : public std::exception {
                public:
                    virtual const char* what() const throw() {
                        return "read empty stack";
                    }
            };  //end of ReadEmprtyStack class

            // number of elements
            typename std::deque<T>::size_type size() const {
                return c.size();
            }

            // is stack empty
            bool empty() const {
                return c.empty();
            }

            // push elements into the stack
            void push(const T& elem) {
                c.push_back(elem);
            }

            //pop element out of the stack and return its value
            T pop() {
                if(c.empty()) {
                    throw ReadEmptyStack();
                }

                T elem(c.back());
                c.pop_back();
                return elem;
            }

            //return value of next element
            T& top() {
                if(c.empty()) {
                    throw ReadEmptyStack();
                }
                return c.back();
            }
    };

}

#endif /* STACK_HPP */

