class Lamp {
private:
	Cube* model;
	Input* a;

	glm::ivec3 oldPos;
	int oldRotation;
public:
	bool state = false;

	glm::ivec3 pos;
	int rotation;

	Lamp(glm::ivec3 pos, int rotation) {
		this->model = new Cube();
		this->model->color = COLOROFF;
		this->a = new Input();

		this->pos = pos;
		this->rotation = rotation;

		this->model->moveAbsolute(glm::vec3(pos));
		this->a->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));

		float angle = 1.5707963267948966f * rotation;
		this->a->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->model->moveAbsolute(glm::vec3(pos));
			this->a->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));

			float angle = 1.5707963267948966f * rotation;
			this->a->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip1;
		Pos in1;

		chip1 = { this->pos };
		if (this->rotation == 0) {
			in1 = { pos + glm::ivec3(0,  0,  1) };
		}
		else if (this->rotation == 1) {
			in1 = { pos + glm::ivec3(1,  0,  0) };
		}
		else if (this->rotation == 2) {
			in1 = { pos + glm::ivec3(0,  0, -1) };
		}
		else if (this->rotation == 3) {
			in1 = { pos + glm::ivec3(-1,  0,  0) };
		}
		else {
			return false;
		}


		// szukanie
		void* in1Ptr = NULL;
		auto search = map->find(chip1);
		if (search != map->end()) {
			// znalazlo cos
			return false;
		}
		search = map->find(in1);
		if (search != map->end()) {
			// znalazlo cos
			// connect input only to wire
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in1Ptr = search->second[x].ptr;
				}
			}
		}


		// jesli mo¿na stworzyc
		std::vector<What> c1{ What{ "lamp", this } };
		std::vector<What> i1{ What{ "input", this->a } };
		if (in1Ptr != NULL) {
			i1.push_back(What{ "wire", in1Ptr });
			((Wire*)in1Ptr)->outputs.push_back(this->a);
		}
		map->insert_or_assign(chip1, c1);
		map->insert_or_assign(in1, i1);
		return true;
	}

	void update() {
		this->state = this->a->state;

		if (this->state) {
			this->model->color = COLORON;
		}
		else {
			this->model->color = COLOROFF;
		}
	}

	void draw() {
		this->model->draw();
		this->a->draw();
	}

	~Lamp() {
		delete this->model;
		delete this->a;
	}
};