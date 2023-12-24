#include "stdafx.h"
#include "Visualizer.h"
#include "OpenGLWindow.h"
#include "Line.h"

Visualizer::Visualizer(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();
    connect(mpushButtonBezier, &QPushButton::clicked, this, &Visualizer::bezierClicked);
    connect(mpushButtonHermite, &QPushButton::clicked, this, &Visualizer::hermiteClicked);
    connect(mpushButtonBSpline, &QPushButton::clicked, this, &Visualizer::bsplineClicked);
    connect(mpushButtonSutherland, &QPushButton::clicked, this, &Visualizer::sutherlandClicked);

}

Visualizer::~Visualizer()
{}

void Visualizer::setupUi() {
    resize(800, 600);

    centralWidget = new QWidget(this);
    centralWidget->setObjectName("centralWidget");

    tabWidget = new QTabWidget(this);
    tabWidget->setObjectName("tabWidget");
    tabWidget->setGeometry(QRect(10, 10, 1500, 750));

    tab1 = new QWidget();
    tab1->setObjectName("tab");
    tabWidget->addTab(tab1, "Curves");

    //-----------------------------------------------------------------------------------------------
    mlabelX = new QLabel(tab1);
    mlabelX->setObjectName("mlabelX");
    mlabelX->setText("X :");
    mlabelX->setGeometry(QRect(100, 10, 150, 50));

    mdoubleSpinBoxX = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxX->setObjectName("mdoubleSpinBoxX");
    mdoubleSpinBoxX->setGeometry(QRect(150, 20, 70, 25));
    mdoubleSpinBoxX->setMinimum(-100.000000000000000);

    mlabelY = new QLabel(tab1);
    mlabelY->setObjectName("mlabelY");
    mlabelY->setText("Y :");
    mlabelY->setGeometry(QRect(300, 10, 150, 50));

    mdoubleSpinBoxY = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxY->setObjectName("mdoubleSpinBoxY");
    mdoubleSpinBoxY->setGeometry(QRect(350, 20, 70, 25));
    mdoubleSpinBoxY->setMinimum(-100.000000000000000);

    mlabelZ = new QLabel(tab1);
    mlabelZ->setObjectName("mlabelZ");
    mlabelZ->setText("Z :");
    mlabelZ->setGeometry(QRect(500, 10, 150, 50));

    mdoubleSpinBoxZ = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxZ->setObjectName("mdoubleSpinBoxZ");
    mdoubleSpinBoxZ->setGeometry(QRect(550, 20, 70, 25));
    mdoubleSpinBoxZ->setMinimum(-100.000000000000000);
    //-----------------------------------------------------------------------------------------------------------------

    mlabelX1 = new QLabel(tab1);
    mlabelX1->setObjectName("mlabelX1");
    mlabelX1->setText("X1 :");
    mlabelX1->setGeometry(QRect(100, 60, 150, 50));

    mdoubleSpinBoxX1 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxX1->setObjectName("mdoubleSpinBoxX1");
    mdoubleSpinBoxX1->setGeometry(QRect(150, 70, 70, 25));
    mdoubleSpinBoxX1->setMinimum(-100.000000000000000);

    mlabelY1 = new QLabel(tab1);
    mlabelY1->setObjectName("mlabelY1");
    mlabelY1->setText("Y1 :");
    mlabelY1->setGeometry(QRect(300, 60, 150, 50));

    mdoubleSpinBoxY1 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxY1->setObjectName("mdoubleSpinBoxY1");
    mdoubleSpinBoxY1->setGeometry(QRect(350, 70, 70, 25));
    mdoubleSpinBoxY1->setMinimum(-100.000000000000000);

    mlabelZ1 = new QLabel(tab1);
    mlabelZ1->setObjectName("mlabelZ1");
    mlabelZ1->setText("Z1 :");
    mlabelZ1->setGeometry(QRect(500, 60, 150, 50));

    mdoubleSpinBoxZ1 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxZ1->setObjectName("mdoubleSpinBoxZ1");
    mdoubleSpinBoxZ1->setGeometry(QRect(550, 70, 70, 25));
    mdoubleSpinBoxZ1->setMinimum(-100.000000000000000);

    //----------------------------------------------------------------------------------

    mlabelX2 = new QLabel(tab1);
    mlabelX2->setObjectName("mlabelX2");
    mlabelX2->setText("X2 :");
    mlabelX2->setGeometry(QRect(100, 110, 150, 50));

    mdoubleSpinBoxX2 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxX2->setObjectName("mdoubleSpinBoxX2");
    mdoubleSpinBoxX2->setGeometry(QRect(150, 120, 70, 25));
    mdoubleSpinBoxX2->setMinimum(-100.000000000000000);

    mlabelY2 = new QLabel(tab1);
    mlabelY2->setObjectName("mlabelY2");
    mlabelY2->setText("Y2 :");
    mlabelY2->setGeometry(QRect(300, 110, 150, 50));

    mdoubleSpinBoxY2 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxY2->setObjectName("mdoubleSpinBoxY2");
    mdoubleSpinBoxY2->setGeometry(QRect(350, 120, 70, 25));
    mdoubleSpinBoxY2->setMinimum(-100.000000000000000);

    mlabelZ2 = new QLabel(tab1);
    mlabelZ2->setObjectName("mlabelZ2");
    mlabelZ2->setText("Z2 :");
    mlabelZ2->setGeometry(QRect(500, 110, 150, 50));

    mdoubleSpinBoxZ2 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxZ2->setObjectName("mdoubleSpinBoxZ2");
    mdoubleSpinBoxZ2->setGeometry(QRect(550, 120, 70, 25));
    mdoubleSpinBoxZ2->setMinimum(-100.000000000000000);


    //-------------------------------------------------------------------------------


    mlabelX3 = new QLabel(tab1);
    mlabelX3->setObjectName("mlabelX3");
    mlabelX3->setText("X3 :");
    mlabelX3->setGeometry(QRect(100, 160, 150, 50));

    mdoubleSpinBoxX3 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxX3->setObjectName("mdoubleSpinBoxX3");
    mdoubleSpinBoxX3->setGeometry(QRect(150, 170, 70, 25));
    mdoubleSpinBoxX3->setMinimum(-100.000000000000000);

    mlabelY3 = new QLabel(tab1);
    mlabelY3->setObjectName("mlabelY3");
    mlabelY3->setText("Y3 :");
    mlabelY3->setGeometry(QRect(300, 160, 150, 50));

    mdoubleSpinBoxY3 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxY3->setObjectName("mdoubleSpinBoxY3");
    mdoubleSpinBoxY3->setGeometry(QRect(350, 170, 70, 25));
    mdoubleSpinBoxY3->setMinimum(-100.000000000000000);

    mlabelZ3 = new QLabel(tab1);
    mlabelZ3->setObjectName("mlabelZ3");
    mlabelZ3->setText("Z3 :");
    mlabelZ3->setGeometry(QRect(500, 160, 150, 50));

    mdoubleSpinBoxZ3 = new QDoubleSpinBox(tab1);
    mdoubleSpinBoxZ3->setObjectName("mdoubleSpinBoxZ3");
    mdoubleSpinBoxZ3->setGeometry(QRect(550, 170, 70, 25));
    mdoubleSpinBoxZ3->setMinimum(-100.000000000000000);

    //--------------------------------------------------------------------------

    mpushButtonBezier = new QPushButton(tab1);
    mpushButtonBezier->setObjectName("mpushButtonBezier");
    mpushButtonBezier->setText("Bezier");
    mpushButtonBezier->setGeometry(QRect(710, 20, 80, 25));

    mpushButtonHermite = new QPushButton(tab1);
    mpushButtonHermite->setObjectName("mpushButtonHermite");
    mpushButtonHermite->setText("Hermite");
    mpushButtonHermite->setGeometry(QRect(710, 70, 80, 25));

    mpushButtonBSpline = new QPushButton(tab1);
    mpushButtonBSpline->setObjectName("mpushButtonBSpline");
    mpushButtonBSpline->setText("BSpline");
    mpushButtonBSpline->setGeometry(QRect(710, 120, 80, 25));


    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(100, 300, 600, 375));
    setWindowTitle(QCoreApplication::translate("Bezier_Curve", "Bezier_Curve", nullptr));

