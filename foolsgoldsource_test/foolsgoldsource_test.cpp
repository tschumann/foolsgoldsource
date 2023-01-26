//========= Copyright © 2008-2023, Team Sandpit, All rights reserved. ============
//
// Purpose: Mock GoldSource engine tests
//
// $NoKeywords: $
//================================================================================

#include "pch.h"
#include "CppUnitTest.h"

#define CLIENT_DLL

#include "../foolsgoldsource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace foolsgoldsourcetest
{
	TEST_CLASS(foolsgoldsource)
	{
	public:

		TEST_METHOD_INITIALIZE(SetUp)
		{
			::foolsgoldsource::gEngine.SetIsFogOn( false );
			::foolsgoldsource::gEngine.SetRenderer( RENDERER_OPENGL );
		}

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
			edict_t* pEdict1 = ::foolsgoldsource::pfnCreateEntity();
			edict_t* pEdict2 = ::foolsgoldsource::pfnCreateEntity();
			edict_t* pEdict3 = ::foolsgoldsource::pfnCreateEntity();

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

		TEST_METHOD(TestGetCvarPointer)
		{
			cvar_t* hello = ::foolsgoldsource::pfnRegisterVariable( "hello", "1", 0 );
			cvar_t* world = ::foolsgoldsource::pfnRegisterVariable( "world", "0", 0 );

			Assert::IsTrue( hello == ::foolsgoldsource::pfnGetCvarPointer( "hello" ) );
			Assert::IsTrue( world == ::foolsgoldsource::pfnGetCvarPointer( "world" ) );
			Assert::IsNull( ::foolsgoldsource::pfnGetCvarPointer( "test" ) );
		}

		TEST_METHOD(TestFog)
		{
			float fColors[3] = { 0.0f, 0.0f, 0.0f };

			::foolsgoldsource::Fog( fColors, 0.0f, 0.0f, 1 );
			Assert::IsTrue( ::foolsgoldsource::gEngine.GetIsFogOn() );
			::foolsgoldsource::Fog( fColors, 0.0f, 0.0f, 0 );
			Assert::IsFalse( ::foolsgoldsource::gEngine.GetIsFogOn() );
		}

		TEST_METHOD(TestIsHardware)
		{
			::foolsgoldsource::gEngine.SetRenderer( RENDERER_SOFTWARE );
			Assert::AreEqual( 0, ::foolsgoldsource::IsHardware() );
			::foolsgoldsource::gEngine.SetRenderer( RENDERER_OPENGL );
			Assert::AreEqual( 1, ::foolsgoldsource::IsHardware() );
		}
	};
}
