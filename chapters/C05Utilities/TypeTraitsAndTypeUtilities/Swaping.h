/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Swaping.h
 * Author: default
 *
 * Created on July 29, 2022, 2:25 PM
 */

#ifndef SWAPING_H
#define SWAPING_H

#include <utility>

namespace Swap {
    class MyContainer {
    private:
        int* elems;
        int numElems;
        //...
    public:
        void swap(MyContainer& obj) {
            std::swap(elems, obj.elems);
            std::swap(numElems, obj.numElems);
        }
    };
    
    //overloaded global swap() for this type
    inline void swap(MyContainer& left, MyContainer& right) noexcept(noexcept(left.swap(right))) {
        left.swap(right);
    }
}

#endif /* SWAPING_H */

