/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: default
 *
 * Created on July 25, 2022, 1:10 PM
 */

#include <cstdlib>
#include <iostream>
#include <array>
#include <vector>

#include "chapters/C03NewFeatures/Ch03.h"
#include "utils/Utils.h"
#include "utils/ExeptionHandling.h"
#include "chapters/C04GeneralConcepts/CallableObjects/CallableObjects.h"
#include "chapters/C05Utilities/PairsAndTuples/PairsExamples.h"
#include "chapters/C05Utilities/PairsAndTuples/TuplesExamples.h"
#include "chapters/C05Utilities/SmartPointers/SharedPtrExample.h"
#include "chapters/C05Utilities/SmartPointers/WeakPtrExample.h"
#include "chapters/C05Utilities/SmartPointers/UniquePtr.h"
#include "chapters/C05Utilities/NumericLimits/NumericLimits.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/TypeTraits.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/FunctionTypeWrappers.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/AuxilaryFunctions.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/Ratio.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/ClockAndTimes/ChronoExamples.h"
#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/ClockAndTimes/DateAndTime.h"
#include "chapters/C06StandardTemplateLibrary/SequenceContainers/C06Vector.h"
#include "chapters/C06StandardTemplateLibrary/SequenceContainers/C06Deque.h"
#include "chapters/C06StandardTemplateLibrary/SequenceContainers/C06Arrays.h"
#include "chapters/C06StandardTemplateLibrary/SequenceContainers/C06List.h"
#include "chapters/C06StandardTemplateLibrary/SequenceContainers/C06ForwardList.h"
#include "chapters/C06StandardTemplateLibrary/AssociativeContainers/C06Multiset.h"
#include "chapters/C06StandardTemplateLibrary/AssociativeContainers/C06Set.h"
#include "chapters/C06StandardTemplateLibrary/AssociativeContainers/C06Multimap.h"
#include "chapters/C06StandardTemplateLibrary/AssociativeContainers/C06Map.h"
#include "chapters/C06StandardTemplateLibrary/UnorderedContainers/C06UnorderedMultiSet.h"
#include "chapters/C06StandardTemplateLibrary/UnorderedContainers/C06UnorderedSet.h"
#include "chapters/C06StandardTemplateLibrary/UnorderedContainers/C06UnorderedMap.h"
#include "chapters/C06StandardTemplateLibrary/UnorderedContainers/C06UnorderedMultiMap.h"
#include "chapters/C06StandardTemplateLibrary/Iterators/C06Iterators.h"
#include "chapters/C06StandardTemplateLibrary/Algorithms/Examples.h"
#include "chapters/C06StandardTemplateLibrary/Iterators/InsertIterators/C06InsertIterators.h"
#include "chapters/C06StandardTemplateLibrary/Algorithms/ManipulatingAlgorithms/C06Removing.h"
#include "chapters/C06StandardTemplateLibrary/Algorithms/FunctionAsAlgorithmArgument/C06FuncAsAlgArg.h"
#include "chapters/C06StandardTemplateLibrary/Predicates/UnaryPredicate.h"
#include "chapters/C06StandardTemplateLibrary/Predicates/BinaryPredicate.h"
#include "chapters/C06StandardTemplateLibrary/Predicates/UsingLambda.h"
#include "chapters/C06StandardTemplateLibrary/FunctionObjects/FuncObject.h"
#include "chapters/C06StandardTemplateLibrary/FunctionObjects/FunctionObjectDefinition.h"
#include "chapters/C06StandardTemplateLibrary/FunctionObjects/PredifinedFuncObjects/PreDefinedExamples.h"
#include "chapters/C06StandardTemplateLibrary/FunctionObjects/Binders/C06Binders.h"
#include "chapters/C07STLContainers/Arrays/ArrayInSTD.h"
#include "chapters/C07STLContainers/Vectors/VectorInSTD.h"
#include "chapters/C07STLContainers/Deque/DequeInSTD.h"
#include "chapters/C07STLContainers/Lists/ListInSTD.h"
#include "chapters/C07STLContainers/ForwardList/ForwardListInSTD.h"
//#include "chapters/C05Utilities/TypeTraitsAndTypeUtilities/ClockAndTimes/Utils.h"

using namespace std;

/*
 * 
 */

void exceptionExample() {
    
    std::vector<int> myVec{10, 20, 30, 40, 50};
    
    try {
        int a = myVec.at(7);
    }
    catch(...) {
        Utils::processException();
    }
    
}
void beforeChapter6() {
    
//    Tuples::printTuple();
//    SharedPtr::testMemoryDetacher();
//    WeakPtr::testWeakPtr();
//    UniquePtr::listFiles();
//    Numerics::limitsOne();
//    Traits::testFunctionWrappers();
//    FuncWrappers::testMemberFunc();
//    AuxilaryFunc::testIntPtrComp();
//    Ratio::testRatio();
//    Chrono::testMakeTimePoint();
}

void chapter6() {
    //    C06STL::testForwardList();
//    C06STL::testTransform1();
//    C06STL::testUnaryPredicate();
//    C06STL::testPersonSortPredicate();
//    C06STL::firstNumBetweenXandY();
//    C06STL::testFuncObject();
//    C06STL::exampleAddValueFuncCall();
//    C06STL::negateExample();
//    C06STL::bindersExample();
    
}

void chapter07() {
//    C07Containers::arraysExample();
//    C07Containers::vectorExample();
//    C07Containers::dequeExample();
//    C07Containers::listsExample();
//    C07Containers::forwardListFind();
    C07Containers::testSpliceAfter();
}
int main(int argc, char** argv) {

    chapter07();

    
    return 0;
}

