/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UniquePtr.h
 * Author: default
 *
 * Created on July 27, 2022, 4:40 PM
 */

#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H

#include <dirent.h>


namespace UniquePtr {
    class DirCloser {
    public:
        void operator() (DIR* dPtr);
    };
    
    
    extern void openCurrentDirectory();
    extern void printFiles(const std::string& file);
    extern void listFiles();
}

#endif /* UNIQUEPTR_H */

