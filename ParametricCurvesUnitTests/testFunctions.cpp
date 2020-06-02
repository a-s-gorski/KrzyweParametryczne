//Łukasz Bondaruk

#include "pch.h"
#include "CppUnitTest.h"
#include "..\ParametricCurves\Functions.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestFunctions
{
	TEST_CLASS(CheckParameters)
	{
	public:
		
		TEST_METHOD(Correct_Parameters)
		{

			FSin<> func;

			std::vector<double> parameters{ 1, 2, 3 };

			bool expected = true;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Wrong_Zero_Parameter)
		{
			FSin<> func;

			std::vector<double> parameters{ 1, 0, 1 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Less_Parameters)
		{
			FSin<> func;

			std::vector<double> parameters{ 1, 2 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(Too_Much_Parameters)
		{
			FSin<> func;

			std::vector<double> parameters{ 1, 2, 3, 4 };

			bool expected = false;

			bool actual = func.checkParameters(parameters);

			Assert::AreEqual(expected, actual);
		}


	};

	TEST_CLASS(Constructors)
	{
	public:
		TEST_METHOD(Default)
		{
			FCos<> f1;
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = true;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Operation)
		{
			FCos<> f1({ 1, 1, 1 }, '+');
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = true;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(Parameters)
		{
			FCos<> f1({ 1, 1, 1 });
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = true;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(DifferentOperation)
		{
			FCos<> f1({ 1, 1, 1 }, '-');
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = false;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(DifferentParameters)
		{
			FCos<> f1({ 1, 2, 1 });
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = false;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(CosSin)
		{
			FCos<double> f1;
			FSin<double> f2;

			bool actual = (f1 == f2);

			bool expected = false;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(SinCos)
		{
			FSin<double> f1;
			FCos<double> f2;

			bool actual = (f1 == f2);

			bool expected = false;

			Assert::AreEqual(expected, actual);
		}
	};


	TEST_CLASS(CalculateValue)
	{
	public:

		TEST_METHOD(FCos1)
		{
			FCos<> func;

			double val = 1;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos0)
		{
			FCos<> func;

			double val = 0;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCosPi)
		{
			FCos<> func;

			double val = 3.14;

			double expected = cos(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_1_2_2)
		{
			FCos<> func;

			double val = 1;

			std::vector<double> parameters{ 1, 2, 2};

			func.setParameters(parameters);

			double expected = pow(cos(val*2), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_1_2)
		{
			FCos<> func;

			double val = 1;

			std::vector<double> parameters{ -2, 1, 2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FCos1_Params_n2_n2_n2)
		{
			FCos<> func;

			double val = 1;

			std::vector<double> parameters{ -2, -2, -2 };

			func.setParameters(parameters);

			double expected = -2*pow(cos(-2*val), -2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}



		TEST_METHOD(FSin1)
		{
			FSin<> func;

			double val = 1;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0)
		{
			FSin<> func;

			double val = 0;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSinPi)
		{
			FSin<> func;

			double val = 3.14;

			double expected = sin(val);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0_Params_n3_1_2)
		{
			FSin<> func;

			double val = 0;

			std::vector<double> parameters{ -3, 1, 2 };

			func.setParameters(parameters);

			double expected = -3*pow(sin(val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FSin0_Params_3_3_3)
		{
			FSin<> func;

			double val = 0;

			std::vector<double> parameters{ 3, 3, 3 };

			func.setParameters(parameters);

			double expected = 3 * pow(sin(3*val), 3);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FMonomial1_Params_1_1_2)
		{
			FMonomial<> func;

			std::vector<double> parameters{ 1, 1, 2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = pow((1+val), 2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FMonomial0_Params_2_n1_n2)
		{
			FMonomial<> func;

			std::vector<double> parameters{ 2, -1, -2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 2*pow((-1 + val), -2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant1_Params_1)
		{
			FConstant<> func;

			std::vector<double> parameters{ 1 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 1;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant1_Params_2)
		{
			FConstant<> func;

			std::vector<double> parameters{ 2 };

			func.setParameters(parameters);

			double val = 1;

			double expected = 2;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FConstant2_Params_2)
		{
			FConstant<> func;

			std::vector<double> parameters{ 2 };

			func.setParameters(parameters);

			double val = 2;

			double expected = 2;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(FExpDefault)
		{
			FExp<> func;

			double val = 1;

			double expected = 2.7183;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(FExpDefault2)
		{
			FExp<> func;

			double val = 2;

			double expected = 7.38915489;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(FExp_Params_2_2)
		{
			FExp<> func({ 2, 2 });

			double val = 2;

			double expected = 8;

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual, 0.0001);
		}

		TEST_METHOD(FLogDefault)
		{
			FLog<> func;

			double val = 2;

			double expected = log(2)/log(2.7183);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(FLog_Params_2)
		{
			FLog<> func({ 2 });

			double val = 2;

			double expected = log(2) / log(2);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(FLog_Params_10)
		{
			FLog<> func({ 10 });

			double val = 2;

			double expected = log(2) / log(10);

			double actual = func.calculateValue(val);

			Assert::AreEqual(expected, actual);
		}
	};
}
