/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <memory>
#include <vector>
#include <iostream>

#include "SharedPtrExample.h"
#include "../../../utils/SharedPtrDeleter.h"
#include "../../../utils/SmartPtrs/SharedMemoryDetacher.h"

namespace SharedPtr {
    
    void deletePArr(int* p) {
        delete [] p;
    }
    
    void testSharedPtr() {
        //two shared ptrs, represent two persons by name
        std::shared_ptr<std::string> pVanya(new std::string("vanya"));
        std::shared_ptr<std::string> pElinna(new std::string("elinna"));
        
        //alternative approach
//        std::shared_ptr<std::string> pVanya{new std::string("vanya")};
//        std::shared_ptr<std::string> pElinna{new std::string("elinna")};
        
        //alternative approach
//        std::shared_ptr<std::string> pVanya = std::make_shared(std::string("vanya"));
//        std::shared_ptr<std::string> pElinna = std::make_shared(std::string("elinna"));
        
        //alternative approach
        // std::shared_ptr<std::string> pVanya;
        // pVanya.reset(new std::string("vanya"));
        
        
        //capitalize persons names
        (*pVanya)[0] = 'V';
        pElinna->replace(0, 1, "E");
        
        //put them multiple times in container
        std::vector<std::shared_ptr<std::string>> myCont;
        myCont.emplace_back(pVanya);
        myCont.emplace_back(pVanya);
        myCont.emplace_back(pElinna);
        myCont.emplace_back(pVanya);
        myCont.emplace_back(pElinna);
        myCont.emplace_back(pElinna);
        myCont.emplace_back(pVanya);
        for(auto elem : myCont) {
            std::cout << *elem << " ";
        }
        std::cout << std::endl;
        
        *pElinna = "Linichka";
        
        for(auto elem : myCont) {
            std::cout << *elem << " ";
        }
        std::cout << std::endl;
        
        //print some internal data
        std::cout << "useCount: " << myCont[0].use_count() << std::endl;
        
        
        //Defining a deleter to object in shared_ptr, this is non-array example.
        std::shared_ptr<std::string> pDessy(new std::string("Dessy"), [] (std::string* str) {
            std::cout << "Delete: " << *str << std::endl;
            delete str;
        });
        
        std::vector<std::shared_ptr<std::string>> testCont{pDessy, pDessy, pDessy, pDessy};
        for(auto& elem : testCont) {
            std::cout << elem.use_count() << std::endl;
            elem = nullptr;
        }
        
        std::cout << testCont[0].use_count() << std::endl;
        pDessy = nullptr;
        
        
        //This is the array approach
        std::shared_ptr<int> pInt(new int[10], [](int* p) {
            delete[] p;
        });
        
        //This is the array approach
        std::shared_ptr<int> pInt2(new int[10], deletePArr);
        
        
        //and officialy provided deleter for unique_ptr
        std::shared_ptr<int> pInt3(new int[10], std::default_delete<int[]>());
        std::cout << "End of program\n";
        
    }
    
    void createAndOpenTempFile() {
        std::shared_ptr<std::ofstream> tempFile(new std::ofstream("tmpfile.txt"), Utils::FileDeleter("tmpfile.txt") );
    }
    
    void testMemoryDetacher() {
        //get and attach shared memory for 100 ints
        std::shared_ptr<int> smPtr(Utils::SmartPtrs::getSharedIntMemory(100));
        
        // init shared memory
        for(int i = 0; i < 100; i++) {
            smPtr.get()[i] = i * 42;
        }
        //...
        
        std::cout << "<return>" << std::endl;
        std::cin.get();
        
        //...
        
        //release shared memory here
        smPtr.reset();
        
        //...
    }
}