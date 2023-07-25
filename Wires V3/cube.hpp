class Cube {
private:
	Shader shader;
	glm::mat4 model;
	unsigned int VBO;
	unsigned int VAO;
public:
	glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f);
	glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);

	Cube() {
		this->shader = Shader("solid.vert", "solid.frag");
		this->model = glm::mat4(1.0f);

		float vertices[] = {
			// position         // normal          
			0.0f, 0.0f, 0.0f,   0.0f,  0.0f, -1.0f,
			1.0f, 1.0f, 0.0f,   0.0f,  0.0f, -1.0f,
			1.0f, 0.0f, 0.0f,   0.0f,  0.0f, -1.0f,
			0.0f, 0.0f, 0.0f,   0.0f,  0.0f, -1.0f,
			1.0f, 1.0f, 0.0f,   0.0f,  0.0f, -1.0f,
			0.0f, 1.0f, 0.0f,   0.0f,  0.0f, -1.0f,

			0.0f, 0.0f, 1.0f,   0.0f,  0.0f,  1.0f,
			1.0f, 1.0f, 1.0f,   0.0f,  0.0f,  1.0f,
			1.0f, 0.0f, 1.0f,   0.0f,  0.0f,  1.0f,
			0.0f, 0.0f, 1.0f,   0.0f,  0.0f,  1.0f,
			1.0f, 1.0f, 1.0f,   0.0f,  0.0f,  1.0f,
			0.0f, 1.0f, 1.0f,   0.0f,  0.0f,  1.0f,

			0.0f, 0.0f, 0.0f,   0.0f, -1.0f,  0.0f,
			1.0f, 0.0f, 1.0f,   0.0f, -1.0f,  0.0f,
			1.0f, 0.0f, 0.0f,   0.0f, -1.0f,  0.0f,
			0.0f, 0.0f, 0.0f,   0.0f, -1.0f,  0.0f,
			1.0f, 0.0f, 1.0f,   0.0f, -1.0f,  0.0f,
			0.0f, 0.0f, 1.0f,   0.0f, -1.0f,  0.0f,

			0.0f, 1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
			1.0f, 1.0f, 1.0f,   0.0f,  1.0f,  0.0f,
			1.0f, 1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
			0.0f, 1.0f, 0.0f,   0.0f,  1.0f,  0.0f,
			1.0f, 1.0f, 1.0f,   0.0f,  1.0f,  0.0f,
			0.0f, 1.0f, 1.0f,   0.0f,  1.0f,  0.0f,

			0.0f, 0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
			0.0f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
			0.0f, 1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
			0.0f, 0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,
			0.0f, 1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,
			0.0f, 0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,

			1.0f, 0.0f, 0.0f,   1.0f,  0.0f,  0.0f,
			1.0f, 1.0f, 1.0f,   1.0f,  0.0f,  0.0f,
			1.0f, 1.0f, 0.0f,   1.0f,  0.0f,  0.0f,
			1.0f, 0.0f, 0.0f,   1.0f,  0.0f,  0.0f,
			1.0f, 1.0f, 1.0f,   1.0f,  0.0f,  0.0f,
			1.0f, 0.0f, 1.0f,   1.0f,  0.0f,  0.0f,
		};

		glGenVertexArrays(1, &this->VAO);
		glGenBuffers(1, &this->VBO);
		glBindVertexArray(this->VAO);
		glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	void move(float x, float y, float z) {
		this->model = glm::translate(this->model, glm::vec3(x, y, z));
		this->pos = this->pos + glm::vec3(x, y, z);
	}

	void moveAbsolute(glm::vec3 newPos) {
		this->model = glm::translate(glm::mat4(1.0f), newPos);
		this->pos = newPos;
	}

	void draw() {
		glBindVertexArray(VAO);
		glUseProgram(shader.shaderProgram);
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "proj"), 1, GL_FALSE, glm::value_ptr(proj));
		glUniform3fv(glGetUniformLocation(shader.shaderProgram, "objectColor"), 1, glm::value_ptr(color));
		glUniform3fv(glGetUniformLocation(shader.shaderProgram, "viewPos"), 1, glm::value_ptr(player.pos));
		glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirX"), player.angleX);
		glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirY"), player.angleY);

		glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	~Cube() {
		glDeleteVertexArrays(1, &this->VAO);
		glDeleteBuffers(1, &this->VBO);
	}
};