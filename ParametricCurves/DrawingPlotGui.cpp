#include "DrawingPlotGui.h"



//	Author : Adam Górski 



template <class X, class Y>
void DrawingPlotGui<X, Y>::setPicture(QPicture picture_base) {
	DrawingPlotGui::drawingPanel = picture_base;
}

template<class X, class Y>
void DrawingPlotGui<X, Y>::drawPlot() {
	QPicture drawingCanvas = DrawingPlotGui::drawingPanel;
	QPainter painting_canvas(&drawingCanvas);
	painting_canvas.setRenderHint(QPainter::Antialiasing);

	try {
		X x1_test = DrawingPlotGui::coordinates[0][0];
		Y y1_test = DrawingPlotGui::coordinates[0][1];
		X x2_test = DrawingPlotGui::coordinates[1][0];
		Y y2_test = DrawingPlotGui::coordinates[1][1];

		if (typeid(x1_test).name() != typeid(y1_test).name()) {
			throw std::runtime_error("not the same type");
		}

	}
	catch (std::bad_alloc) {
		exit(1);
	}

		for (int i = 1; i < DrawingPlot::points.size(); i++) {
			X x1 = DrawingPlotGui::coordinates[i - 1][0];
			Y y1 = DrawingPlotGui::coordinates[i - 1][1];
			X x2 = DrawingPlotGui::coordinates[i][0];
			Y y2 = DrawingPlotGui::coordinates[i][1];

			painting_canvas.drawLine(x1, y1, x2, y2);
		}
		painting_canvas.end();
#ifdef _DEBUG
		cout << "DrawingPlot : drawing plot lines conecting coordinates \n";
#endif // _DEBUG

		for (int i = 0; i < DrawingPlotGui::points.size(); i++) {
			delete[] DrawingPlotGui::coordinates[i];
		}
		delete[] DrawingPlot::coordinates;
#ifdef _DEBUG
		cout << "DrawingPlot: destructor\n";
		cout << "DrawingPlot: deleting dynamic 2d array coordinates\n";
#endif // _DEBUG

		}
	