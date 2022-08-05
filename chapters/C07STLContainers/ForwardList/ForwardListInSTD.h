/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ForwardListInSTD.h
 * Author: default
 *
 * Created on August 4, 2022, 12:46 PM
 */

#ifndef FORWARDLISTINSTD_H
#define FORWARDLISTINSTD_H

#include <memory>


namespace C07Containers {
    /**
     * for size() of the forward_list we can use algorithm/iterator distance
     * std::distance(list.begin(), list.end());  or std::distance(pos, endPos);
     * list in std
     * T- the elements of the array can have any type of elements T
     * Allocator = memory model provided by c++ std
     */
//    template<typename T, typename Allocator = std::allocator<T>>
//    class forward_list;
    
    //cont/forwardlistfind1.cpp
    extern void forwardListFind();
    
    template<typename InputIterator, typename Tp>
    inline InputIterator findBefore(InputIterator first, InputIterator last, const Tp& value) {
        if(first == last) {
            return first;
        }
        InputIterator next(first);
        ++next;
        while(next != last && !(*next == value)) {  //or may be (*next != value)
            ++next;
            ++first;
        }
        return first;
    }
    
    template<typename InputIterator, typename Pred>
    inline InputIterator findBeforeIf(InputIterator first, InputIterator last, Pred pred) {
        if(first == last) {
            return first;
        }
        InputIterator next(first);
        ++next;
        while(next != last && !pred(*next)) {
            ++next;
            ++first;
        }
        return first;
    }
    
    
    extern void testSpliceAfter();

    
    extern void exampleOfForwardList();
    
    
}

#endif /* FORWARDLISTINSTD_H */

