#pragma once

//	Author : Adam G�rski 


#include <QtWidgets/QMainWindow>
#include "ui_OutputController.h"

class OutputController : public QMainWindow
{
	Q_OBJECT

public:
	OutputController(QWidget *parent = Q_NULLPTR);

private:
	Ui::OutputControllerClass ui;
};
