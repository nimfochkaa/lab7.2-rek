#include "pch.h"
#include "CppUnitTest.h"
#include "../7.2 рек/7.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace My72
{
	TEST_CLASS(My72)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			int row[] = { 3, 10, 7, 15 };

			int* a[] = { row };

			int max = MaxInRow(a, n, 0, 0, a[0][0]);

			Assert::AreEqual(15, max, L"Incorrect maximum in row");
		}
	};
}
