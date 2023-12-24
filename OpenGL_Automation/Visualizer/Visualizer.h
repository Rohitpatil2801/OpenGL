#pragma once
#include <QtWidgets/QMainWindow>
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include <vector>
#include "Point3D.h"
#include "Bezier.h"
#include "Hermite.h"
#include "Bspline.h"
#include "Sutherland.h"
#include "Shape.h"

class OpenGLWindow;

class Visualizer : public QMainWindow {
    Q_OBJECT

public:
    Visualizer(QWindow* parent = nullptr);
    ~Visualizer();

private:
    void setupUi();

public:
    vector<float>      mVerticess;
    vector<float>      mColorss;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

private slots:
    void bezierClicked();
    void hermiteClicked();
    void bsplineClicked();
    void sutherlandClicked();

private:
    QWidget* centralWidget;
    QTabWidget* tabWidget;
    OpenGLWindow* mRenderer;

    QWidget* tab1;

    QLabel* mlabelX;
    QLabel* mlabelY;
    QLabel* mlabelZ;

    QLabel* mlabelX1;
    QLabel* mlabelY1;
    QLabel* mlabelZ1;

    QLabel* mlabelX2;
    QLabel* mlabelY2;
    QLabel* mlabelZ2;

    QLabel* mlabelX3;
    QLabel* mlabelY3;
    QLabel* mlabelZ3;

    QLabel* mlabelX4;
    QLabel* mlabelY4;
    QLabel* mlabelZ4;

    QDoubleSpinBox* mdoubleSpinBoxX;
    QDoubleSpinBox* mdoubleSpinBoxY;
    QDoubleSpinBox* mdoubleSpinBoxZ;

    QDoubleSpinBox* mdoubleSpinBoxX1;
    QDoubleSpinBox* mdoubleSpinBoxY1;
    QDoubleSpinBox* mdoubleSpinBoxZ1;

    QDoubleSpinBox* mdoubleSpinBoxX2;
    QDoubleSpinBox* mdoubleSpinBoxY2;
    QDoubleSpinBox* mdoubleSpinBoxZ2;

    QDoubleSpinBox* mdoubleSpinBoxX3;
    QDoubleSpinBox* mdoubleSpinBoxY3;
    QDoubleSpinBox* mdoubleSpinBoxZ3;

    QDoubleSpinBox* mdoubleSpinBoxX4;
    QDoubleSpinBox* mdoubleSpinBoxY4;
    QDoubleSpinBox* mdoubleSpinBoxZ4;

    QWidget* tab2;
  
    QPushButton* mpushButtonBezier;
    QPushButton* mpushButtonHermite;
    QPushButton* mpushButtonBSpline;

    QLabel* mlabels1;
    QLabel* mlabels2;
    QLabel* mlabels3;
    QLabel* mlabels4;
    QLabel* mlabels5;
    QLabel* mlabels6;
    QLabel* mlabels7;
    QLabel* mlabels8;
    QLabel* mlabels9;
    QLabel* mlabels10;

    QDoubleSpinBox* mdoubleSpinBoxs1;
    QDoubleSpinBox* mdoubleSpinBoxs2;
    QDoubleSpinBox* mdoubleSpinBoxs3;
    QDoubleSpinBox* mdoubleSpinBoxs4;
    QDoubleSpinBox* mdoubleSpinBoxs5;
    QDoubleSpinBox* mdoubleSpinBoxs6;
    QDoubleSpinBox* mdoubleSpinBoxs7;
    QDoubleSpinBox* mdoubleSpinBoxs8;

    QPushButton* mpushButtonSutherland;
};
