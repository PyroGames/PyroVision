// PyroVision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main()
{
    std::cout << "Hello World!\n";

	/***********************************************/
	//GLFW setup
	//https://www.glfw.org/documentation.html
	/***********************************************/
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	unsigned windowWidth = 640;
	unsigned windowHeight = 480;
	window = glfwCreateWindow(windowWidth, windowHeight, "PyroVision v1.0", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	// init GLEW
	if (glewInit() == GLEW_OK) {
		std::cout << "glewInit success" << std::endl;
	}
	else {
		std::cout << "glewInit did not return GLEW_OK" << std::endl;
	}

	// print out openGL version
	std::cout << "Running openGL version: " << glGetString(GL_VERSION) << std::endl;


	//draw a triangle
	float vertices[6] = {
		-0.5f, -0.5f,
		 0.0f,  0.5f,
		 0.5f, -0.5f
	};

	unsigned int buffer;
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), vertices, GL_STATIC_DRAW);

	// main game loop
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	/***********************************************/
	/***********************************************/
	return 0;
}