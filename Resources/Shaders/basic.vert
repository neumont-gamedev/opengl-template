#version 430

in vec3 vertexPosition;
in vec3 vertexColor;

out vec3 color;

void main()
{
	color = vertexColor;
	gl_Position = vec4(vertexPosition, 1.0);
}
