#include "stdafx.h"

#include <glm/vec3.hpp>

#include <stdlib.h>

#include "renderer.h"

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main()
{
	Renderer* renderer = new Renderer();

	if (!renderer->Initialize())
	{
		renderer->Shutdown();
		delete renderer;
		exit(EXIT_FAILURE);
	}

	glfwSetKeyCallback(renderer->m_window, key_callback);

	// render code
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	// initialize scene
	GLuint program = renderer->CreateShaderProgram("..\\Resources\\Shaders\\basic.vert", "..\\Resources\\Shaders\\basic.frag");

	// main game loop
	while (!glfwWindowShouldClose(renderer->m_window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwPollEvents();
		glfwSwapBuffers(renderer->m_window);
	}

	renderer->Shutdown();

    return 0;
}

