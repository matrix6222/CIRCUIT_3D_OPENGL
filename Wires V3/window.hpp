#pragma once
#ifndef WINDOW_HPP
#define WINDOW_HPP
#endif


class Window {
private:
public:
	int resX;
	int resY;
	GLFWwindow* window;

	Window(int resX, int resY) {
		this->resX = resX;
		this->resY = resY;

		if (!glfwInit()) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
		this->window = glfwCreateWindow(this->resX, this->resY, "Window", NULL, NULL);
		if (!this->window) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}
		glfwMakeContextCurrent(this->window);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
			glfwTerminate();
			exit(EXIT_FAILURE);
		}

		glfwSetInputMode(this->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		glEnable(GL_DEPTH_TEST);

		this->calcProj();
	}

	void calcProj() {
		proj = glm::perspective(glm::radians(120.0f), (float)this->resX / (float)this->resY, 0.1f, 100.0f);
	}
};