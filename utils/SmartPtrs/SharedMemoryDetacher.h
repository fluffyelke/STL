/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SharedMemoryDetacher.h
 * Author: default
 *
 * Created on July 26, 2022, 3:49 PM
 */

#ifndef SHAREDMEMORYDETACHER_H
#define SHAREDMEMORYDETACHER_H

#include <memory>


namespace Utils {
    namespace SmartPtrs {
        class SharedMemoryDetacher {
        public:
            void operator() (int* p);
        };
        
        extern std::shared_ptr<int> getSharedIntMemory(int num);
    }
}

#endif /* SHAREDMEMORYDETACHER_H */

