#pragma once

#include <stdlib.h>
#include <iostream>
#include <fstream>

class Renderer
{
public:
	Renderer();
	~Renderer();

	bool Initialize();
	void Shutdown();

	GLuint CreateShaderProgram(const std::string& vertextShader, const std::string& fragmentShader);
	GLuint CreateShader(const std::string& shader, GLenum shaderType);

private:
	std::string ReadFile(const std::string& filename);

public:
	GLFWwindow* m_window;
};

