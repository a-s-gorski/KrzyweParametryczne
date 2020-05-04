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


	TEST_CLASS(CalculateValue)
	{
	public:

		TEST_METHOD(FCos1)
		{
			FCos func;

			double val = 1;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos0)
		{
			FCos func;

			double val = 0;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCosPi)
		{
			FCos func;

			double val = 3.14;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_1_2_2)
		{
			FCos func;

			double val = 1;

			std::vector<double> parameters{ 1, 2, 2};

			func.setParameters(parameters);

			double expected = pow(cos(val*2), 2);

			double actual = func.calculateValue(1);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_1_2)
		{
			FCos func;

			double val = 1;

			std::vector<double> parameters{ -2, 1, 2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(val), 2);

			double actual = func.calculateValue(1);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_n2_n2)
		{
			FCos func;

			double val = 1;

			std::vector<double> parameters{ -2, -2, -2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(-2*val), -2);

			double actual = func.calculateValue(1);

			Assert::AreEqual(expected, actual);
		}



		TEST_METHOD(FSin1)
		{
			FSin func;

			double val = 1;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0)
		{
			FSin func;

			double val = 0;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSinPi)
		{
			FSin func;

			double val = 3.14;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}
	};
}
