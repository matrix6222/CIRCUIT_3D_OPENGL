class Wire {
private:
	Shader shader;
	glm::mat4 model;
	unsigned int VBO;
	unsigned int VAO;
	GLsizei verticesLen = 0;

	struct StartEnd {
		glm::ivec3 a;
		glm::ivec3 b;
	};
	glm::ivec3 startPos;
	glm::ivec3 endPos;

	bool isIn(Wire* element, std::vector<Wire*> tab) {
		for (size_t x = 0; x < tab.size(); x++) {
			if (element == tab[x]) {
				return true;
			}
		}
		return false;
	}
public:
	bool state = false;
	std::vector<StartEnd> lines;
	glm::vec3 color = COLOROFF;
	std::vector<Output*> inputs;
	std::vector<Input*> outputs;

	Wire(glm::ivec3 startPos) {
		this->shader = Shader("solid.vert", "solid.frag");
		this->startPos = startPos;
		this->endPos = startPos;
		this->model = glm::mat4(1.0f);
	}

	void setEndPos(glm::ivec3 endPos) {
		if (this->endPos != endPos) {
			glm::ivec3 vec = endPos - this->startPos;
			
			this->lines.clear();
			if (vec.x != 0) {
				StartEnd se = { this->startPos, this->startPos + glm::ivec3(vec.x, 0, 0)};
				this->lines.push_back(se);
			}
			if (vec.y != 0) {
				StartEnd se = { this->startPos + glm::ivec3(vec.x, 0, 0), this->startPos + glm::ivec3(vec.x, vec.y, 0) };
				this->lines.push_back(se);
			}
			if (vec.z != 0) {
				StartEnd se = { this->startPos + glm::ivec3(vec.x, vec.y, 0), this->startPos + glm::ivec3(vec.x, vec.y, vec.z) };
				this->lines.push_back(se);
			}
			this->endPos = endPos;
			this->genBuffer();
		}
		
	}

	// dim must be +x +y +z
	std::vector<float> genCubeNormal(glm::vec3 pos, glm::vec3 dim) {
		if (dim.x < 0 || dim.y < 0 || dim.z < 0) {
			std::cout << "error dim in Wire class, normals might be flipped" << std::endl;
		}
		std::vector<float> vertices;
		
		// right
		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);


		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);



		// left
		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);


		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);



		// up
		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);


		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);



		// down
		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);


		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(0.0f);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);



		// front
		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);


		vertices.push_back(pos.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(-1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);



		// back
		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);


		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y);
		vertices.push_back(pos.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z + dim.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		vertices.push_back(pos.x + dim.x);
		vertices.push_back(pos.y + dim.y);
		vertices.push_back(pos.z);
		vertices.push_back(1.0f);
		vertices.push_back(0.0f);
		vertices.push_back(0.0f);

		return vertices;
	}

	void genBuffer() {
		float wireSize = 0.2f;

		float wireS = 0.5f - wireSize;
		float wireR = 2 * wireSize;
		std::vector<float> vertices; // px, py, px, nx, ny, nz
		for (size_t x = 0; x < this->lines.size(); x++) {
			StartEnd se = this->lines[x];
			float sx = se.a.x;
			float sy = se.a.y;
			float sz = se.a.z;
			float ex = se.b.x;
			float ey = se.b.y;
			float ez = se.b.z;
			
			// kierunek +x
			if (ex - sx > 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(sx + wireS, sy + wireS, sz + wireS), glm::vec3(ex - sx + wireR, wireR, wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}
			// kierunek -x
			else if (ex - sx < 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(ex + wireS, ey + wireS, ez + wireS), glm::vec3(sx - ex + wireR, wireR, wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}

			// kierunek +y
			else if (ey - sy > 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(sx + wireS, sy + wireS, sz + wireS), glm::vec3(wireR, ey - sy + wireR, wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}
			// kierunek -y
			else if (ey - sy < 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(ex + wireS, ey + wireS, ez + wireS), glm::vec3(wireR, sy - ey + wireR, wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}

			// kierunek +z
			else if (ez - sz > 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(sx + wireS, sy + wireS, sz + wireS), glm::vec3(wireR, wireR, ez - sz + wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}
			// kierunek -z
			else if (ez - sz < 0) {
				std::vector<float> temp = this->genCubeNormal(glm::vec3(ex + wireS, ey + wireS, ez + wireS), glm::vec3(wireR, wireR, sz - ez + wireR));
				for (size_t y = 0; y < temp.size(); y++) {
					vertices.push_back(temp[y]);
				}
			}
		}


		this->verticesLen = vertices.size() / 6;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}

	std::vector<Pos> genPos() {
		std::vector<Pos> ret;
		std::map<Pos, int> set;
		for (size_t x = 0; x < this->lines.size(); x++) {
			StartEnd se = this->lines[x];
			// +-x
			if (se.a.x != se.b.x) {
				// +x
				if (se.a.x < se.b.x) {
					for (int y = se.a.x; y <= se.b.x; y++) {
						set[Pos{ glm::ivec3(y, se.a.y, se.a.z) }] = 0;
					}
				}
				// -x
				else {
					for (int y = se.b.x; y <= se.a.x; y++) {
						set[Pos{ glm::ivec3(y, se.a.y, se.a.z) }] = 0;
					}
				}
			}
			// +-y
			else if (se.a.y != se.b.y) {
				// +y
				if (se.a.y < se.b.y) {
					for (int y = se.a.y; y <= se.b.y; y++) {
						set[Pos{ glm::ivec3(se.a.x, y, se.a.z) }] = 0;
					}
				}
				// -y
				else {
					for (int y = se.b.y; y <= se.a.y; y++) {
						set[Pos{ glm::ivec3(se.a.x, y, se.a.z) }] = 0;
					}
				}
			}
			// +-z
			else {
				// +z
				if (se.a.z < se.b.z) {
					for (int y = se.a.z; y <= se.b.z; y++) {
						set[Pos{ glm::ivec3(se.a.x, se.a.y, y) }] = 0;
					}
				}
				// -z
				else {
					for (int y = se.b.z; y <= se.a.z; y++) {
						set[Pos{ glm::ivec3(se.a.x, se.a.y, y) }] = 0;
					}
				}
			}
		}
		for (auto x = set.begin(); x != set.end(); x++) {
			ret.push_back(x->first);
		}
		return ret;
	}

	bool connect(std::map<Pos, std::vector<What>>* map, std::vector<Wire*>* wires) {
		std::vector<Pos> points = this->genPos();
		if (points.size() == 0) {
			return false;
		}

		std::vector<std::vector<What>> whats;
		for (size_t x = 0; x < points.size(); x++) {
			std::vector<What> w{ What{ "wire", this } };
			whats.push_back(w);
		}


		// szukanie
		std::vector<Wire*> others;
		for (size_t x = 0; x < points.size(); x++) {
			auto search = map->find(points[x]);
			if (search != map->end()) {
				// znalazlo cos
				// TODO ewentualnie po³¹czyæ
				//for (size_t y = 0; y < search->second.size(); y++) {
				//	std::cout << "znalazlo: " << search->second[y].name << " ";
				//}
				//std::cout << std::endl;

				// jesli znalaz³o cos innego niz input i output to return false
				for (size_t y = 0; y < search->second.size(); y++) {
					if (search->second[y].name == "input") {
						// pod³¹cz input
						//std::cout << "podlacz input as output" << std::endl;
						whats[x].push_back(What{"input", search->second[y].ptr });
						this->outputs.push_back((Input*)search->second[y].ptr);
					}
					else if (search->second[y].name == "output") {
						// pod³¹cz output
						//std::cout << "podlacz output as input" << std::endl;
						whats[x].push_back(What{ "output", search->second[y].ptr });
						this->inputs.push_back((Output*)search->second[y].ptr);
					}
					else if (search->second[y].name == "wire") {
						// pod³¹cz wire
						//std::cout << "podlacz wire" << std::endl;
						// znajdz inne kable
						if (!isIn((Wire*)search->second[y].ptr, others)) {
							others.push_back((Wire*)search->second[y].ptr);
						}
					}
					else {
						return false;
					}
				}
			}
		}

		if (others.size() == 0) {
			//std::cout << "no connect to others wires" << std::endl;
			for (size_t x = 0; x < points.size(); x++) {
				map->insert_or_assign(points[x], std::vector<What>{whats[x]});
			}
		}
		else {
			//std::cout << "connect to others wires" << std::endl;
			//std::cout << "to remove: " << others.size() << std::endl;
			// copy others lines to this
			// copy others inputs to this (remove duplicates)
			// copy others outputs to this (remove duplicates)
			// generate new geometry
			// remove and delete others from vector
			// generate points from all lines and register in map2

			// copy others lines to this
			for (size_t x = 0; x < others.size(); x++) {
				std::vector<StartEnd> otherLines = others[x]->lines;
				for (size_t y = 0; y < otherLines.size(); y++) {
					this->lines.push_back(otherLines[y]);
				}
			}

			// remove others from vector
			//std::cout << "to remove: ";
			//for (size_t x = 0; x < others.size(); x++) {
			//	std::cout << others[x] << ", ";
			//}
			//std::cout << std::endl;
			//
			//
			//
			//std::cout << "from: ";
			//for (size_t x = 0; x < wires->size(); x++) {
			//	std::cout << wires->data()[x] << ", ";
			//}
			//std::cout << std::endl;
			//
			//
			//
			for (size_t x = 0; x < others.size(); x++) {
				wires->erase(std::remove(wires->begin(), wires->end(), others[x]), wires->end());
				delete others[x];
			}
			//
			//
			//
			//std::cout << "result: ";
			//for (size_t x = 0; x < wires->size(); x++) {
			//	std::cout << wires->data()[x] << ", ";
			//}
			//std::cout << std::endl;

			// delete others
			//for (size_t x = 0; x < others.size(); x++) {
			//	delete others[x];
			//}


			points = this->genPos();
			whats.clear();
			for (size_t x = 0; x < points.size(); x++) {
				std::vector<What> w{ What{ "wire", this } };
				whats.push_back(w);
			}
			this->outputs.clear();
			this->inputs.clear();
			for (size_t x = 0; x < points.size(); x++) {
				std::vector<What> w{ What{ "wire", this } };
				whats.push_back(w);
			}
			for (size_t x = 0; x < points.size(); x++) {
				auto search = map->find(points[x]);
				if (search != map->end()) {
					// znalazlo cos
					// TODO ewentualnie po³¹czyæ

					for (size_t y = 0; y < search->second.size(); y++) {
						if (search->second[y].name == "input") {
							// pod³¹cz input
							//std::cout << "podlacz input as output" << std::endl;
							whats[x].push_back(What{ "input", search->second[y].ptr });
							this->outputs.push_back((Input*)search->second[y].ptr);
						}
						else if (search->second[y].name == "output") {
							// pod³¹cz output
							//std::cout << "podlacz output as input" << std::endl;
							whats[x].push_back(What{ "output", search->second[y].ptr });
							this->inputs.push_back((Output*)search->second[y].ptr);
						}
					}
				}
			}
			for (size_t x = 0; x < points.size(); x++) {
				map->insert_or_assign(points[x], std::vector<What>{whats[x]});
			}
			this->genBuffer();
		}
		return true;
	}

	void update() {
		this->state = false;
		this->color = COLOROFF;
		for (size_t x = 0; x < this->inputs.size(); x++) {
			if (this->inputs[x]->state == true) {
				this->state = true;
				this->color = COLORON;
				break;
			}
		}
		for (size_t x = 0; x < this->outputs.size(); x++) {
			this->outputs[x]->state = this->state;
		}
	}

	void draw() {
		if (this->verticesLen > 0) {
			glBindVertexArray(VAO);
			glUseProgram(shader.shaderProgram);
			glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
			glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
			glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "proj"), 1, GL_FALSE, glm::value_ptr(proj));
			glUniform3fv(glGetUniformLocation(shader.shaderProgram, "objectColor"), 1, glm::value_ptr(color));
			glUniform3fv(glGetUniformLocation(shader.shaderProgram, "viewPos"), 1, glm::value_ptr(player.pos));
			glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirX"), player.angleX);
			glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirY"), player.angleY);
			glDrawArrays(GL_TRIANGLES, 0, this->verticesLen);
		}
	}
};