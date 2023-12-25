attribute highp vec4 posAttr;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;
uniform highp mat4 scaleMatrix;
void main()
{
col = colAttr;
gl_Position = matrix * (scaleMatrix * posAttr);
}
