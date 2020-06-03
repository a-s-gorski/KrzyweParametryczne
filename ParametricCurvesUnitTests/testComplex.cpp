#include "pch.h"
#include "CppUnitTest.h"
#include "..\ParametricCurves\ComplexNumber.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestComplex
{
	TEST_CLASS(CheckConstructors)
	{
	public:

		TEST_METHOD(Default)
		{
			Complex c;

			double expected = 0;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 0;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Re)
		{
			Complex c(2);

			double expected = 2;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 0;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Im)
		{
			Complex c(0, 1);

			double expected = 0;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 1;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(ReIm)
		{
			Complex c(2, 3);

			double expected = 2;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Copy)
		{
			Complex t(2, 3);
			Complex c(t);

			double expected = 2;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(EqualComplex)
		{
			Complex t(2, 3);
			Complex c = t;

			double expected = 2;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(EqualDouble)
		{
			double t = 5;
			Complex c = t;

			double expected = 5;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 0;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

	};

	TEST_CLASS(checkOperationsComplex)
	{
		TEST_METHOD(Adding)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			double expected = 7;
			double actual = (t+c).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 10;
			actual = (t + c).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Substracting)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			double expected = -3;
			double actual = (t - c).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = -4;
			actual = (t - c).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Multiplying)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			double expected = -11;
			double actual = (t * c).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 29;
			actual = (t * c).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Dividing)
		{
			Complex t(2, 4);
			Complex c(6, 8);

			double expected = double(11) / 25;
			double actual = (t / c).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = double(2) / 25;
			actual = (t / c).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}
	};

	TEST_CLASS(checkOperationsDouble)
	{
		TEST_METHOD(Adding)
		{
			double t = 3;
			Complex c(5, 7);

			double expected = 8;
			double actual = (c + t).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 7;
			actual = (c + t).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Substracting)
		{
			double t = 3;
			Complex c(5, 7);

			double expected = 2;
			double actual = (c - t).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 7;
			actual = (c - t).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Multiplying)
		{
			double t = 3;
			Complex c(5, 7);

			double expected = 15;
			double actual = (c * t).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 21;
			actual = (c * t).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Dividing)
		{
			double t = 3;
			Complex c(6, 8);

			double expected = 2;
			double actual = (c / t).getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = double(8) / 3;
			actual = (c / t).getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}
	};

	TEST_CLASS(checkEqualsOperationsComplex)
	{
		TEST_METHOD(Adding)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			t += c;

			double expected = 7;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 10;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Substracting)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			t -= c;

			double expected = -3;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = -4;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Multiplying)
		{
			Complex t(2, 3);
			Complex c(5, 7);

			c *= t;

			double expected = -11;
			double actual = c.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 29;
			actual = c.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Dividing)
		{
			Complex t(2, 4);
			Complex c(6, 8);

			t /= c;

			double expected = double(11) / 25;
			double actual = t.getRe();

			Assert::AreEqual(expected, actual);

			expected = double(2) / 25;
			actual = t.getIm();

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(checkEqualsOperationsDouble)
	{
		TEST_METHOD(Adding)
		{
			Complex t(2, 3);
			double c = 3;

			t += c;

			double expected = 5;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Substracting)
		{
			Complex t(2, 3);
			double c = 3;

			t -= c;

			double expected = -1;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Multiplying)
		{
			Complex t(2, 3);
			double c = 3;

			t *= c;

			double expected = 6;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 9;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Dividing)
		{
			Complex t(2, 4);
			double c = 3;

			t /= c;

			double expected = double(2) / 3;
			double actual = t.getRe();

			Assert::AreEqual(expected, actual);

			expected = double(4) / 3;
			actual = t.getIm();

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(otherFunctions) {
		TEST_METHOD(Reflection1)
		{
			Complex c(2, 5);
			Complex t = c.reflect();

			double expected = 2;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = -5;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(Reflection2)
		{
			Complex c(1, -3.5);
			Complex t = c.reflect();

			double expected = 1;
			double actual = t.getRe();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);

			expected = 3.5;
			actual = t.getIm();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(CalculateR1)
		{
			Complex c(3, 4);

			double expected = 5;
			double actual = c.getAbsoluteValue();

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CalculateR2)
		{
			Complex c(3, -4);

			double expected = 5;
			double actual = c.getAbsoluteValue();

			Assert::AreEqual(true, abs(expected - actual) < 1e-9);
		}

		TEST_METHOD(CalculatePhi1)
		{
			Complex c(0, 1);

			double expected = 1.5708;
			double actual = c.getPhi();

			Assert::AreEqual(true, abs(expected - actual) < 1e-4);
		}

		TEST_METHOD(CalculatePhi2)
		{
			Complex c(3, -4);

			double expected = -0.927295;
			double actual = c.getPhi();

			Assert::AreEqual(true, abs(expected - actual) < 1e-4);
		}
	};
}
