//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Mock GoldSource engine tests
//
// $NoKeywords: $
//================================================================================

#include "pch.h"
#include "CppUnitTest.h"

#include "../foolsgoldsource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace foolsgoldsourcetest
{
	TEST_CLASS(foolsgoldsource)
	{
	public:

		TEST_METHOD(TestAllocString)
		{
			string_t hello = ::foolsgoldsource::pfnAllocString( "hello" );
			string_t world = ::foolsgoldsource::pfnAllocString( "world" );
			string_t newline = ::foolsgoldsource::pfnAllocString( "\n" );

			Assert::AreEqual( "hello", ::foolsgoldsource::gEngine.GetString( hello ) );
			Assert::AreEqual( "world", ::foolsgoldsource::gEngine.GetString( world ) );
			Assert::AreEqual( "\n", ::foolsgoldsource::gEngine.GetString( newline ) );
		}

		TEST_METHOD(TestFindEntityByVars)
		{
			edict_t* pEdict1 = ::foolsgoldsource::gEngine.CreateEdict();
			edict_t* pEdict2 = ::foolsgoldsource::gEngine.CreateEdict();
			edict_t* pEdict3 = ::foolsgoldsource::gEngine.CreateEdict();

			Assert::IsTrue( pEdict1 == ::foolsgoldsource::pfnFindEntityByVars( &pEdict1->v ) );
			Assert::IsTrue( pEdict2 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict1->v ) );
			Assert::IsTrue( pEdict3 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict1->v ) );

			Assert::IsTrue( pEdict1 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict2->v ) );
			Assert::IsTrue( pEdict2 == ::foolsgoldsource::pfnFindEntityByVars( &pEdict2->v ) );
			Assert::IsTrue( pEdict3 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict2->v ) );

			Assert::IsTrue( pEdict1 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict3->v ) );
			Assert::IsTrue( pEdict2 != ::foolsgoldsource::pfnFindEntityByVars( &pEdict3->v ) );
			Assert::IsTrue( pEdict3 == ::foolsgoldsource::pfnFindEntityByVars( &pEdict3->v ) );
		}

		TEST_METHOD(TestGetGameDir)
		{
			char szGameDirectory[16] = "";
			::foolsgoldsource::pfnGetGameDir( szGameDirectory );
			Assert::AreEqual( "valve", szGameDirectory );

			::foolsgoldsource::gEngine.SetGameDirectory("gearbox");

			::foolsgoldsource::pfnGetGameDir( szGameDirectory );
			Assert::AreEqual( "gearbox", szGameDirectory );
		}
	};
}
