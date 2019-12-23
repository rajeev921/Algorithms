# Require a recent version of cmake
cmake_minimum_required(VERSION 2.8.4 FATAL_ERROR)

# This project is C++ based.
project(seminar)

if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    set(CMAKE_CXX_FLAGS "-O3 -std=c++14 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0)
	    message(WARNING "!!!! GCC versions must be at least 5.0 !!!!")
        message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL Clang)
    set(CMAKE_CXX_FLAGS "-O3 -std=c++14 -pthread")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.5)
        message(WARNING "!!!! Clang version must be at least 3.5 !!!!")
		message(WARNING "!!!! Adust the makefile to build with a different compiler. !!!!")
    endif()
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
    set(CMAKE_CXX_FLAGS "/Ox /EHsc")
    if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 19.10)    
        message(WARNING "!!!! MSVC version must be at least 19.10 !!!!")
    endif()	
else()
    message(WARNING "!!! You are using an unsupported compiler! Compilation has only been tested with GCC >= 5.0, Clang >= 3.5, or MSVC >= 19.10. !!!")
endif()
    

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")

set(CMAKE_VERBOSE_MAKEFILE on)


set(example_programs    lock
    delete
    countDown
    recursiveMutex
    makeTriple
    templateAdd
    explicitToImplicit
    templateIsPointer
    lambdaFunctionCapture
    constructorInheriting
    IOStreamsStreamBuffer
    constructorDelegationRecursive
    stringInputOutput
    constructorBalance
    array
    tuple
    bigArray
    stringFind
    vectorSize
    autoExplicit
    initializerList
    regexSearchEmail
    IOStreamsFraction
    perfectForwarding
    typeModifications
    rangedBasedForLoop
    regexWordStatistic
    regexReplaceDoubles
    bindLambdaComparison
    unorderedSetHashInfo
    unorderedSetMultiset
    stlAlgorithmenForEach
    promiseFutureException
    singletonMultithreading
    stlAlgorithmenAccumulate
    threadArgumentsVariation
    operatorOverloadingLambda
    templateVariadicTemplates
    userDefinedLiteralExtended
    classMemberInitializerWidget
    templateAutomaticReturnTypeTypeTraits
    automaticReturnType
    led
    sum
    power1
    power2
    power3
    printf
    shareMe
    polymorph
    gcdVariations
    templateTypes
    dispatchGeneric
    dispatchConcepts
    dispatchPolymorph
    templatesCRTPShareMe
    templateCRTPRelational
    templateNonTypeParameter
    templateClassTemplateMethods
    templateClassTemplateMethods2
    templateClassTemplateMethods3
   )

foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)
  source_group("Source Files" FILES{sources})
  add_executable(${example_program} ${sources})
endforeach()
