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
#include <algorithm>
#include <iterator>

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
#include "chapters/C07STLContainers/SetAndMultiset/SetAndMultiset.h"
#include "chapters/C07STLContainers/MapAndMultimap/MapAndMultimap.h"
#include "chapters/C07STLContainers/UnorderedContainers/UnorderedContainers.h"
#include "chapters/C07STLContainers/UnorderedContainers/UserDefinedHashFunctionAndEquivalentCriterion.h"
#include "chapters/C07STLContainers/UnorderedContainers/UsingLambdaAsHash.h"
#include "chapters/C07STLContainers/CStyleArrayAsSTL/CStyleContAsSTL.h"
#include "chapters/C07STLContainers/ReferenceSemantic/RefSemantic.h"
#include "chapters/C09Iterators/RandomAccessIter.h"
#include "chapters/C09Iterators/AuxiliaryIterFunctions.h"
#include "chapters/C09Iterators/IteratorAdapters.h"
#include "chapters/C09Iterators/InsertIterators.h"
#include "chapters/C09Iterators/OstreamIterators.h"
#include "chapters/C10FunctionObjectsAndUsingLambdas/ConceptOfFunctionObject/C10FunctionObject.h"
#include "chapters/C10FunctionObjectsAndUsingLambdas/PredifinedFunctionObjectsAndBinders/PredifinedFunctionObjectsList.h"
#include "chapters/C10FunctionObjectsAndUsingLambdas/PredifinedFunctionObjectsAndBinders/UserDefinedFunctionObjects.h"
#include "chapters/C10FunctionObjectsAndUsingLambdas/UsingLambdas/LambdasAsFuncObjects.h"
#include "chapters/C11Algorithms/for_each/ForEach.h"
#include "chapters/C11Algorithms/NonModifying/CountAndCountIf.h"
#include "chapters/C11Algorithms/NonModifying/MinimumAndMaximum.h"
#include "chapters/C11Algorithms/NonModifying/SearchingElements.h"
#include "chapters/C11Algorithms/Modifying/ModifyingAlgs.h"
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
//    C07Containers::testSpliceAfter();
//    C07Containers::exampleOfForwardList();
//    C07Containers::exampleOfLowerUpperBound();
//    C07Containers::setMultisetExample();
//    C07Containers::testRuntimeCmp();
//    C07Containers::mapMultimapExample();
//    C07Containers::mapMultimapExample2();
//    C07Containers::multimapDictionary();
//    C07Containers::findElemInMap();
//    C07Containers::mapWithSortCriterionAtRunTimeExample();
//    C07Containers::exampleOfUnorderedSet();
//    C07Containers::exampleOfUnorderedMultiset();
//    C07Containers::testOwnHash();
//    C07Containers::testLambdaHash();
//    C07Containers::testBucketInterface();
//    C07Containers::unordMultiMapHash();
//    C07Containers::cstyleArrAsSTL();
//    C07Containers::testRefSemantic();
}

void chapter08() {
    
}

void chapter09() {
//    C09Iterators::randAccessIterExample();
//    C09Iterators::advanceExample();
//    C09Iterators::distanceExample();
//    C09Iterators::iterSwapExample();
//    C09Iterators::revIterExample();
//    C09Iterators::revIterExample2();
//    C09Iterators::revIterExample3();
//    C09Iterators::revIterExample4();
//    C09Iterators::backInserterTest();
//    C09Iterators::frontInserterTest();
//    C09Iterators::inserterTest();
//    C09Iterators::ostreamIterTest1();
//    C09Iterators::ostreamIterTest2();
//    C09Iterators::istreamIterTest();
//    C09Iterators::streamIterAndAdvance();
//    C09Iterators::testUserDefinedIter();
    
    
}

void chapter10() {
//    C10FuncObj::sequenceTest1();
//    C10FuncObj::sequenceTest2();
//    C10FuncObj::forEachReturnExample();
//    C10FuncObj::predVsFuncObjTest();
//    C10FuncObj::bindExample();
//    C10FuncObj::testBindGlobalFunc();
//    C10FuncObj::testCallingMemberFuncs();
//    C10FuncObj::testFoPow();
//    C10FuncObj::compareToSTDBind();
//    C10FuncObj::lambdaMean();
//    C10FuncObj::lambdaMutableUse();
//    C10FuncObj::lambdaCallsGlobal();
//    C10FuncObj::testPersonLambda();
    
}

void chapter11ModifyingAlgs()  {
//    C11Algorithms::copyExample();
//    C11Algorithms::copyExample2();
//    C11Algorithms::copyExample3();
//    C11Algorithms::moveExample();
//    C11Algorithms::transformExample();
//    C11Algorithms::transformExample2();
//    C11Algorithms::swapRangesExample();
//    C11Algorithms::fillExample();
//    C11Algorithms::generateExample();
//    C11Algorithms::iotaExample();
//    C11Algorithms::replaceExample();
//    C11Algorithms::replaceExample2();
//    C11Algorithms::removeExample();
//    C11Algorithms::removeCopyExample();
//    C11Algorithms::uniqueExample();
//    C11Algorithms::uniqueCopyExample();
    C11Algorithms::uniqueCopyExample2();
}

void chapter11() {
//    C11Algorithms::testForEach1();
//    C11Algorithms::testForEach2();
//    C11Algorithms::testForEach3();
//    C11Algorithms::testCount1();
//    C11Algorithms::testMinMax1();
//    C11Algorithms::exampleFind1();
//    C11Algorithms::exampleFindIfNot();
//    C11Algorithms::exampleSearchN1();
//    C11Algorithms::exampleSearch1();
//    C11Algorithms::exampleSearch2();
//    C11Algorithms::exampleFindEnd();
//    C11Algorithms::exampleFindFirstOf();
//    C11Algorithms::exampleAdjacentFind();
//    C11Algorithms::exampleEqual1();
//    C11Algorithms::isPermutationTest();
//    C11Algorithms::mismatchExample();
//    C11Algorithms::LexicoGraphicalCompareTest();
//    C11Algorithms::isSortedExample();
//    C11Algorithms::isPartitionedExample();
//    C11Algorithms::isHeapExample();
//    C11Algorithms::allAnyNoneTest();
    chapter11ModifyingAlgs();
    
}

int main(int argc, char** argv) {
    
    chapter11();

  
    return 0;
}

