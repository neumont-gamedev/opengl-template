#include "stdafx.h"
#include "renderer.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec3.hpp>

#include <stdlib.h>

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

Renderer::Renderer()
{
}


Renderer::~Renderer()
{
}

bool Renderer::Initialize()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	{
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	return true;
}

void Renderer::Shutdown()
{
	glfwTerminate();
}