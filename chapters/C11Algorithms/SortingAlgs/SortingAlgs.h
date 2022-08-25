/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortingAlgs.h
 * Author: default
 *
 * Created on August 23, 2022, 2:38 PM
 */

#ifndef SORTINGALGS_H
#define SORTINGALGS_H

namespace C11Algorithms {
    
    
    /**
     * SORTING ALL ELEMENTS
     * void sort(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void sort(RandomAccessIterator beg, RandomAccessIterator end,
     *           BinaryPredicate op);        op(elem1, elem2);
     * 
     * void stable_sort(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void stable_sort(RandomAccessIterator beg, RandomAccessIterator end,
     *                  BinaryPredicate op);        op(elem1, elem2);
     * 
     * 
     * Partial Sorting
     * 
     * void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
     *                   RandomAccessIterator end);
     * 
     * void partial_sort(RandomAccessIterator beg, RandomAccessIterator sortEnd,
     *                   RandomAccessIterator end,
     *                   BinaryPredicate op);       op(elem1, elem2);
     * 
     * 
     * RandomAccessIterator partial_sort_copy(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                        RandomAccessIterator destBeg, RandomAccessIterator destEnd);
     * 
     * RandomAccessIterator partial_sort_copy(InputIterator sourceBeg, InputIterator sourceEnd,
     *                                        RandomAccessIterator destBeg, RandomAccessIterator destEnd,
     *                                        BinaryPredicate op);      op(elem);
     * 
     * Sorting According nth element
     * void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
     *                  RandomAccessIterator end);
     * 
     * void nth_element(RandomAccessIterator beg, RandomAccessIterator nth,
     *                  RandomAccessIterator end,
     *                  BinaryPredicate op);
     * 
     * Heap Algorithms in Details.
     * void make_heap(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void make_heap(RandomAccessIterator beg, RandomAccessIterator end,
     *                BinaryPredicate op);  op(elem1, elem2);
     * 
     * void push_heap(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void push_heap(RandomAccessIterator beg, RandomAccessIterator end,
     *                BinaryPredicate op);  op(elem1, elem2);
     * 
     * void pop_heap(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void pop_heap(RandomAccessIterator beg, RandomAccessIterator end,
     *               BinaryPredicate op);  op(elem1, elem2);
     * 
     * void sort_heap(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * void sort_heap(RandomAccessIterator beg, RandomAccessIterator end,
     *                BinaryPredicate op);  op(elem1, elem2);
     */
    
    //algo/sort1.cpp
    extern void sortExample();
    
    
    //algo/sort2.cpp
    extern void sortExample2();
    
    //algo/partialsort1.cpp
    extern void partialSortExample();
    
    //algo/partialsort1.cpp
    extern void partialSortCopyExample();
    
    //algo/nthelement1.cpp
    extern void nthElementExample();
    
    //algo/heap1.cpp
    extern void heapExample();
}

#endif /* SORTINGALGS_H */

