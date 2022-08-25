/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortedRangeAlgs.h
 * Author: default
 *
 * Created on August 23, 2022, 4:11 PM
 */

#ifndef SORTEDRANGEALGS_H
#define SORTEDRANGEALGS_H

namespace C11Algorithms {
    /**
     * Checking whether one element is present
     * bool binary_search(ForwardIterator beg, ForwardIterator end, 
     *                    const T& value);
     * 
     * bool binary_search(ForwardIterator beg, ForwardIterator end, 
     *                    const T& value,
     *                    BinaryPredicate op);
     * 
     * Checking whether several elements are present
     * bool includes(InputIterator1 beg, InputIterator1 end,
     *               InputIterator2 searchBeg, InputIterator2 searchEnd);
     * 
     * bool includes(InputIterator1 beg, InputIterator1 end,
     *               InputIterator2 searchBeg, InputIterator2 searchEnd,
     *               BinaryPredicate op);
     * 
     * 
     * Search first or last possible position
     * ForwardIterator lower_bound(ForwardIterator beg, ForwardIterator end, 
     *                             const T& value);
     * 
     * ForwardIterator lower_bound(ForwardIterator beg, ForwardIterator end, 
     *                             const T& value,
     *                             BinaryPredicate op);   op(elem1, elem2);
     * 
     * ForwardIterator upper_bound(ForwardIterator beg, ForwardIterator end, 
     *                             const T& value);
     * 
     * ForwardIterator upper_bound(ForwardIterator beg, ForwardIterator end, 
     *                             const T& value,
     *                             BinaryPredicate op);   op(elem1, elem2);
     * 
     * 
     * Searching first and last possible position
     * std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator beg, ForwardIterator end,
     *                                                         const T& value);
     * 
     * std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator beg, ForwardIterator end,
     *                                                         const T& value,
     *                                                         BinaryPredicate op);   op(elem1, elem2);
     * 
     * 
     * MERGING ELEMENTS
     * Processing the sum of two sorted sets
     * 
     * OutputIterator merge(InputIterator source1Beg, InputIterator source1End,
     *                      InputIterator source2Beg, InputIterator source2End,
     *                      OutputIterator destBeg);
     * 
     * OutputIterator merge(InputIterator source1Beg, InputIterator source1End,
     *                      InputIterator source2Beg, InputIterator source2End,
     *                      OutputIterator destBeg,
     *                      BinaryPredicate op);   op(elem1, elem2);
     * 
     * Processing the union of 2 sorted sets
     * 
     * OutputIterator set_union(InputIterator source1Beg, InputIterator source1End,
     *                          InputIterator source2Beg, InputIterator source2End,
     *                          OutputIterator destBeg);
     * 
     * OutputIterator set_union(InputIterator source1Beg, InputIterator source1End,
     *                          InputIterator source2Beg, InputIterator source2End,
     *                          OutputIterator destBeg,
     *                          BinaryPredicate op);   op(elem1, elem2);
     * 
     * Processing the intersection of 2 sorted sets
     * 
     * OutputIterator set_intersection(InputIterator source1Beg, InputIterator source1End,
     *                                 InputIterator source2Beg, InputIterator source2End,
     *                                 OutputIterator destBeg);
     * 
     * OutputIterator set_intersection(InputIterator source1Beg, InputIterator source1End,
     *                                 InputIterator source2Beg, InputIterator source2End,
     *                                 OutputIterator destBeg,
     *                                 BinaryPredicate op);   op(elem1, elem2);
     * 
     * Processing the difference of 2 sorted sets
     * 
     * OutputIterator set_difference(InputIterator source1Beg, InputIterator source1End,
     *                               InputIterator source2Beg, InputIterator source2End,
     *                               OutputIterator destBeg);
     * 
     * OutputIterator set_difference(InputIterator source1Beg, InputIterator source1End,
     *                               InputIterator source2Beg, InputIterator source2End,
     *                               OutputIterator destBeg,
     *                               BinaryPredicate op);   op(elem1, elem2);
     * 
     * OutputIterator set_symmetric_difference(InputIterator source1Beg, InputIterator source1End,
     *                                         InputIterator source2Beg, InputIterator source2End,
     *                                         OutputIterator destBeg);
     * 
     * OutputIterator set_symmetric_difference(InputIterator source1Beg, InputIterator source1End,
     *                                         InputIterator source2Beg, InputIterator source2End,
     *                                         OutputIterator destBeg,
     *                                         BinaryPredicate op);   op(elem1, elem2);
     * 
     * 
     * Merging consecutive Sorted Ranges
     * void inplace_merge(BidirectionalIterator beg1, BidirectionalIterator end1,
     *                    BidirectionalIterator end2);
     * 
     * void inplace_merge(BidirectionalIterator beg1, BidirectionalIterator end1,
     *                    BidirectionalIterator end2,
     *                    BinaryPredicate op);
     */
    
    extern void binarySearchExample();
    
    
    //algo/includes1.cpp
    extern void includesExample();
    
    
    //algo/bounds1.cpp
    extern void boundExamples();
    
    //algo/equalrange1.cpp
    extern void equalRange();
    
    //algo/merge1.cpp
    extern void mergeExample();
    
    
    //algo/sorted1.cpp
    extern void mergingExamples();
    
    // algo/inplacemerge1.cpp
    extern void inplaceMergeExample();
}

#endif /* SORTEDRANGEALGS_H */

