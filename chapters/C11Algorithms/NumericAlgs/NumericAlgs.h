/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumericAlgs.h
 * Author: default
 *
 * Created on August 24, 2022, 12:10 PM
 */

#ifndef NUMERICALGS_H
#define NUMERICALGS_H

namespace C11Algorithms {
    
    /**
     * PROCESSING RESULTS
     * 
     * Computing the Result of 1 sequence
     * 
     * T accumulate(InputIterator beg, InputIterator end,
     *              T initValue);
     * 
     * T accumulate(InputIterator beg, InputIterator end,
     *              T initValue,
     *              BinaryFunc op);  op(initValue, elem);
     * 
     * 
     * Computing the inner product of 2 sequences
     * 
     * T inner_product(InputIterator1 beg, InputIterator1 end,
     *                 InputIterator2 beg,
     *                 T initValue);
     * 
     * T inner_product(InputIterator1 beg, InputIterator1 end,
     *                 InputIterator2 beg,
     *                 T initValue,
     *                 BinaryFunc op1,
     *                 BinaryFunc op2);
     * 
     * 
     * Converting relative and absolute values
     * OutputIterator partial_sum(InputIterator sourceBeg, InputIterator sourceEnd,
     *                            OutputIterator destBeg);
     * 
     * OutputIterator partial_sum(InputIterator sourceBeg, InputIterator sourceEnd,
     *                            OutputIterator destBeg,
     *                            BinaryFunc op);
     * 
     * 
     * Converting Absolute Values into Relative Values
     * OutputIterator adjacent_difference(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                    OutputIterator destBeg);
     * 
     * OutputIterator adjacent_difference(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                    OutputIterator destBeg,
     *                                    BinaryFunc op);
     */
    
    // algo/accumulate1.cpp
    extern void accumulateExample();
    
    // algo/innerproduct1.cpp
    extern void innerProductExample();
    
    //algo/partialsum1.cpp
    extern void partialSumExample();
    
    //algo/adjacentdifference1.cpp
    extern void adjacentDiffExample();
    
    //algo/relabs1.cpp
    extern void relativeAbsExample();
}

#endif /* NUMERICALGS_H */

