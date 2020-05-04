#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCalculator
{
	TEST_CLASS(CheckOperations)
	{
	public:

		TEST_METHOD(Adding)
		{
			FSin<double> func;

			std::vector<double> parameters{ 1, 2, 3 };

			bool expected = true;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}

	};
}
