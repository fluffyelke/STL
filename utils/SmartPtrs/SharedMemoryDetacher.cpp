/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <sys/mman.h>
#include <fcntl.h>
#include <cstring>
#include <unistd.h>   //for shared memory
#include <cerrno>
#include <string>

#include "SharedMemoryDetacher.h"


namespace Utils {
    namespace SmartPtrs {
        
        void SharedMemoryDetacher::operator() (int* p) {
            std::cout << "unlink /tmp1234" << std::endl;
            if(shm_unlink("/tmp1234") != 0) {
                std::cerr << "OOPS: shm_unlink() failed\n";
            }
        }

        std::shared_ptr<int> getSharedIntMemory(int num) {
            void* mem;
            int shmfd = shm_open("/tmp1234", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG);
            if(shmfd < 0) {
                throw std::string(strerror(errno));
            }
            if(ftruncate(shmfd, num * sizeof(int)) == -1 ) {
                throw std::string(strerror(errno));
            }
            
            mem = mmap(nullptr, num * sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shmfd, 0);
            
            if(mem == MAP_FAILED) {
                throw std::string(strerror(errno));
            }
            
            return std::shared_ptr<int>(static_cast<int*>(mem), SharedMemoryDetacher());
        }
    }
}