#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
#include <utility>
#include "..\ParametricCurves\DrawingPlot.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestOutput
{
	TEST_CLASS(CheckDrawingPlot) {
public:
	TEST_METHOD(CheckCanvasRange) {
		//Frame *test_frame = new Frame;
		//double test_height = test_frame.getHeight();
		//double test_width = test_frame.getWidth();
		double test_height = 500.0;
		double test_width = 700.0;


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
			if (test_plot.getCurrentCoordinates(i, 0) > test_width || test_plot.getCurrentCoordinates(i, 1) > test_height) {
				actual = false;
			}

			Assert::AreEqual(expected, actual);


		}
	}
	};

}