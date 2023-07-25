#pragma once
#ifndef PLAYER_HPP
#define PLAYER_HPP
#endif

#include "cubeWireframe.hpp"

//glm::mat4 rotationX(float angle) {
//	return glm::mat4(1.0, 0, 0, 0,
//		0, cos(angle), -sin(angle), 0,
//		0, sin(angle), cos(angle), 0,
//		0, 0, 0, 1);
//}
//
//glm::mat4 rotationY(float angle) {
//	return glm::mat4(cos(angle), 0, sin(angle), 0,
//		0, 1.0, 0, 0,
//		-sin(angle), 0, cos(angle), 0,
//		0, 0, 0, 1);
//}
//
//glm::mat4 rotationZ(float angle) {
//	return glm::mat4(cos(angle), -sin(angle), 0, 0,
//		sin(angle), cos(angle), 0, 0,
//		0, 0, 1, 0,
//		0, 0, 0, 1);
//}

glm::mat3 rotationX(float angle) {
	return glm::mat3(1.0, 0, 0,
		0, cos(angle), -sin(angle),
		0, sin(angle), cos(angle));
}

glm::mat3 rotationY(float angle) {
	return glm::mat3(cos(angle), 0, sin(angle),
		0, 1.0, 0,
		-sin(angle), 0, cos(angle));
}

glm::mat3 rotationZ(float angle) {
	return glm::mat3(cos(angle), -sin(angle), 0,
		sin(angle), cos(angle), 0,
		0, 0, 1);
}

class Player {
private:
	GLFWwindow* window;
	float speed = 0.025f;
	float sens = 0.005f;
	float vecX = 0.0f;
	float vecZ = speed;
	double oldMouseX;
	double oldMouseY;
	CubeWireframe cubeWireframe;
public:
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 Orientation;
	float angleY = 0.0f;
	float angleX = 0.0f;
	glm::ivec3 posBlock = glm::ivec3(0, 0, 0);
	glm::ivec3 posBlockLookAt = glm::ivec3(0, 0, 0);

	Player(GLFWwindow* window) {
		this->window = window;
		this->cubeWireframe = CubeWireframe();
	}

	void update() {
		double mouseX;
		double mouseY;
		glfwGetCursorPos(window, &mouseX, &mouseY);
		angleY += (oldMouseX - mouseX) * sens;
		angleX -= (oldMouseY - mouseY) * sens;
		oldMouseX = mouseX;
		oldMouseY = mouseY;

		if (angleX > 1.57) {
			angleX = 1.57;
		}
		else if (angleX < -1.57) {
			angleX = -1.57;
		}
		vecZ = cos(angleY) * speed;
		vecX = sin(angleY) * speed;
		// po co tu * speed xd
		Orientation = glm::normalize(glm::vec3(cos(angleX) * vecX, sin(angleX) * -speed, cos(angleX) * vecZ));

		if (glfwGetKey(this->window, GLFW_KEY_W)) {
			pos.x += vecX;
			pos.z += vecZ;
		}
		if (glfwGetKey(this->window, GLFW_KEY_S)) {
			pos.x -= vecX;
			pos.z -= vecZ;
		}
		if (glfwGetKey(this->window, GLFW_KEY_A)) {
			pos.x += vecZ;
			pos.z -= vecX;
		}
		if (glfwGetKey(this->window, GLFW_KEY_D)) {
			pos.x -= vecZ;
			pos.z += vecX;
		}
		if (glfwGetKey(this->window, GLFW_KEY_LEFT_SHIFT)) {
			pos.y -= speed;
		}
		if (glfwGetKey(this->window, GLFW_KEY_SPACE)) {
			pos.y += speed;
		}

		// Calc posBlock
		if (pos.x >= 0.0f) {
			this->posBlock.x = (int)pos.x;
		}
		else {
			this->posBlock.x = (int)pos.x - 1.0f;
		}
		if (pos.y >= 0.0f) {
			this->posBlock.y = (int)pos.y;
		}
		else {
			this->posBlock.y = (int)pos.y - 1.0f;
		}
		if (pos.z >= 0.0f) {
			this->posBlock.z = (int)pos.z;
		}
		else {
			this->posBlock.z = (int)pos.z - 1.0f;
		}

		// Calc posBlockLookAt
		//glm::vec3 temp = pos + Orientation * (10.0f * this->scroll + 100.0f);
		glm::vec3 temp = pos + Orientation * (3.0f);
		if (temp.x >= 0.0f) {
			this->posBlockLookAt.x = (int)temp.x;
		}
		else {
			this->posBlockLookAt.x = (int)temp.x - 1.0f;
		}
		if (temp.y >= 0.0f) {
			this->posBlockLookAt.y = (int)temp.y;
		}
		else {
			this->posBlockLookAt.y = (int)temp.y - 1.0f;
		}
		if (temp.z >= 0.0f) {
			this->posBlockLookAt.z = (int)temp.z;
		}
		else {
			this->posBlockLookAt.z = (int)temp.z - 1.0f;
		}

		view = glm::lookAt(pos, pos + Orientation, glm::vec3(0.0f, 1.0f, 0.0f));
		this->cubeWireframe.moveAbsolute(this->posBlockLookAt.x, this->posBlockLookAt.y, this->posBlockLookAt.z);
	}

	void draw() {
		this->cubeWireframe.draw();
	}
};