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

			std::vector<double> parameters{ 1,2,3 };

			bool expected = true;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}
	};
}
