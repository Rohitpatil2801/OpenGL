#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>
#include <tuple>

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background) {
    setParent(parent);
    setMinimumSize(300, 250);

    const QStringList list = { "vertexShader.glsl" , "fragmentShader.glsl" };
    mShaderWatcher = new QFileSystemWatcher(list, this);
    connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);

}

OpenGLWindow::~OpenGLWindow() {
    reset();
}

void OpenGLWindow::mouseMoveEvent(QMouseEvent* event) {
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        QQuaternion rotX = QQuaternion::fromAxisAndAngle(0.0f, 1.0f, 0.0f, 0.5f * dx);
        QQuaternion rotY = QQuaternion::fromAxisAndAngle(1.0f, 0.0f, 0.0f, 0.5f * dy);

        rotationAngle = rotX * rotY * rotationAngle;
        update();
    }
    lastPos = event->pos();
}


void OpenGLWindow::reset() {
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    QObject::disconnect(mContextWatchConnection);
}



void OpenGLWindow::setVectorOfLines(QVector<GLfloat>& vectorOfLines)
{
    verticesOfOrignalLine= vectorOfLines;
}

void OpenGLWindow::setColorOfLines(QVector<GLfloat>& colorOfLines)
{
    colorOfOrignalLine= colorOfLines;
}

void OpenGLWindow::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-30.0f, 30.0f, -30.0f, 30.0f, 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);

    GLfloat* verticesData = verticesOfOrignalLine.data();
    GLfloat* colorsData = colorOfOrignalLine.data();

    if (mFlag == 1)
    {
        glVertexAttribPointer(m_posAttr, 3, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 3);
    }
    else
    {
        glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, verticesData);
        glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, colorsData);

        glEnableVertexAttribArray(m_posAttr);
        glEnableVertexAttribArray(m_colAttr);

        glDrawArrays(GL_LINES, 0, verticesOfOrignalLine.size() / 2);
    }


}

void OpenGLWindow::updateData(const QVector<GLfloat>& vertices, const QVector<GLfloat>& colors, int  flag=0)
{
    verticesOfOrignalLine = vertices;
    colorOfOrignalLine = colors;
    mFlag = flag;
    update();  // Schedule a repaint
}



QString OpenGLWindow::readShader(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "INvaid";

    QTextStream stream(&file);
    QString line = stream.readLine();


    while (!stream.atEnd())
    {
        line.append(stream.readLine());
    }

    file.close();
    return line;
}


void OpenGLWindow::shaderWatcher()
{

    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    mProgram->release();
    mProgram->removeAllShaders();
    mProgram = new QOpenGLShaderProgram(this);

    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
}













void OpenGLWindow::initializeGL() {

    /*static const char* vertexShaderSource =
        "attribute highp vec4 posAttr;\n"
        "attribute lowp vec4 colAttr;\n"
        "varying lowp vec4 col;\n"
        "uniform highp mat4 matrix;\n"
        "void main() {\n"
        "   col = colAttr;\n"
        "   gl_Position = matrix * posAttr;\n"
        "}\n";

    static const char* fragmentShaderSource =
        "varying lowp vec4 col;\n"
        "void main() {\n"
        "   gl_FragColor = col;\n"
        "}\n";*/




    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();

    m_posAttr = mProgram->attributeLocation("posAttr");
    m_colAttr = mProgram->attributeLocation("colAttr");
    m_matrixUniform = mProgram->uniformLocation("matrix");

    if (m_posAttr == -1 || m_colAttr == -1 || m_matrixUniform == -1)
    {
        qDebug() << "Shader attribute or uniform location error.";
        // Handle the error appropriately, e.g., return or throw an exception
    }
}

