/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   VectorInSTD.h
 * Author: default
 *
 * Created on August 4, 2022, 9:15 AM
 */

#ifndef VECTORINSTD_H
#define VECTORINSTD_H

#include <memory>
#include <vector>


namespace C07Containers {
    /**
     * T- the elements of the array can have any type of elements T
     * Allocator = memory model provided by c++ std
     */
//    template<typename T, typename Allocator = std::allocator<T>>
//    class MyVector;
    
    template<typename T>
    void shrinkCapacity(std::vector<T>& vec) {
        std::vector<T> tmp(vec);        //copy elements into new vector
        vec.swap(tmp);                  //swap internal vector data
    }
    
    extern void vectorExample();
}

#endif /* VECTORINSTD_H */

