
#include "pch.h"
#include "CppUnitTest.h"
#include <cmath>
#include <vector>
#include <utility>
#include "..\ParametricCurves\DrawingPlot.h"
#include "..\ParametricCurves\Frame.h"
#include "..\ParametricCurves\Frame.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestOutput
{
	TEST_CLASS(CheckDrawingPlot) {
public:
	TEST_METHOD(CheckCanvasRange) {
		//Frame *test_frame = new Frame;
		//double test_height = test_frame.getHeight();
		//double test_width = test_frame.getWidth();
		double test_height = 5000.0;
		double test_width = 7000.0;


		DrawingPlot <double, double> test_plot;
		pair <double, double> test_pair;
		vector <pair <double, double>> test_vector;

		for (int i = 0; i < 100; i++) {
			test_pair.first = (double)i;
			test_pair.second = (double)i * i;
			test_vector.push_back(test_pair);
		}
		test_plot.setPlot(test_vector);

	
		bool expected = true;
		bool actual = true;
		for (int i = 0; i < 1000; i++) {
			if (test_pair.first > test_width && test_pair.second > test_height && test_pair.first != test_pair.second) {
				actual = true;
			}



		}
		Assert::AreEqual(expected, actual);

	}
	};

}