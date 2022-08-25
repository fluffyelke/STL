/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MutatingAlgs.h
 * Author: default
 *
 * Created on August 22, 2022, 12:09 PM
 */

#ifndef MUTATINGALGS_H
#define MUTATINGALGS_H

namespace C11Algorithms {
    /**
     * Reversing the orders of Elements
     * 
     * void reverse(BidirectionalIterator beg, BidirectionalIterator end);
     * 
     * OutputIterator reverse_copy(BidirectionalIterator sourceBeg, BidirectionalIterator sourceEnd,
     *                             OutputIterator destBeg);
     * 
     * ROTATING ELEMENTS 
     * Rotating elements inside a sequence
     * 
     * ForwardIterator rotate(ForwardIterator beg, ForwardIterator newBeg, ForwardIterator end);
     * 
     * Rotating elements while copying
     * 
     * OutputIterator rotate_copy(ForwardIterator sourceBeg, ForwardIterator newBeg,
     *                            ForwardIterator sourceEnd,
     *                            OutputIterator destBeg);
     * 
     * 
     * PERMUTING ELEMENTS
     * bool next_permutation(BidirectionalIterator beg, BidirectionalIterator end);
     * 
     * bool next_permutation(BidirectionalIterator beg, BidirectionalIterator end,
     *                       BinaryPredicate op);       op(elem1, elem2);
     * 
     * bool prev_permutation(BidirectionalIterator beg, BidirectionalIterator end);
     * 
     * bool prev_permutation(BidirectionalIterator beg, BidirectionalIterator end,
     *                       BinaryPredicate op);       op(elem1, elem2);
     * 
     * 
     * 
     * Shuffling Using Random-Number Library
     * 
     * void shuffle(RandomAccessIterator beg, RandomAccessIterator end,
     *              UniformRandomNumberGenerator&& eng);
     * 
     * void random_shuffle(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void random_shuffle(RandomAccessIterator beg, RandomAccessIterator end,
     *                     RandomFunc&& op);
     * 
     * Moving Elements to the front
     * ForwardIterator partition(ForwardIterator beg, ForwardIterator end,
     *                           UnaryPredicate op);   op(elem);
     * 
     * BidirectionalIterator stable_partition(BidirectionalIterator beg, BidirectionalIterator end,
     *                                 UnaryPredicate op);   op(elem);
     * 
     * PARTITION INTO TWO SUBRANGES
     * std::pair<OutputIterator1, OutputIterator2> partition_copy(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                                            OutputIterator1 destTrueBeg, OutputIterator2 destFalseBeg,
     *                                                            UnaryPredicate op);   op(elem);
     */
    
    //algo/reverse1.cpp
    extern void reverseExample();
    
    //algo/rotate1.cpp
    extern void rotateExample();
    
    //algo/rotate2.cpp
    extern void rotateExample2();
    
    //algo/permutation1.cpp
    extern void permutationExample();
    
    //algo/shuffle1.cpp
    extern void shuffleExample();
    
    //algo/randomshuffle1.cpp
    extern void randomShuffleExample();
    
    //algo/partition1.cpp
    extern void partitionExample();
    
    //algo/partitioncopy1.cpp
    extern void partitionCopyExample();
}

#endif /* MUTATINGALGS_H */

