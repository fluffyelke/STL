/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SharedPtrDeleter.h
 * Author: default
 *
 * Created on July 26, 2022, 3:27 PM
 */

#ifndef SHAREDPTRDELETER_H
#define SHAREDPTRDELETER_H

#include <fstream>


namespace Utils {
    class FileDeleter {
        std::string fileName;
    public:
        FileDeleter(const std::string& fn) 
            : fileName{fn} {
                std::cout << "File: [" << fileName << "] Created!\n";
        }
        void operator() (std::ofstream* fp) {
            std::cout << "File: [" << fileName << "] Closed\n";
            fp->close();                        //closes the file
            std::cout << "File: [" << fileName << "] Removed\n";
            std::remove(fileName.c_str());      //delete the file
        }
    };
}

#endif /* SHAREDPTRDELETER_H */

