#include "pch.h"
#include "CppUnitTest.h"
#include "..\ParametricCurves\Functions.cpp"
#include <vector>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFunctions
{
	TEST_CLASS(CheckParameters)
	{
	public:
		
		TEST_METHOD(Correct_Parameters)
		{
			FSin func;

			std::vector<double> parameters{ 1, 2, 3 };

			bool expected = true;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Wrong_Zero_Parameter)
		{
			FSin func;

			std::vector<double> parameters{ 1, 0, 1 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Less_Parameters)
		{
			FSin func;

			std::vector<double> parameters{ 1, 2 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Much_Parameters)
		{
			FSin func;

			std::vector<double> parameters{ 1, 2, 3, 4 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}
	};
}
