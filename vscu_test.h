//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Visual Studio CppUnit support for solutions that don't have a separate unit test project.
//          In an ideal world this shouldn't be needed but many Half-Life mods and plugins don't have
//          a separate unit test project in the solution and creating one isn't always simple - this
//          helps allow unit tests to exist as part of the main project rather than forcing the creation
//          of a separate unit test project.
//
// $NoKeywords: $
//================================================================================

#ifndef __VSCU_TEST_H__
#define __VSCU_TEST_H__

#ifdef _MSC_VER

#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// create this file before compiling for unit testing then delete it after compilation for testing
#if !__has_include("run_tests.hxx")

#undef TEST_CLASS
#define TEST_CLASS(className) class className

#undef TEST_METHOD_INITIALIZE
#define TEST_METHOD_INITIALIZE(methodName) void methodName()

#undef TEST_METHOD_CLEANUP
#define TEST_METHOD_CLEANUP(methodName) void methodName()

// stub out TEST_METHOD when building normally because CppUnitTestFramework does something strange and breaks the engine's ability to load the .dll
#undef TEST_METHOD
#define TEST_METHOD(methodName) static const void* test##methodName() { return nullptr; } void methodName()

// stub out BEGIN_TEST_METHOD_ATTRIBUTE when building normally otherwise the tests won't compile
#undef BEGIN_TEST_METHOD_ATTRIBUTE
#define BEGIN_TEST_METHOD_ATTRIBUTE(methodName)

// stub out TEST_IGNORE when building normally otherwise the tests won't compile
#undef TEST_IGNORE
#define TEST_IGNORE()

// stub out END_TEST_METHOD_ATTRIBUTE when building normally otherwise the tests won't compile
#undef END_TEST_METHOD_ATTRIBUTE
#define END_TEST_METHOD_ATTRIBUTE()

#endif // !__has_include("run_tests.hxx")

#endif // _MSC_VER

#endif // __VSCU_TEST_H__