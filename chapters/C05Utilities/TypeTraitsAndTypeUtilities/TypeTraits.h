/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TypeTraits.h
 * Author: default
 *
 * Created on July 29, 2022, 12:59 PM
 */

#ifndef TYPETRAITS_H
#define TYPETRAITS_H

#include <utility>

namespace Traits {
    
//    template<typename T1, typename T2>
//    struct CommonType<T1, T2>{
//        typedef decltype(true ? std::declval<T1>() : std::declval<T2>) type;
//    };
//    
//    template<typename T1, typename T2>
//    typename CommonType<T1,T2>::type min(const T1& left, const T2& right) {
//        
//    }
    
    
    //Function type wrappers
    extern void myFunc(int x, int y);
    extern void testFunctionWrappers();
}

#endif /* TYPETRAITS_H */

