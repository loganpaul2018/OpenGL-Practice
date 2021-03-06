#include <iostream>
#include "definitions/base/base.h"
#include "definitions/window.h"
#include "definitions\input_handler.h"
using namespace std;

int main()
{
	Initializer::InitGL();

	auto window = Window(800, 600, "test");
	Initializer::GLAD_Init();
	window.setUp();

	auto* window_ptr = window.getWindowPointer();
	auto handler = InputHandler(window_ptr);

	handler.handle(GLFW_KEY_ESCAPE,
		[window_ptr]() {glfwSetWindowShouldClose(window_ptr, true); });

	glClearColor(0.4f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window_ptr))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		handler.listen();

		glfwSwapBuffers(window_ptr);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0x1;
}