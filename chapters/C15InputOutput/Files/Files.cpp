/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <fstream>
#include <iostream>
#include <iomanip>

#include "Files.h"


namespace C15Files {
    
    void writeCharsetToFile(const std::string& fileName) {
        //open output file
        std::ofstream file(fileName);
        
        //file opened?
        if(!file.is_open()) {
            // No abort program
            std::cerr << "can't open output file\"" << fileName << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        //write character set
        for(int i = 32; i < 128; ++i) {
            file << "value: " << std::setw(3) << i << " " << "char: " << static_cast<char>(i) << std::endl;
        }
    }   //closes file automatically
    
    void outputFile(const std::string& fileName) {
        //open input file
        std::ifstream file(fileName);
        
        if(!file.is_open()) {
            // No abort program
            std::cerr << "can't open output file\"" << fileName << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        //copy file content to std::cout
        char c;
        while(file.get(c)) {
            std::cout.put(c);
        }
    }   //closes file automatically
    
    void fstreamExample1() {
        writeCharsetToFile("chapters/C15InputOutput/Files/charset.out");
        outputFile("chapters/C15InputOutput/Files/charset.out");
    }
    
    
    
    
    
    //utils
    std::ofstream openToWriteFile(const std::string& fileName) {
        std::ofstream file(fileName);
        if(!file.is_open()) {
            // No abort program
            std::cerr << "can't open output file\"" << fileName << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        return file;
    }
    std::ifstream openToWriteFile(const std::string& fileName) {
        std::ifstream file(fileName);
        if(!file.is_open()) {
            // No abort program
            std::cerr << "can't open output file\"" << fileName << "\"" << std::endl;
            exit(EXIT_FAILURE);
        }
        
        return file;
    }
}