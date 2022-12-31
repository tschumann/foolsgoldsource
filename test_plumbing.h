//========= Copyright © 2008-2022, Team Sandpit, All rights reserved. ============
//
// Purpose: Mock engine for testing
//
// $NoKeywords: $
//================================================================================

#ifndef __TEST_PLUMBING_H__
#define __TEST_PLUMBING_H__

#ifdef _MSC_VER

#include "CppUnitTest.h"

#include "foolsgoldsource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

// CppUnitTestFramework does something strange and breaks the engine's ability to load the .dll so stub it out when building normally
// test.ps1 creates a file called run_tests so that during the test script this block is skipped and vstest can run the tests
#if !__has_include("run_tests")

#undef TEST_METHOD
#define TEST_METHOD(methodName) static const void* test##methodName() { return nullptr; } void methodName()

#endif // !__has_include("run_tests")

#else

#warning Tests are only defined for Visual Studio

#endif // _MSC_VER

#endif // __TEST_PLUMBING_H__