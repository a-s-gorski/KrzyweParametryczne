#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFunctions
{
	TEST_CLASS(CheckParameters)
	{
	public:
		
		TEST_METHOD(Correct_Parameters)
		{

			FSin<double> func;

			std::vector<double> parameters{ 1, 2, 3 };

			bool expected = true;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Wrong_Zero_Parameter)
		{
			FSin<double> func;

			std::vector<double> parameters{ 1, 0, 1 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Less_Parameters)
		{
			FSin<double> func;

			std::vector<double> parameters{ 1, 2 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Much_Parameters)
		{
			FSin<double> func;

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
			FCos<double> func;

			double val = 1;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos0)
		{
			FCos<double> func;

			double val = 0;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCosPi)
		{
			FCos<double> func;

			double val = 3.14;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_1_2_2)
		{
			FCos<double> func;

			double val = 1;

			std::vector<double> parameters{ 1, 2, 2};

			func.setParameters(parameters);

			double expected = pow(cos(val*2), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_1_2)
		{
			FCos<double> func;

			double val = 1;

			std::vector<double> parameters{ -2, 1, 2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_n2_n2)
		{
			FCos<double> func;

			double val = 1;

			std::vector<double> parameters{ -2, -2, -2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(-2*val), -2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}



		TEST_METHOD(FSin1)
		{
			FSin<double> func;

			double val = 1;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0)
		{
			FSin<double> func;

			double val = 0;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSinPi)
		{
			FSin<double> func;

			double val = 3.14;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0_Params_n3_1_2)
		{
			FSin<double> func;

			double val = 0;

			std::vector<double> parameters{ -3, 1, 2 };

			func.setParameters(parameters);

			double expected = -3*pow(sin(val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0_Params_3_3_3)
		{
			FSin<double> func;

			double val = 0;

			std::vector<double> parameters{ 3, 3, 3 };

			func.setParameters(parameters);

			double expected = 3 * pow(sin(3*val), 3);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FMonomial1_Params_1_1_2)
		{
			FMonomial<double> func;

			std::vector<double> parameters{ 1, 1, 2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = pow((1+val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FMonomial0_Params_2_n1_n2)
		{
			FMonomial<double> func;

			std::vector<double> parameters{ 2, -1, -2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 2*pow((-1 + val), -2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant1_Params_1)
		{
			FConstant<double> func;

			std::vector<double> parameters{ 1 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 1;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant1_Params_2)
		{
			FConstant<double> func;

			std::vector<double> parameters{ 2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 2;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant2_Params_2)
		{
			FConstant<double> func;

			std::vector<double> parameters{ 2 };

			func.setParameters(parameters);

			double val = 2;

			double expected = 2;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}
	};
}
