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

		TEST_METHOD(AddingToEquation)
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
	};


	TEST_CLASS(CheckFileInput)
	{
		TEST_METHOD(AddingXEquation)
		{
			std::string v = "circle.txt";
			FileInput c(v);
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

		TEST_METHOD(AddingYEquation)
		{
			FileInput c("circle.txt");
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
	};
}