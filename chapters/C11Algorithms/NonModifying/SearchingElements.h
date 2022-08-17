/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SearchingElements.h
 * Author: default
 *
 * Created on August 11, 2022, 3:00 PM
 */

#ifndef SEARCHINGELEMENTS_H
#define SEARCHINGELEMENTS_H

namespace C11Algorithms {
    /**
     * 
     * BinaryPredicate op()   ====  op(elem1, elem2);
     * CompFunc op()          ====  op(elem1, elem2);    <<< BinaryPredicate
     * 
     * UnaryPredicate op()    ====  op(elem);
     * 
     * 
     * 
     * SEARCH FIRST MATCHING ELEMENT
     * 
     * InputIterator find(InputIterator beg, InputIterator end, const T& value);
     * 
     * InputIterator find_if(InputIterator beg, InputIterator end, UnaryPredicate op);
     * 
     * InputIterator find_if_not(InputIterator beg, InputIterator end, UnaryPredicate op);
     * 
     * 
     * 
     * SEARCH n MATCHING CONSECUTIVE ELEMENTS
     * 
     * ForwardIterator search_n(ForwardIterator beg, ForwardIterator end, Size counts, const T& value);
     * 
     * ForwardIterator search_n(ForwardIterator beg, ForwardIterator end, Size counts, const T& value, BinaryPredicate op);
     * 
     * 
     * 
     * SEARCH FIRST SUBRANGE
     * 
     * ForwardIterator1 search(ForwardIterator1 beg, ForwardIterator1 end, 
     *                         ForwardIterator2 searchBeg, ForwardIterator2 searchEnd);
     * 
     * ForwardIterator1 search(ForwardIterator1 beg, ForwardIterator1 end, 
     *                         ForwardIterator2 searchBeg, ForwardIterator2 searchEnd,
     *                         BinaryPredicate op);
     * 
     * 
     * SEARCH LAST SUBRANGE
     * ForwardIterator1 find_end(ForwardIterator1 beg, ForwardIterator1 end,
     *                           ForwardIterator2 searchBeg, ForwardIterator2 searchEnd);
     * 
     * ForwardIterator1 find_end(ForwardIterator1 beg, ForwardIterator1 end,
     *                           ForwardIterator2 searchBeg, ForwardIterator2 searchEnd,
     *                           BinaryPredicate op);
     * 
     * 
     * 
     * SEARCH FIRST OF SEVERAL POSSIBLE ELEMENTS
     * InputIterator find_first_of(InputIterator beg, InputIterator end,
     *                             ForwardIterator searchBeg, ForwardIterator searchEnd);
     * 
     * InputIterator find_first_of(InputIterator beg, InputIterator end,
     *                             ForwardIterator searchBeg, ForwardIterator searchEnd,
     *                             BinaryPredicate op);
     * 
     * 
     * SEARCH TWO ADJACENT, EQUAL ELEMENTS
     * ForwardIterator adjacent_find(ForwardIterator beg, ForwardIterator end);
     * 
     * ForwardIterator adjacent_find(ForwardIterator beg, ForwardIterator end,
     *                               BinaryPredicate op);
     * 
     * TESTING EQUALITY
     * bool equal(InputIterator beg, InputIterator end,
     *           InputIterator compBeg);
     * 
     * bool equal(InputIterator beg, InputIterator end,
     *           InputIterator compBeg,
     *           BinaryPredicate op);
     * 
     * TESTING FOR UNORDERED EQUALITY
     * bool is_permutation(ForwardIterator1 beg1, ForwardIterator1 end1,
     *                     ForwardIterator2 beg2);
     * 
     * bool is_permutation(ForwardIterator1 beg1, ForwardIterator1 end1,
     *                     ForwardIterator2 beg2,
     *                     CompFunc op);
     * 
     * 
     * SEARCH FOR FIRST DIFFERENCE
     * std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 beg, InputIterator1 end,
     *                                                    InputIterator2 cmpBeg);
     * 
     * std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 beg, InputIterator1 end,
     *                                                    InputIterator2 cmpBeg,
     *                                                    BinaryPredicate op);
     * 
     * TESTING FOR "LESS THAN"
     * bool lexicographical_compar(InputIterator1 beg, InputIterator end,
     *                             InputIterator2 beg, InputIterator2 end);
     * 
     * bool lexicographical_compar(InputIterator1 beg, InputIterator end,
     *                             InputIterator2 beg, InputIterator2 end,
     *                             CompFunc op);
     * 
     * 
     * PREDICATE FOR RANGES
     * 
     * CHECK FOR (PARTIAL) SORTING
     * bool is_sorted(ForwardIterator beg, ForwardIterator end);
     * 
     * bool is_sorted(ForwardIterator beg, ForwardIterator end,
     *                BinaryPredicate op);
     * 
     * ForwardIterator is_sorted_until(ForwardIterator beg, ForwardIterator end);
     * 
     * ForwardIterator is_sorted_until(ForwardIterator beg, ForwardIterator end,
     *                                 BinaryPredicate op); 
     * 
     * CHECK FOR BEING PARTITIONED
     * bool is_partitioned(InputIterator beg, InputIterator end,
     *                     UnaryPredicate op); 
     * 
     * ForwardIterator partition_point(ForwardIterator beg, ForwardIterator end,
     *                                 BinaryPredicate op);    
     * 
     * CHECK FOR BEING A HEAP (MAXIMUM ELEMENT FIRST)
     * bool is_heap(RandomAccessIterator beg, RandomAccessIterator end);
     * 
     * bool is_heap(RandomAccessIterator beg, RandomAccessIterator end,
     *              BinaryPredicate op);  
     * 
     * RandomAccessIterator is_heap_until(RandomAccessIterator beg, RandomAccessIterator end);   
     * 
     * RandomAccessIterator is_heap_until(RandomAccessIterator beg, RandomAccessIterator end,
     *                                   BinaryPredicate op); 
     * 
     * 
     * ALL, ANY, OR NONE
     * bool all_of(InputIterator beg, InputIterator end, 
     *             UnaryPredicate op);  
     * 
     * bool any_of(InputIterator beg, InputIterator end, 
     *             UnaryPredicate op);   
     * 
     * bool none_of(InputIterator beg, InputIterator end, 
     *             UnaryPredicate op); 
     *               
     */
    
    // algo/find1.cpp
    extern void exampleFind1();
    
    // algo/find2.cpp
    extern void exampleFindIfNot();
    
    
    // algo/searchn1.cpp
    extern void exampleSearchN1();
    
    // algo/search1.cpp
    extern void exampleSearch1();
    
    // algo/search2.cpp
    extern void exampleSearch2();
    
    //algo/findend1.cpp
    extern void exampleFindEnd();
    
    //algo/findof1.cpp
    extern void exampleFindFirstOf();
    
    //algo/adjacentfind1.cpp
    extern void exampleAdjacentFind();
    
    //algo/equal1.cpp
    extern void exampleEqual1();
    
    //algo/ispermutation1.cpp
    extern void isPermutationTest();
    
    //algo/mismatch1.cpp
    extern void mismatchExample();
    
    //algo/lexicocmp1.cpp
    extern void LexicoGraphicalCompareTest();
    
    //algo/issorted1.cpp
    extern void isSortedExample();
    
    //algo/ispartitioned1.cpp
    extern void isPartitionedExample();
    
    //algo/isheap1.cpp
    extern void isHeapExample();
    
    //algo/allanynone1.cpp
    extern void allAnyNoneTest();
}

#endif /* SEARCHINGELEMENTS_H */

