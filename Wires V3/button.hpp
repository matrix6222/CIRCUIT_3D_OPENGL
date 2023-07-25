class Button {
private:
	Cube* model;
	Output* s;

	glm::ivec3 oldPos;
	int oldRotation;
public:
	bool state = false;

	glm::ivec3 pos;
	int rotation;

	Button(glm::ivec3 pos, int rotation) {
		this->model = new Cube();
		this->model->color = COLOROFF;
		this->s = new Output();

		this->pos = pos;
		this->rotation = rotation;

		this->model->moveAbsolute(glm::vec3(pos));
		this->s->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) - 1));

		float angle = 1.5707963267948966f * rotation;
		this->s->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->model->moveAbsolute(glm::vec3(pos));
			this->s->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) - 1));

			float angle = 1.5707963267948966f * rotation;
			this->s->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip1;
		Pos out1;

		chip1 = { this->pos };
		if (this->rotation == 0) {
			out1 = { pos + glm::ivec3(0,  0,  -1) };
		}
		else if (this->rotation == 1) {
			out1 = { pos + glm::ivec3(-1,  0,  0) };
		}
		else if (this->rotation == 2) {
			out1 = { pos + glm::ivec3(0,  0,  1) };
		}
		else if (this->rotation == 3) {
			out1 = { pos + glm::ivec3(1,  0,  0) };
		}
		else {
			return false;
		}


		// szukanie
		void* out1Ptr = NULL;
		auto search = map->find(chip1);
		if (search != map->end()) {
			// znalazlo cos
			return false;
		}
		search = map->find(out1);
		if (search != map->end()) {
			// znalazlo cos
			// connect output only to wire
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out1Ptr = search->second[x].ptr;
				}
			}
		}


		// jesli mo¿na stworzyc
		std::vector<What> c1{ What{ "chip button", this } };
		std::vector<What> o1{ What{ "output", this->s } };
		if (out1Ptr != NULL) {
			o1.push_back(What{"wire", out1Ptr});
			((Wire*)out1Ptr)->inputs.push_back(this->s);
		}
		std::cout << o1.size() << std::endl;
		map->insert_or_assign(chip1, c1);
		map->insert_or_assign(out1, o1);
		return true;
	}

	void click() {
		this->state = !this->state;
		this->s->state = this->state;

		if (this->state) {
			this->model->color = COLORON;
		}
		else {
			this->model->color = COLOROFF;
		}
	}

	void draw() {
		this->model->draw();
		this->s->draw();
	}

	~Button() {
		delete this->model;
		delete this->s;
	}
};