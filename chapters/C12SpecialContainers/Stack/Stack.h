/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Stack.h
 * Author: default
 *
 * Created on August 24, 2022, 2:28 PM
 */

#ifndef STACK_H
#define STACK_H

#include <deque>
#include <algorithm>

namespace C12Containers {
    /**
     * C++ implementation of stack
     * 
       
        namespace std {
            template<typename T,
                     typename Container = std::deque<T>>
            class stack;
        }
     * 
     */
    
    //class stack in details
    template<typename T, typename Container = std::deque<T>>
    class MyStack {
        public:
            using value_type = typename Container::value_type;
            using reference = typename Container::reference;
            using const_reference = typename Container::const_reference;
            using size_type = typename Container::size_type;
            using container_type = Container;
//            typedef typename Container::value_type          value_type;
//            typedef typename Container::reference           reference;
//            typedef typename Container::const_reference     const_reference;
//            typedef typename Container::size_type           size_type;
//            typedef          Container                      container_type;
            
        protected:
            Container c;
            
        public:
            bool empty() const { return c.emprty(); }
            
            size_type size() const { return c.size(); } 
            
            void push(const value_type& x) { c.push_back(x); } 
            
            void push(value_type&& x) { c.push_back(std::move(x)); }
            
            void pop() { c.pop_back(); }
            
            value_type& top() { return c.back(); }
            
            const value_type& top() const { return c.back(); }
            
            template<typename... Args>
            void emplace(Args&&... args) {
                c.emplace_back(std::forward<Args>(args)...);
            }
            
            void swap(MyStack& s) {
                std::swap(c, s.c);
            }
            
    };
    
    // contadapt/stack1.cpp
    extern void stackExample();
    
    // contadapt/stack2.cpp
    extern void testUserDefinedStack();
    
}

#endif /* STACK_H */

