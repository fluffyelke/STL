/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PairInterface.h
 * Author: default
 *
 * Created on July 26, 2022, 12:38 PM
 */

#ifndef PAIRINTERFACE_H
#define PAIRINTERFACE_H

namespace PairInterface {
    
    template<typename T1, typename T2>
    struct Pair {
        
        T1 first;
        T2 second;
   
        Pair(const T1& x, const T2& y) 
            : first{x},
             second{y} {}
        
        //Before c++11
        template<typename T1, typename T2>
        Pair<T1, T2> makePair(const T1& x, const T2& y) {
            return Pair<T1, T2>(x, y);
        }

        //Since C++11
        template<typename T1, typename T2>
        Pair<T1, T2> makePair(T1&& x, T2&& y);

        //Compare of two pairs, its true if both pair values are true
        template<typename T, typename T>
        bool operator == (const Pair<T1, T2>& x, const Pair<T1, T2>& y ) {
            return x.first == y.first && x.second == y.second;
        }  

        template<typename T1, typename T2>
        bool operator < (const Pair<T1, T2>& x, const Pair<T1, T2>& y) {
            return x.first < y.first || (!(y.first < x.first) && x.second < y.second);
        }
    };

    
}

#endif /* PAIRINTERFACE_H */

