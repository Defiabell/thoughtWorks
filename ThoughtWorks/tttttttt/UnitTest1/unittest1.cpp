#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "../tttttttt/thought.h"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(court_wrong)
		{
			string  str3 = "user1 2016-09-08 16:00~20:00 A";
			string str2 = "ABCD";
			info test1;
			SplitString(str3, test1, " ");
			bool t = str2.find(test1.Court) == string::npos;
			Assert::IsTrue(str2.find(test1.Court)!= string::npos);//场地不合法
		}
		TEST_METHOD(data_wrong)
		{
			string  str3 = "user1 2016-13-08 16:00~20:00 A";
			
			info test1;
			SplitString(str3, test1, " ");
			int date = DateLegal(test1.Date);
			Assert::IsTrue(date!=0);//时间不合法
		}
		TEST_METHOD(time_wrong)
		{
			string  str3 = "user1 2016-12-08 16:00~20:00 A";

			info test1;
			SplitString(str3, test1, " ");
			int date = DateLegal(test1.Date);
			Assert::IsTrue(date != 0);//时间不合法
		}
	};
}