#pragma once
#ifndef CUBEWIREFRAME_HPP
#define CUBEWIREFRAME_HPP
#endif


class CubeWireframe {
private:
	Shader shader;
	glm::mat4 model;
	unsigned int VBO;
	unsigned int VAO;
public:
	CubeWireframe() {
		this->shader = Shader("cubeWireframe.vert", "cubeWireframe.frag");
		this->model = glm::mat4(1.0f);

		float vertices[]{
			0.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 0.0f,

			1.0f, 0.0f, 0.0f,
			1.0f, 0.0f, 1.0f,

			1.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 1.0f,

			0.0f, 0.0f, 1.0f,
			0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 0.0f,

			1.0f, 1.0f, 0.0f,
			1.0f, 1.0f, 1.0f,

			1.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 1.0f,

			0.0f, 1.0f, 1.0f,
			0.0f, 1.0f, 0.0f,

			0.0f, 0.0f, 0.0f,
			0.0f, 1.0f, 0.0f,

			1.0f, 0.0f, 0.0f,
			1.0f, 1.0f, 0.0f,

			1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f,

			0.0f, 0.0f, 1.0f,
			0.0f, 1.0f, 1.0f,
		};

		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
	}

	void moveAbsolute(float x, float y, float z) {
		this->model = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
	}

	void draw() {
		glBindVertexArray(VAO);
		glUseProgram(shader.shaderProgram);
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "proj"), 1, GL_FALSE, glm::value_ptr(proj));
		glDrawArrays(GL_LINES, 0, 24);
	}
};