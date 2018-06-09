#include "stdafx.h"
#include "CppUnitTest.h"
#include <iostream>
#include "../test/test.h"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(should_return_error_when_booking_court_not_support)
		{
			//string  str3 = "user1 2016-09-08 16:00~20:00 A";
			//string str2 = "ABCD";
			//info test1;
			//SplitString(str3, test1, " ");
			//Assert::IsTrue(str2.find(test1.Court)== string::npos);//场地不合法

		}
		
	};
}