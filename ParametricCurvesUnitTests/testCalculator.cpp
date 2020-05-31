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

			FSin<> *f1 = new FSin<double>;
			FCos<> *f2 = new FCos<double>;

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);

			Calculator calc;

			double expected = (*f1)(val) + (*f2)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Substracting)
		{
			double val = 1;

			FSin<>* f1 = new FSin<double>;
			FCos<>* f2 = new FCos<double>('-');

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);

			Calculator calc;

			double expected = (*f1)(val) - (*f2)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Multiplaying)
		{
			double val = 1;

			FSin<>* f1 = new FSin<double>;
			FCos<>* f2 = new FCos<double>('*');

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);

			Calculator calc;

			double expected = (*f1)(val) * (*f2)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Dividing)
		{
			double val = 1;

			FSin<>* f1 = new FSin<double>;
			FCos<>* f2 = new FCos<double>('/');

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);

			Calculator calc;

			double expected = (*f1)(val) / (*f2)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Order112)
		{
			double val = 1;

			FSin<>* f1 = new FSin<double>('+');
			FCos<>* f2 = new FCos<double>('+');
			FCos<>* f3 = new FCos<double>('*');

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);
			functions.push_back(f3);

			Calculator calc;

			double expected = (*f1)(val) + (*f2)(val) * (*f3)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Order121)
		{
			double val = 1;

			FSin<>* f1 = new FSin<double>('+');
			FCos<>* f2 = new FCos<double>('*');
			FCos<>* f3 = new FCos<double>('+');

			std::vector<Function<double>*> functions;

			functions.push_back(f1);
			functions.push_back(f2);
			functions.push_back(f3);

			Calculator calc;

			double expected = (*f1)(val) * (*f2)(val) + (*f3)(val);

			double actual = calc.calculateSingiel(&functions, val);

			Assert::AreEqual(expected, actual);
		}

	};
}
