#include "pch.h"
#include "CppUnitTest.h"
#include "..\ParametricCurves\Calculator.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestCalculator
{
	TEST_CLASS(CheckOperations)
	{
	public:

		TEST_METHOD(Adding)
		{
			double val = 1;

			FSin<double> *f1 = new FSin<double>;
			FCos<double> *f2 = new FCos<double>;

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);

			Calculator calc;

			double expected = (*f1)(val) + (*f2)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

	};
}
