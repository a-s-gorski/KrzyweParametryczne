#include "pch.h"
#include "CppUnitTest.h"
#include "..\ParametricCurves\InputController.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestInputController
{
	double pi = 3.14159265359;
	TEST_CLASS(CheckEquation)
	{
	public:

		TEST_METHOD(AddingToEquationSin)
		{
			Equation<Function<double>> eq;
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
			Equation<Function<double>> eq;
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
		TEST_METHOD(AddingToEquationCin)
		{
			Equation<Function<double>> eq;
			FCos<double> s;

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
		TEST_METHOD(AddingToEquationMonomial)
		{
			Equation<Function<double>> eq;
			FMonomial<double> s;

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
		TEST_METHOD(AddingToEquationConstant)
		{
			Equation<Function<double>> eq;
			FConstant<double> s;

			vector<double> parameters{6};
			s.setParameters(parameters);
			s.setOperation('+');

			Function<double>* ps = &s;

			eq += ps;

			const std::vector<Function<double>*> vec = eq.getEquation();

			double expected = s.calculateValue(0.5 * pi);
			double actual = vec[0]->calculateValue(0.5 * pi);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AddingToEquationExp)
		{
			Equation<Function<double>> eq;
			FExp<double> s;

			vector<double> parameters{ 1, 2 };
			s.setParameters(parameters);
			s.setOperation('+');

			Function<double>* ps = &s;

			eq += ps;

			const std::vector<Function<double>*> vec = eq.getEquation();

			double expected = s.calculateValue(0.5 * pi);
			double actual = vec[0]->calculateValue(0.5 * pi);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AddingToEquationLog)
		{
			Equation<Function<double>> eq;
			FSin<double> s;

			vector<double> parameters{ 2 };
			s.setParameters(parameters);
			s.setOperation('+');

			Function<double>* ps = &s;

			eq += ps;

			const std::vector<Function<double>*> vec = eq.getEquation();

			double expected = s.calculateValue(4);
			double actual = vec[0]->calculateValue(4);

			Assert::AreEqual(expected, actual);
		}
	};


	TEST_CLASS(CheckInputController)
	{

		TEST_METHOD(AddingXEquation)
		{
			CMDInput c;
			FSin<double> s;
			FMonomial<double> m;
			Equation<Function<double>> eq;

			vector<double> parameters{ 1, 1, 1 };
			s.setParameters(parameters);
			m.setParameters(parameters);
			s.setOperation('+');
			m.setOperation('+');

			eq += &s;
			eq += &m;

			c.getXEquation() = eq;

			Equation<Function<double>> x;
			vector<Function<double>*> xf;

			x = c.getXEquation();
			xf = x.getEquation();

			double expected = m.calculateValue(1);
			double actual = xf[1]->calculateValue(1);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AddYEquation)
		{
			CMDInput c;
			FSin<double> s;
			FMonomial<double> m;
			Equation<Function<double>> eq;

			vector<double> parameters{ 1, 1, 1 };
			s.setParameters(parameters);
			m.setParameters(parameters);
			s.setOperation('+');
			m.setOperation('+');

			eq += &s;
			eq += &m;

			c.getYEquation() = eq;

			Equation<Function<double>> x;
			vector<Function<double>*> xf;

			x = c.getYEquation();
			xf = x.getEquation();

			double expected = m.calculateValue(1);
			double actual = xf[1]->calculateValue(1);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AddingToXEquationLog)
		{
			CMDInput c;
			FLog<double> s;
			Equation<Function<double>> eq;

			vector<double> parameters{ 2 };
			s.setParameters(parameters);
			s.setOperation('+');

			eq += &s;

			c.getXEquation() = eq;

			Equation<Function<double>> x;
			vector<Function<double>*> xf;

			x = c.getXEquation();
			xf = x.getEquation();

			double expected = s.calculateValue(8);
			double actual = xf[0]->calculateValue(8);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(AddingToXEquationExp)
		{
			CMDInput c;
			FExp<double> s;
			Equation<Function<double>> eq;

			vector<double> parameters{ 2, 6 };
			s.setParameters(parameters);
			s.setOperation('+');

			eq += &s;

			c.getXEquation() = eq;

			Equation<Function<double>> x;
			vector<Function<double>*> xf;

			x = c.getXEquation();
			xf = x.getEquation();

			double expected = s.calculateValue(8);
			double actual = xf[0]->calculateValue(8);

			Assert::AreEqual(expected, actual);
		}
	};
}