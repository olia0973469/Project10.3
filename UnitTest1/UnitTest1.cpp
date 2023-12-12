#include "pch.h"
#include "CppUnitTest.h"
#include "../Project10.3/Source.cpp"
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string testFileName = "test_addStudent.txt";
			Students testStudents = { "TestStudents", 2, 3, 10.5 };

			addStudent(testFileName, testStudents);

			ifstream file(testFileName);
			string line;
			bool found = false;
			while (getline(file, line)) {
				if (line.find("TestStudents") != string::npos) {
					found = true;
					break;
				}
			}
			Assert::IsTrue(found);
			file.close();
		}
	};
}
