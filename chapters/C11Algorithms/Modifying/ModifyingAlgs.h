/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ModifyingAlgs.h
 * Author: default
 *
 * Created on August 16, 2022, 3:19 PM
 */

#ifndef MODIFYINGALGS_H
#define MODIFYINGALGS_H

namespace C11Algorithms {
    /**
     * Two ways for modifying elements
     * 1. Modify them directly while iterating through a sequence
     * 2. Modify them while copying them from a source range to a destination range.
     * 
     * COPYING ELEMENTS
     * OutputIterator copy(OutputIterator sourceBeg, OutputIterator sourceEnd,
     *                     OutputIterator destBeg, 
     *                     UnaryPredicate op); 
     * 
     * OutputIterator copy_if(OutputIterator sourceBeg, OutputIterator sourceEnd,
     *                        OutputIterator destBeg, 
     *                        UnaryPredicate op); 
     * 
     * OutputIterator copy_n(OutputIterator sourceBeg,
     *                       Size num,
     *                       OutputIterator destBeg); 
     * 
     * BidirectionalIterator2 copy_backward(BidirectionalIterator1 sourceBeg,
     *                                      BidirectionalIterator1 sourceEnd,
     *                                      BidirectionalIterator destEnd);
     * 
     * 
     * since C++11 if source destination is not used anymore, we should use
     * std::move() instead std::copy(),  and std::move_backward() instead std::copy_backward()
     * 
     * 
     * 
     * MOVING ELEMENTS
     * OutputIterator move(InputIterator sourceBeg, InputIterator sourceEnd,
     *                     OutputIterator destBeg);
     * 
     * BidirectionalIterator2 move_backward(BidirectionalIterator1 sourceBeg, 
     *                                      BidirectionalIterator1 sourceEnd,
     *                                      BidirectionalIterator2 destEnd);
     * 
     * 
     * 
     * TRANSFORMING AND COMBINING ELEMENTS
     * 
     * OutputIterator transform(InputIterator sourceBeg, InputIterator sourceEnd,
     *                          OutputIterator sourceBeg,
     *                          UnaryPredicate op);
     * 
     * COMBINING ELEMENTS OF TWO SEQUENCES
     * 
     * OutputIterator transform(InputIterator1 source1Beg, InputIterator1 source1End,
     *                          InputIterator2 source2Beg, 
     *                          OutputIterator destBeg,
     *                          BinaryPredicate op);
     * 
     * 
     * SWAPING ELEMENTS
     * 
     * ForwardIterator2 swap_ranges(ForwardIterator1 beg, ForwardIterator1 end,
     *                              ForwardIterator2 beg);
     * 
     * 
     * ASSIGNING NEW VALUES
     * 
     * Assigning the same values
     * 
     * void fill(ForwardIterator beg, ForwardIterator end,
     *            const T& newValue);
     * 
     * void fill_n(OutputIterator beg, Size num,
     *            const T& newValue);
     * 
     * Assigning generated values
     * 
     * void generate(ForwardIterator beg, ForwardIterator end,
     *               Func op);
     *
     * void generate_n(OutputIterator beg, Size num,
     *               Func op);
     * 
     * 
     * Assigning sequence of increment values
     * 
     * void iota(ForwardIterator beg, ForwardIterator end,
     *           T startValue);
     * 
     * REPLACING ELEMENTS
     * 
     * Replace Values Inside a Sequence
     * 
     * void replace(ForwardIterator beg, ForwardIterator end,
     *              const T& oldValue, 
     *              const T& newValue);
     * 
     * void replace_if(ForwardIterator beg, ForwardIterator end,
     *                 UnaryPredicate op,           op(elem)
     *                 const T& newValue);       
     * 
     * Copying and replacing elements
     * OutputIterator replace_copy(InputIterator beg, InputIterator end,
     *                             OutputIterator destBeg,
     *                             const T& oldValue, 
     *                             const T& newValue);
     * 
     * OutputIterator replace_copy_if(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                OutputIterator destBeg,
     *                                UnaryPredicate op,       op(elem)      
     *                                const T& newValue);
     * 
     * REMOVING ALGORITHMS
     * 
     * Removing elements in sequence
     * ForwardIterator remove(ForwardIterator beg, ForwardIterator end,
     *                        const T& newValue);
     * 
     * ForwardIterator remove_if(ForwardIterator beg, ForwardIterator end,
     *                           UnaryPredicate op);    op(elem)
     * 
     * Removing elements while copying
     * OutputIterator remove_copy(InputIterator sourceBeg, InputIterator sourceEnd,
     *                            OutputIterator destBeg,
     *                            const T& value);
     * 
     * OutputIterator remove_copy_if(InputIterator sourceBeg, InputIterator sourceEnd,
     *                               OutputIterator destBeg,
     *                               UnaryPredicate op);        op(elem)
     * 
     * 
     * REMOVING DUPLICATES
     * 
     * Removing consecutive duplicates
     * ForwardIterator unique(ForwardIterator beg, ForwardIterator end);
     * 
     * ForwardIterator unique(ForwardIterator beg, ForwardIterator end,
     *                        BinaryPredicate op);      op(elem1, elem2);
     * 
     * Removing duplicates while copying
     * OutputIterator unique_copy(InputIterator sourceBeg, InputIterator sourceEnd,
     *                            OutputIterator destBeg);
     * 
     * OutputIterator unique_copy_if(InputIterator sourceBeg, InputIterator sourceEnd,
     *                               OutputIterator destBeg,
     *                               BinaryPredicate op);      op(elem1, elem2);
     * 
     * 
     * MUTATING ALGORITHMS
     * 
     */
    
    
    //algo/copy1.cpp
    extern void copyExample();
    
    //algo/copy2.cpp
    extern void copyExample2();
    
    //algo/copy3.cpp
    extern void copyExample3();
    
    //algo/move1.cpp
    extern void moveExample();
    
    //algo/transform1.cpp
    extern void transformExample();
    
    //algo/transform2.cpp
    extern void transformExample2();
    
    //algo/swapranges1.cpp
    extern void swapRangesExample();
    
    //algo/fill1.cpp
    extern void fillExample();
    
    //algo/generate1.cpp
    extern void generateExample();
    
    //algo/iota1.cpp
    extern void iotaExample();
    
    //algo/replace1.cpp
    extern void replaceExample();
    
    //algo/replace2.cpp
    extern void replaceExample2();
    
    //algo/remove1.cpp
    extern void removeExample();
    
    //algo/remove2.cpp
    extern void removeCopyExample();
    
    //algo/unique1.cpp
    extern void uniqueExample();
    
    //algo/unique2.cpp
    extern void uniqueCopyExample();
    
    //algo/uniqie3.cpp
    extern void uniqueCopyExample2();
}

#endif /* MODIFYINGALGS_H */

