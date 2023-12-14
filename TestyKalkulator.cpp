#include "pch.h"
#include "CppUnitTest.h"
#include "../zad2/funkcje.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestyKalkulator
{
	TEST_CLASS(TestyKalkulator)
	{
	public:
		TEST_METHOD(TestLogarytmNaturalny)
		{
			Assert::AreEqual(0.0, logarytmNaturalny(1.0));
			Assert::IsTrue(logarytmNaturalny(10.0) > 0.0);
			Assert::IsTrue(_isnan(logarytmNaturalny(-1.0)));
		}

		TEST_METHOD(TestOdchylenieStandardowe)
		{
			Assert::AreEqual(0.0, odchylenieStandardowe(3.0, 3.0));
			Assert::IsTrue(odchylenieStandardowe(3.0, 5.0) > 0.0);
		}

		TEST_METHOD(TestWartoscExponentu)
		{
			Assert::AreEqual(1.0, wartoscExponentu(0.0));
			Assert::IsTrue(wartoscExponentu(2.0) > 0.0);
		}
		
		TEST_METHOD(TestfunkcjaProstakwadratowa)
		{
			Assert::IsTrue(funkcjaProstakwadratowa(2.0) > 0.0);
		}
	};
}
