#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2(2)/lab7.2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestCreateRows)
        {
            int N = 2; 
            int Low = 1, High = 2;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N];

            CreateRows(a, N, Low, High, 0);

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    Assert::IsTrue(a[i][j] >= Low && a[i][j] <= High);
                }
            }

            for (int i = 0; i < N; i++) delete[] a[i];
            delete[] a;
        }

        TEST_METHOD(TestSortRec)
        {
            int N = 3;
            int** a = new int* [N];
            for (int i = 0; i < N; i++)
                a[i] = new int[N] { 0 }; 
            a[0][2] = 9;
            a[1][1] = 5;
            a[2][0] = 1;

            SortRec(a, N);

            Assert::AreEqual(9, a[0][2]);
            Assert::AreEqual(5, a[1][1]);
            Assert::AreEqual(1, a[2][0]);

            for (int i = 0; i < N; i++) delete[] a[i];
            delete[] a;
        }
	};
}