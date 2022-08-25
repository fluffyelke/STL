/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PriorityQueue.hpp
 * Author: default
 *
 * Created on August 25, 2022, 1:46 PM
 */

#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <vector>
#include <functional>
#include <algorithm>
#include <cstdlib>
#include <cstdef>

namespace C11Algorithms {
    
    template<typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type>>
    class PriorityQueue {
        protected:
            Compare comp;       //sorting criterion
            Container c;
        public:
            //constructors
            explicit PriorityQueue(const Compare& cmp = Compare(), const Container& cnt = Container()) 
                : comp(cmp), 
                  c(cnt){
                    std::make_heap(c.begin(), c.end(), comp);
            }
                
            void push(const value_type& x) {
                c.push_back(x);
                std::push_heap(c.begin(), c.end(), comp);
            }   
            void pop() {
                std::pop_heap(c.begin(), c.end(), comp);
                c.pop_back();
            }
            
            bool empty() const { return c.empty(); }
            std::size_t size() const { return c.size(); }
            const value_type& top() const { return c.front(); }
            
            ///....
    };
    
}

#endif /* PRIORITYQUEUE_HPP */

