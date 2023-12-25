# Visualizer Project - Scaling (Shader Implementation)

## Overview

This project is a `graphical application` developed in `C++` using the `Qt framework` with `OpenGL` for rendering. The primary objective is to serve as a `visualization tool` to demonstrate how `CAGD algorithm` works.By continuing `OpenGl Automation` i have modified `Shader Program` to show `Scaling Feature`.Feature explained at end of this file.

### File Structure

**Libraries**

1. `Sutherland.lib` - Includes `Sutherland.h` and `Sutherland.cpp`

2. `Bezier.lib` - Includes `Bezier.h` and `Bezier.cpp`

3. `Hermite.lib` - Includes `Hermite.h` and `Bezier.cpp`

4. `BSpline.lib` - Includes `BSpline.h` and `BSpline.cpp`

5. `Geometry.lib`

Includes various geometry classes as follows

- `Point3D.h` and `Point3D.cpp`

- `Line.h` and `Line.cpp`

- `Shape.h` and `Shape.cpp`

**Visualizer App** 

1. Includes `Visualizer.h` and `Visualizer.cpp`
- GUI components are implemented in these files.

2. Includes `OpenGLWindow.h` and `OpenGLWindow.cpp`
- Responsible for handling OpenGL rendering.

3. And `main.cpp`
- Entry point for the application, initializes and runs the graphical line clipping tool.

**Scaling Implementaion**
1. Added two buttons `Scale Up` and `Scale Down` in GUI.

2. Defined two connectors `scaleUpClicked` and `scaleDownClicked` in `Visualizer.cpp`, passes `scaling factor` to `OpenGLWindow.cpp`.

3. Defined `setScaleFactor` function that takes scale factor value and update scale `mScaleFactor`.

4. Created  `QMatrix4x4 scaleMatrix;` to scale drawing. 

5. And updated `vertexShader.glsl`.