//--------------------------------------------------------------Sutherland---------------------------------------------

    tab2 = new QWidget();
    tab2->setObjectName("tab_2");
    tabWidget->addTab(tab2, "Sutherland");

    //---------------------------------------------------------
    mlabels1 = new QLabel(tab2);
    mlabels1->setObjectName("mlabels1");
    mlabels1->setText("Clipping Region :");
    mlabels1->setGeometry(QRect(10, 10, 150, 50));

    //---------------------------------------------------------
    mlabels2 = new QLabel(tab2);
    mlabels2->setObjectName("Min_X");
    mlabels2->setText("Min X:");
    mlabels2->setGeometry(QRect(150, 10, 150, 50));

    mdoubleSpinBoxs1 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs1->setObjectName("mdoubleSpinBox1");
    mdoubleSpinBoxs1->setGeometry(QRect(200, 20, 70, 25));
    mdoubleSpinBoxs1->setMinimum(-100.000000000000000);
    //---------------------------------------------------------
    mlabels3 = new QLabel(tab2);
    mlabels3->setObjectName("Min_Y");
    mlabels3->setText("Min Y:");
    mlabels3->setGeometry(QRect(300, 10, 150, 50));

    mdoubleSpinBoxs2 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs2->setObjectName("mdoubleSpinBox2");
    mdoubleSpinBoxs2->setGeometry(QRect(350, 20, 70, 25));
    mdoubleSpinBoxs2->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mlabels4 = new QLabel(tab2);
    mlabels4->setObjectName("Max_X");
    mlabels4->setText("Max X:");
    mlabels4->setGeometry(QRect(450, 10, 150, 50));

    mdoubleSpinBoxs3 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs3->setObjectName("mdoubleSpinBox3");
    mdoubleSpinBoxs3->setGeometry(QRect(500, 20, 70, 25));
    mdoubleSpinBoxs3->setMinimum(-100.000000000000000);
    //---------------------------------------------------------

    mlabels5 = new QLabel(tab2);
    mlabels5->setObjectName("Max_Y");
    mlabels5->setText("Max Y:");
    mlabels5->setGeometry(QRect(600, 10, 150, 50));

    mdoubleSpinBoxs4 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs4->setObjectName("mdoubleSpinBox4");
    mdoubleSpinBoxs4->setGeometry(QRect(660, 20, 70, 25));
    mdoubleSpinBoxs4->setMinimum(-100.000000000000000);

    //---------------------------------------------------------------------------------------------
    mlabels6 = new QLabel(tab2);
    mlabels6->setObjectName("mlabel6");
    mlabels6->setText("Line :");
    mlabels6->setGeometry(QRect(10, 60, 150, 50));

    //---------------------------------------------------------
    mlabels7 = new QLabel(tab2);
    mlabels7->setObjectName("Start_X");
    mlabels7->setText("Start_X:");
    mlabels7->setGeometry(QRect(150, 60, 150, 50));

    mdoubleSpinBoxs5 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs5->setObjectName("mdoubleSpinBox5");
    mdoubleSpinBoxs5->setGeometry(QRect(200, 70, 70, 25));
    mdoubleSpinBoxs5->setMinimum(-100.000000000000000);
    //---------------------------------------------------------
    mlabels8 = new QLabel(tab2);
    mlabels8->setObjectName("Start_Y");
    mlabels8->setText("Start_Y:");
    mlabels8->setGeometry(QRect(300, 60, 150, 50));

    mdoubleSpinBoxs6 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs6->setObjectName("mdoubleSpinBox6");
    mdoubleSpinBoxs6->setGeometry(QRect(350, 70, 70, 25));
    mdoubleSpinBoxs6->setMinimum(-100.000000000000000);

    //---------------------------------------------------------

    mlabels9 = new QLabel(tab2);
    mlabels9->setObjectName("End_X");
    mlabels9->setText("End_X:");
    mlabels9->setGeometry(QRect(450, 60, 150, 50));

    mdoubleSpinBoxs7 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs7->setObjectName("mdoubleSpinBox7");
    mdoubleSpinBoxs7->setGeometry(QRect(500, 70, 70, 25));
    mdoubleSpinBoxs7->setMinimum(-100.000000000000000);
    //---------------------------------------------------------

    mlabels10 = new QLabel(tab2);
    mlabels10->setObjectName("End_Y");
    mlabels10->setText("End_Y:");
    mlabels10->setGeometry(QRect(600, 60, 150, 50));

    mdoubleSpinBoxs8 = new QDoubleSpinBox(tab2);
    mdoubleSpinBoxs8->setObjectName("mdoubleSpinBox8");
    mdoubleSpinBoxs8->setGeometry(QRect(660, 70, 70, 25));
    mdoubleSpinBoxs8->setMinimum(-100.000000000000000);

    //-------------------------------------------------------------

    mpushButtonSutherland = new QPushButton(tab2);
    mpushButtonSutherland->setObjectName("mpushButton");
    mpushButtonSutherland->setText("Clip");
    mpushButtonSutherland->setGeometry(QRect(320, 120, 100, 25));

    setCentralWidget(centralWidget);
}




