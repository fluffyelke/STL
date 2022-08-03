/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <memory>
#include <experimental/filesystem>
#include "UniquePtr.h"


namespace UniquePtr {

    void DirCloser::operator()(DIR* dPtr) {
        if(closedir(dPtr) != 0) {
            std::cerr << "OOPS: closedir() failed!\n";
        }
    }

    void openCurrentDirectory() {
        //open current directory 
        std::unique_ptr<DIR, DirCloser> pDir(opendir("."));
        
        struct dirent* dp;
        while((dp = readdir(pDir.get())) != nullptr) {
            std::string fileName(dp->d_name);
            std::cout << "process: " << fileName << std::endl;
        }
    }
    
    void printFiles(const std::string& file) {
        std::unique_ptr<DIR, DirCloser> pDir(opendir(file.c_str()));
        
        struct dirent* dp;
        if((dp = readdir(pDir.get())) != nullptr) {
            
            std::cout << std::string(dp->d_name) << std::endl;
            ++dp;
            printFiles(std::string(dp->d_name));
        }
    }
    
    void listFiles() {
        std::string directory{};
//        std::experimental::filesystem::recursive_directory_iterator
        for (std::experimental::filesystem::recursive_directory_iterator i("."), end; i != end; ++i) {
            
//            if(is_directory(i->path())) {
//                directory = std::string(i->path()) + "/";
//            }
            if (!is_directory(i->path())) {
              std::cout << directory << i->path() << "\n";
            }
//            else {
//                std::cout << i->path() << std::endl;
//            }
        }
    }
}