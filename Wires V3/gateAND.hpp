class GateAND : public Gate {
private:
	Model* chip;
	Input* a;
	Input* b;
	Output* s;

	glm::ivec3 oldPos;
	int oldRotation;
public:
	glm::ivec3 pos;
	int rotation;

	GateAND(glm::ivec3 pos, int rotation) {
		this->chip = new Model("Models3D/chipAND/modelT.obj", "Models3D/chipAND/tex.png", glm::vec3(0.1f, 0.1f, 0.1f));
		this->a = new Input();
		this->b = new Input();
		this->s = new Output();

		this->pos = pos;
		this->rotation = rotation;

		this->chip->moveAbsolute(glm::vec3(pos));
		this->a->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));
		this->b->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) + 1));
		this->s->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) - 1));

		float angle = 1.5707963267948966f * rotation;
		this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));
		this->a->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
		this->b->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
		this->s->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->chip->moveAbsolute(glm::vec3(pos));
			this->a->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));
			this->b->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) + 1));
			this->s->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) - 1));

			float angle = 1.5707963267948966f * rotation;
			this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));
			this->a->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
			this->b->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
			this->s->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip1;
		Pos chip2;
		Pos in1;
		Pos in2;
		Pos out1;


		// pukty do sprawdzenia
		if (this->rotation == 0) {
			chip1 = { this->pos };
			chip2 = { glm::vec3((pos.x) + 1, pos.y, pos.z) };
			in1 = { glm::vec3(pos.x,       pos.y, (pos.z) + 1) };
			in2 = { glm::vec3((pos.x) + 1, pos.y, (pos.z) + 1) };
			out1 = { glm::vec3(pos.x, pos.y, (pos.z) - 1) };
		}
		else if (this->rotation == 1) {
			chip1 = { this->pos };
			chip2 = { glm::vec3(pos.x, pos.y, (pos.z) - 1) };
			in1 = { glm::vec3((pos.x) + 1, pos.y, pos.z) };
			in2 = { glm::vec3((pos.x) + 1, pos.y, (pos.z) - 1) };
			out1 = { glm::vec3((pos.x) - 1, pos.y, pos.z) };
		}
		else if (this->rotation == 2) {
			chip1 = { pos + glm::ivec3(0,  0,  0) };
			chip2 = { pos + glm::ivec3(-1,  0,  0) };
			in1 = { pos + glm::ivec3(0,  0, -1) };
			in2 = { pos + glm::ivec3(-1,  0, -1) };
			out1 = { pos + glm::ivec3(0,  0,  1) };
		}
		else if (this->rotation == 3) {
			chip1 = { pos + glm::ivec3(0,  0,  0) };
			chip2 = { pos + glm::ivec3(0,  0,  1) };
			in1 = { pos + glm::ivec3(-1,  0,  0) };
			in2 = { pos + glm::ivec3(-1,  0,  1) };
			out1 = { pos + glm::ivec3(1,  0,  0) };
		}
		else {
			return false;
		}


		// szukanie
		void* in1Ptr = NULL;
		void* in2Ptr = NULL;
		void* out1Ptr = NULL;
		auto search = map->find(chip1);
		if (search != map->end()) {
			// znalazlo cos
			return false;
		}
		search = map->find(chip2);
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
		search = map->find(in2);
		if (search != map->end()) {
			// znalazlo cos
			// connect input only to wire
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in2Ptr = search->second[x].ptr;
				}
			}
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
		std::vector<What> c1{ What{ "chip AND", this } };
		std::vector<What> c2{ What{ "chip AND", this } };
		std::vector<What> i1{ What{ "input", this->a } };
		std::vector<What> i2{ What{ "input", this->b } };
		std::vector<What> o1{ What{ "output", this->s} };
		if (in1Ptr != NULL) {
			i1.push_back(What{ "wire", in1Ptr });
			((Wire*)in1Ptr)->outputs.push_back(this->a);
		}
		if (in2Ptr != NULL) {
			i2.push_back(What{ "wire", in2Ptr });
			((Wire*)in2Ptr)->outputs.push_back(this->b);
		}
		if (out1Ptr != NULL) {
			o1.push_back(What{ "wire", out1Ptr });
			((Wire*)out1Ptr)->inputs.push_back(this->s);
		}
		map->insert_or_assign(chip1, c1);
		map->insert_or_assign(chip2, c2);
		map->insert_or_assign(in1, i1);
		map->insert_or_assign(in2, i2);
		map->insert_or_assign(out1, o1);
		return true;
	}

	void update() {
		this->s->state = this->a->state && this->b->state;
	}

	void draw() {
		this->chip->draw();
		this->a->draw();
		this->b->draw();
		this->s->draw();
	}

	~GateAND() {
		delete this->chip;
		delete this->a;
		delete this->b;
		delete this->s;
	}
};