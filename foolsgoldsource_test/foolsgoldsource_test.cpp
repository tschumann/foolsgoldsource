#include "pch.h"
#include "CppUnitTest.h"

#include "../foolsgoldsource.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace foolsgoldsourcetest
{
	TEST_CLASS(foolsgoldsource)
	{
	public:
		
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
