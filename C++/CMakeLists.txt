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


set(example_programs    raii
    override
    namespace
    destructor
    regexMatch
    uniqueLock
    constructor
    regexSearch
    methodStatic
    templateCRTP
    threadCreate
    templateTypes
    IOStreamsInOut
    IOStreamsState
    templateLookup
    threadLifetime
    functionDefault
    initializerList
    IOStreamsOutput
    rvalueReference
    copyMoveSemantic
    readerWriterLock
    regexMatchObject
    stlContainerSize
    stringConstructor
    vectorConstructor
    IOStreamsFormatter
    userDefinedLiteral
    automaticReturnType
    multipleInheritance
    referenceWrapperClass
    templateTypeParameter
    IOStreamsStringStreams
    stlContainerComparison
    templateCRTPRelational
    templateSpecialization
    inheritanceAccessRights
    IOStreamsInputFormatted
    stringNumericConversion
    alternativeFunctionSyntax
    callableUnitLambaFunction
    templateArgumentDeduction
    multipleInheritanceVirtual
    safeInitializationCallOnce
    templateSpecializationFull
    bindAndFunctionDispatchTable
    classMemberInitializerWidget
    stringComparisoConcatenation
    stlContainerAssignmentAndSwap
    stlOrderedUnorderedComparison
    templateClassTemplateInheritance
    templateSpecializationTypeTraits
    templateTemplateTemplatesParameter
    templateClassTemplateTypeFriendship
    templateClassTemplateGeneralFriendship
    templateClassTemplateSpecialFriendship
    stlOrderedAssoziativeContainerAssoziativeArray
    new
    auto
    enum
    list
    pair
    swap
    array
    mutex
    tuple
    delete
    random
    string
    default
    pointer
    weakPtr
    bigArray
    decltype
    explicit
    iterator
    castConst
    IOStreams
    lockGuard
    rawString
    sharedPtr
    singleton
    uniquePtr
    castStatic
    dotProduct
    castDynamic
    dequeModify
    forwardList
    inheritance
    methodConst
    threadLocal
    tupleHelper
    accessRights
    autoExplicit
    packagedTask
    regexReplace
    stringAccess
    unorderedMap
    vectorModify
    methodVirtual
    overrideFinal
    pointerMember
    promiseFuture
    regexIterator
    stlAlgorithms
    threadMethods
    typeTraitsGcd
    asyncLazyEager
    iteratorStream
    lambdaFunction
    typeTraitsCopy
    uniquePtrArray
    bindAndFunction
    built_inLiteral
    castReinterpret
    constExpression
    cyclicReference
    dotProductAsync
    IOStreamsRandom
    methodConstexpr
    stringCverusC++
    threadArguments
    typeInformation
    functionOverload
    iteratorExplicit
    iteratorInserter
    referenceWrapper
    sharedPtrDeleter
    unorderedMapHash
    conditionVariable
    iteratorUtilities
    methodThisPointer
    perfectForwarding
    rangeBasedForLoop
    lambdaFunctionThis
    regexWordStatistic
    stringModification
    stringSizeCapacity
    constructorExplicit
    operatorOverloading
    stlAlgorithmsRemove
    bindLambdaComparison
    callableUnitFunction
    constExpressionCpp14
    inheritanceBaseClass
    overloadNewAndDelete
    stlAlgorithmsForEach
    stlContainerIterator
    unorderedMapMultimap
    constructorDelegation
    constructorInheriting
    lambdaFunctionCapture
    lambdaFunctionClosure
    lambdaFunctionGeneric
    overloadNewAndDelete2
    templateClassTemplate
    uniformInitialization
    classMemberInitializer
    constructorInitializer
    stlAlgorithmsTransform
    inheritanceAbstractBase
    referenceWrapperRefCref
    stlAlgorithmsAllAnyNone
    stlContainerConstructor
    stlContainerSearchRange
    templateDefaultArgument
    promiseFutureSynchronize
    safeInitializationStatic
    typeTraitsTypeCategories
    conditionVariablePingPong
    IOStreamsInputUnformatted
    templatePerfectForwarding
    templateVariadicTemplates
    callableUnitFunctionObject
    templateFunctionsTemplates
    templateAutomaticReturnType
    templateClassTemplateMethods
    operatorOverloadingAssignment
    smartPointerPerformanceNative
    smartPointerPerformanceShared
    smartPointerPerformanceUnique
    operatorOverloadingParentheses
    templateSpecializationExternal
    packagedTaskHardwareConcurrency
    stlOrderedAssoziativeContainerModify
    stlOrderedAssoziativeContainerSearch
    unorderedOrderedContainerPerformance
    templateFunctionsTemplatesOverloading
    stlOrderedAssoziativeContainerComparison
   )

foreach(example_program ${example_programs})
  set(sources ${example_program}.cpp)
  source_group("Source Files" FILES{sources})
  add_executable(${example_program} ${sources})
endforeach()
