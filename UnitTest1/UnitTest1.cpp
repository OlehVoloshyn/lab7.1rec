#include "pch.h"
#include "CppUnitTest.h"
#include "../lab7.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int t;
			const int K  = 100;
			const int N = 100;
			
			int rowNo = 0;
			int** a = new int* [K];
			for (int i = 0; i < K; i++)
				a[i] = new int[N];

			t =  minElem(a, N, rowNo, 0, a[rowNo][0]);
			Assert::AreEqual(t, a[rowNo][0]);

			
		}
	};
}