void Visualizer::bezierClicked()
{
    double x0Coordinate = mdoubleSpinBoxX->value();
    double y0Coordinate = mdoubleSpinBoxY->value();
    double z0Coordinate = mdoubleSpinBoxZ->value();

    double x1Coordinate = mdoubleSpinBoxX1->value();
    double y1Coordinate = mdoubleSpinBoxY1->value();
    double z1Coordinate = mdoubleSpinBoxZ1->value();

    double x2Coordinate = mdoubleSpinBoxX2->value();
    double y2Coordinate = mdoubleSpinBoxY2->value();
    double z2Coordinate = mdoubleSpinBoxZ2->value();

    double x3Coordinate = mdoubleSpinBoxX3->value();
    double y3Coordinate = mdoubleSpinBoxY3->value();
    double z3Coordinate = mdoubleSpinBoxZ3->value();

    Point3D p0 = Point3D(x0Coordinate, y0Coordinate, z0Coordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

     Bezier bezier(p0, p1, p2, p3);
    bezier.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    mVertices << x0Coordinate << y0Coordinate << z0Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mVertices << x3Coordinate << y3Coordinate << z3Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}



void Visualizer::hermiteClicked()
{
    double x0Coordinate = mdoubleSpinBoxX->value();
    double y0Coordinate = mdoubleSpinBoxY->value();
    double z0Coordinate = mdoubleSpinBoxZ->value();

    double x1Coordinate = mdoubleSpinBoxX1->value();
    double y1Coordinate = mdoubleSpinBoxY1->value();
    double z1Coordinate = mdoubleSpinBoxZ1->value();

    double x2Coordinate = mdoubleSpinBoxX2->value();
    double y2Coordinate = mdoubleSpinBoxY2->value();
    double z2Coordinate = mdoubleSpinBoxZ2->value();

    double x3Coordinate = mdoubleSpinBoxX3->value();
    double y3Coordinate = mdoubleSpinBoxY3->value();
    double z3Coordinate = mdoubleSpinBoxZ3->value();

    Point3D p0 = Point3D(x0Coordinate, y0Coordinate, z0Coordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

    Hermite hermite(p0, p1, p2, p3);
    hermite.drawCurve(p0, p1, p2, p3, mVerticess, mColorss);

    mVertices << x0Coordinate << y0Coordinate << z0Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    mVertices << x3Coordinate << y3Coordinate << z3Coordinate;
    mColors << 0.0f << 1.0f << 0.0f;

    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}


void Visualizer::bsplineClicked()
{
    double x0Coordinate = mdoubleSpinBoxX->value();
    double y0Coordinate = mdoubleSpinBoxY->value();
    double z0Coordinate = mdoubleSpinBoxZ->value();

    double x1Coordinate = mdoubleSpinBoxX1->value();
    double y1Coordinate = mdoubleSpinBoxY1->value();
    double z1Coordinate = mdoubleSpinBoxZ1->value();

    double x2Coordinate = mdoubleSpinBoxX2->value();
    double y2Coordinate = mdoubleSpinBoxY2->value();
    double z2Coordinate = mdoubleSpinBoxZ2->value();

    double x3Coordinate = mdoubleSpinBoxX3->value();
    double y3Coordinate = mdoubleSpinBoxY3->value();
    double z3Coordinate = mdoubleSpinBoxZ3->value();

    Point3D p0 = Point3D(x0Coordinate, y0Coordinate, z0Coordinate);
    Point3D p1 = Point3D(x1Coordinate, y1Coordinate, z1Coordinate);
    Point3D p2 = Point3D(x2Coordinate, y2Coordinate, z2Coordinate);
    Point3D p3 = Point3D(x3Coordinate, y3Coordinate, z3Coordinate);

    BSpline bSpline(p0, p1, p2, p3);
    bSpline.drawCurveBspline(mVerticess, mColorss);

    for (int i = 0; i < mVerticess.size(); i += 3)
    {
        mVertices << mVerticess[i] << mVerticess[i + 1] << mVerticess[i + 2];
    }
    for (int i = 0; i < mColorss.size(); i += 3)
    {
        mColors << mColorss[i] << mColorss[i + 1] << mColorss[i + 2];
    }

    int flag = 1;
    mRenderer->updateData(mVertices, mColors, flag);
    mColorss.clear();
    mVerticess.clear();
    mVertices.clear();
    mColors.clear();
}


void Visualizer::sutherlandClicked()
{
    double minX = mdoubleSpinBoxs1->value();
    double minY = mdoubleSpinBoxs2->value();
    double maxX = mdoubleSpinBoxs3->value();
    double maxY = mdoubleSpinBoxs4->value();

    double startX = mdoubleSpinBoxs5->value();
    double startY = mdoubleSpinBoxs6->value();
    double endX = mdoubleSpinBoxs7->value();
    double endY = mdoubleSpinBoxs8->value();

    Point3D startPoint(startX, startY);
    Point3D endPoint(endX, endY);
    Line inputLine(startPoint, endPoint);

    Point3D minPoint = Point3D(minX, minY);
    Point3D maxPoint = Point3D(maxX, maxY);
    Shape rectangle = Shape(minPoint, maxPoint);
    std::vector<Line> sides = rectangle.getShape();

    //----------------------------------------------------------------------

    double xMin = sides.at(0).getStart().x();
    double yMin = sides.at(0).getStart().y();
    double xMax = sides.at(2).getStart().x();
    double yMax = sides.at(2).getStart().y();

    mVertices << xMin << yMin;
    mVertices << xMax << yMin;

    mVertices << xMax << yMin;
    mVertices << xMax << yMax;

    mVertices << xMax << yMax;
    mVertices << xMin << yMax;

    mVertices << xMin << yMax;
    mVertices << xMin << yMin;

    mColors << 0.0f << 0.0f << 1.0f;
    mColors << 0.0f << 0.0f << 1.0f;

    mColors << 0.0f << 0.0f << 1.0f;
    mColors << 0.0f << 0.0f << 1.0f;

    mColors << 0.0f << 0.0f << 1.0f;
    mColors << 0.0f << 0.0f << 1.0f;

    mColors << 0.0f << 0.0f << 1.0f;
    mColors << 0.0f << 0.0f << 1.0f;

    //----------------------------------------------------------------------

    Line clippedLine = Sutherland::clip(inputLine, sides);

    double x1 = clippedLine.getStart().x();
    double y1 = clippedLine.getStart().y();
    double x2 = clippedLine.getEnd().x();
    double y2 = clippedLine.getEnd().y();

    mVertices << x1 << y1;
    mVertices << x2 << y2;

    mColors << 1.0f << 0.0f << 1.0f;
    mColors << 1.0f << 0.0f << 1.0f;

    //----------------------------------------------------------------------

    mRenderer->setVectorOfLines(mVertices);
    mRenderer->setColorOfLines(mColors);

    mRenderer->updateData(mVertices, mColors, 0);
    mColors.clear();
    mVertices.clear();
    mVertices.clear();
    mColors.clear();
}

