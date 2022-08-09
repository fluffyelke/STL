/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Algorithms.h
 * Author: default
 *
 * Created on August 9, 2022, 11:40 AM
 */

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

namespace Algorithms {
    template<typename InputIterator, typename OutputIterator>
    OutputIterator myCopy(InputIterator fromBegin,      //beginig of the source
                          InputIterator fromEnd,        //end of the source
                          OutputIterator toPos) {       //beginning of the destination 
        
        while(fromBegin != fromEnd) {
            *toPos = *fromBegin;        //copy values
            ++fromBegin;                //increment iterators
            ++toPos;
        }
        return toPos;
    }
}

#endif /* ALGORITHMS_H */

