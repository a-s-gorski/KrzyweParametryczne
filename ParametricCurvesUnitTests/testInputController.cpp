#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInputController
{
	double pi = 3.14159265359;
	TEST_CLASS(CheckEquation)
	{
	public:

		TEST_METHOD(AddingToEquation)
		{
			Equation eq;
			FSin<double> s;

			vector<double> parameters{ 1, 1, 1 };
			s.setParameters(parameters);
			s.setOperation('+');

			Function<double>* ps = &s;

			eq += ps;

			const std::vector<Function<double>*> vec = eq.getEquation();

			double expected = s.calculateValue(0.5 * pi);
			double actual = vec[0]->calculateValue(0.5 * pi);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AddingMoreToEquation)
		{
			Equation eq;
			FSin<double> s;
			FMonomial<double> c;

			vector<double> parameters1{ 1, 1, 1 };
			s.setParameters(parameters1);
			s.setOperation('+');

			vector<double> parameters2{ 3, 1, 1 };
			s.setParameters(parameters2);
			s.setOperation('-');

			Function<double>* ps = &s;
			Function<double>* pc = &c;

			eq += ps;
			eq += pc;

			const std::vector<Function<double>*> vec = eq.getEquation();

			double expected = c.calculateValue(pi);
			double actual = vec[1]->calculateValue(pi);

			Assert::AreEqual(expected, actual);
		}
	};
}