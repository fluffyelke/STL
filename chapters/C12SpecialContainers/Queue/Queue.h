/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Queue.h
 * Author: default
 *
 * Created on August 24, 2022, 3:25 PM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <vector>
#include <condition_variable>


namespace C12Containers {
    /**
     * c++ queue implementation
     * 
        namespace std {
            template<typemane T, typename Container = std::deque<T>>
            class queue;
        }
     * 
     * 
     * c++ priority_queue implementation
        namespace std {
            template<typemane T, 
            typename Container = std::vector<T>, 
            typename Compare = std::less<typename Container::value_type>>
            class priority_queue;
        }
     */
    
    // contadapt/queue1.cpp
    extern void queueExample();
    
    // contadapt/priorityqueue1.cpp
    extern void priorityQueueExample();
    
}

#endif /* QUEUE_H */

