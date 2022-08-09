/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <unordered_set>

#include "UserDefinedHashFunctionAndEquivalentCriterion.h"
#include "HashVal.h"
#include "../../C06StandardTemplateLibrary/Utils/Utils.h"

namespace C07Containers {

    Customer::Customer(std::string firstName, std::string secondName, long no) :
        firstName(firstName), secondName(secondName), no(no) {
    }
    std::ostream& operator<<(std::ostream& os, const Customer& obj) {
        return os << "[" << obj.firstName << ", " << obj.secondName << ", " << obj.no << "]";
    }
    
    std::size_t CustomerHash::operator()(const Customer& obj) const {
        return HashVal::hashVal(obj.firstName, obj.secondName, obj.no);
    }

    bool CustomerEqual::operator()(const Customer& left, const Customer& right) const {
        return left.no == right.no;
    }

    void testOwnHash() {
        //unordered set with own hash function and equivalence criterion
        std::unordered_set<Customer, CustomerHash, CustomerEqual> custSet;
        custSet.insert(Customer("nico", "josuttis", 42));
        
        Containers::printElements(custSet);
    }
}