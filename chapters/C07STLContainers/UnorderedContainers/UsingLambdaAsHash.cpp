/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unordered_set>

#include "UsingLambdaAsHash.h"
#include "HashVal.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"

namespace C07Containers {

    Customer2::Customer2(const std::string& f, const std::string& l, long n) 
        : firstName{f}, lastName{l}, no{n} {

    }
    std::string Customer2::getFirstName() const {
        return firstName;
    }

    std::string Customer2::getLastName() const {
        return lastName;
    }

    long Customer2::getNumber() const {
        return no;
    }
    
    std::ostream& operator <<(std::ostream& os, const Customer2& obj) {
        return os << "[" << obj.firstName << "," << obj.lastName << "," << obj.no << "]";
    }

    
    void testLambdaHash() {
        //lambda for user defined hash function
        auto hashLambda = [] (const Customer2& obj) {
          return HashVal::hashVal(obj.getFirstName(), obj.getLastName(), obj.getNumber());  
        };
        
        //lambda for user defined equivalence criterion
        auto eqLambda = [] (const Customer2& left, const Customer2& right) {
            return left.getNumber() == right.getNumber();
        };
        
        
        //create unordered set with user defined behaviour
        std::unordered_set<Customer2, decltype(hashLambda), decltype(eqLambda)> custSet(10, hashLambda, eqLambda);
        
        custSet.insert(Customer2("nico", "josuttis", 42));
        Containers::printElements(custSet);
    }
}


