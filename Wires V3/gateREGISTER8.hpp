class GateREGISTER8 : public Gate {
private:
	Model* chip;

	Input* clk;
	Input* d0;
	Input* d1;
	Input* d2;
	Input* d3;
	Input* d4;
	Input* d5;
	Input* d6;
	Input* d7;

	Input* mr;
	Output* o0;
	Output* o1;
	Output* o2;
	Output* o3;
	Output* o4;
	Output* o5;
	Output* o6;
	Output* o7;

	glm::ivec3 oldPos;
	int oldRotation;

	bool oldClk = false;
	bool oldMr = false;
public:
	glm::ivec3 pos;
	int rotation;

	GateREGISTER8(glm::ivec3 pos, int rotation) {
		this->chip = new Model("Models3D/chipREGISTER8/modelT.obj", "Models3D/chipREGISTER8/texA.png", glm::vec3(0.1f, 0.1f, 0.1f));
		
		this->clk = new Input();
		this->d0 = new Input();
		this->d1 = new Input();
		this->d2 = new Input();
		this->d3 = new Input();
		this->d4 = new Input();
		this->d5 = new Input();
		this->d6 = new Input();
		this->d7 = new Input();

		this->mr = new Input(true);
		this->o0 = new Output();
		this->o1 = new Output();
		this->o2 = new Output();
		this->o3 = new Output();
		this->o4 = new Output();
		this->o5 = new Output();
		this->o6 = new Output();
		this->o7 = new Output();

		this->pos = pos;
		this->rotation = rotation;

		this->chip->moveAbsolute(glm::vec3(pos));
		this->clk->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));
		this->d0->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) + 1));
		this->d1->moveAbsolute(glm::vec3((pos.x) + 2, pos.y, (pos.z) + 1));
		this->d2->moveAbsolute(glm::vec3((pos.x) + 3, pos.y, (pos.z) + 1));
		this->d3->moveAbsolute(glm::vec3((pos.x) + 4, pos.y, (pos.z) + 1));
		this->d4->moveAbsolute(glm::vec3((pos.x) + 5, pos.y, (pos.z) + 1));
		this->d5->moveAbsolute(glm::vec3((pos.x) + 6, pos.y, (pos.z) + 1));
		this->d6->moveAbsolute(glm::vec3((pos.x) + 7, pos.y, (pos.z) + 1));
		this->d7->moveAbsolute(glm::vec3((pos.x) + 8, pos.y, (pos.z) + 1));

		this->mr->moveAbsolute(glm::vec3((pos.x) + 0, pos.y, (pos.z) - 1));
		this->o0->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) - 1));
		this->o1->moveAbsolute(glm::vec3((pos.x) + 2, pos.y, (pos.z) - 1));
		this->o2->moveAbsolute(glm::vec3((pos.x) + 3, pos.y, (pos.z) - 1));
		this->o3->moveAbsolute(glm::vec3((pos.x) + 4, pos.y, (pos.z) - 1));
		this->o4->moveAbsolute(glm::vec3((pos.x) + 5, pos.y, (pos.z) - 1));
		this->o5->moveAbsolute(glm::vec3((pos.x) + 6, pos.y, (pos.z) - 1));
		this->o6->moveAbsolute(glm::vec3((pos.x) + 7, pos.y, (pos.z) - 1));
		this->o7->moveAbsolute(glm::vec3((pos.x) + 8, pos.y, (pos.z) - 1));

		float angle = 1.5707963267948966f * rotation;
		this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));

		this->clk->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
		this->d0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
		this->d1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, -0.5f));
		this->d2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, -0.5f));
		this->d3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, -0.5f));
		this->d4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, -0.5f));
		this->d5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, -0.5f));
		this->d6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, -0.5f));
		this->d7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, -0.5f));

		this->mr->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));
		this->o0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, 1.5f));
		this->o1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, 1.5f));
		this->o2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, 1.5f));
		this->o3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, 1.5f));
		this->o4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, 1.5f));
		this->o5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, 1.5f));
		this->o6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, 1.5f));
		this->o7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, 1.5f));

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->chip->moveAbsolute(glm::vec3(pos));
			this->clk->moveAbsolute(glm::vec3(pos.x, pos.y, (pos.z) + 1));
			this->d0->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) + 1));
			this->d1->moveAbsolute(glm::vec3((pos.x) + 2, pos.y, (pos.z) + 1));
			this->d2->moveAbsolute(glm::vec3((pos.x) + 3, pos.y, (pos.z) + 1));
			this->d3->moveAbsolute(glm::vec3((pos.x) + 4, pos.y, (pos.z) + 1));
			this->d4->moveAbsolute(glm::vec3((pos.x) + 5, pos.y, (pos.z) + 1));
			this->d5->moveAbsolute(glm::vec3((pos.x) + 6, pos.y, (pos.z) + 1));
			this->d6->moveAbsolute(glm::vec3((pos.x) + 7, pos.y, (pos.z) + 1));
			this->d7->moveAbsolute(glm::vec3((pos.x) + 8, pos.y, (pos.z) + 1));

			this->mr->moveAbsolute(glm::vec3((pos.x) + 0, pos.y, (pos.z) - 1));
			this->o0->moveAbsolute(glm::vec3((pos.x) + 1, pos.y, (pos.z) - 1));
			this->o1->moveAbsolute(glm::vec3((pos.x) + 2, pos.y, (pos.z) - 1));
			this->o2->moveAbsolute(glm::vec3((pos.x) + 3, pos.y, (pos.z) - 1));
			this->o3->moveAbsolute(glm::vec3((pos.x) + 4, pos.y, (pos.z) - 1));
			this->o4->moveAbsolute(glm::vec3((pos.x) + 5, pos.y, (pos.z) - 1));
			this->o5->moveAbsolute(glm::vec3((pos.x) + 6, pos.y, (pos.z) - 1));
			this->o6->moveAbsolute(glm::vec3((pos.x) + 7, pos.y, (pos.z) - 1));
			this->o7->moveAbsolute(glm::vec3((pos.x) + 8, pos.y, (pos.z) - 1));

			float angle = 1.5707963267948966f * rotation;
			this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));

			this->clk->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
			this->d0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
			this->d1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, -0.5f));
			this->d2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, -0.5f));
			this->d3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, -0.5f));
			this->d4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, -0.5f));
			this->d5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, -0.5f));
			this->d6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, -0.5f));
			this->d7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, -0.5f));

			this->mr->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 1.5f));
			this->o0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, 1.5f));
			this->o1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, 1.5f));
			this->o2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, 1.5f));
			this->o3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, 1.5f));
			this->o4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, 1.5f));
			this->o5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, 1.5f));
			this->o6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, 1.5f));
			this->o7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, 1.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip1;
		Pos chip2;
		Pos chip3;
		Pos chip4;
		Pos chip5;
		Pos chip6;
		Pos chip7;
		Pos chip8;
		Pos chip9;

		Pos in1;
		Pos in2;
		Pos in3;
		Pos in4;
		Pos in5;
		Pos in6;
		Pos in7;
		Pos in8;
		Pos in9;
		Pos in10;

		Pos out1;
		Pos out2;
		Pos out3;
		Pos out4;
		Pos out5;
		Pos out6;
		Pos out7;
		Pos out8;


		// pukty do sprawdzenia
		if (this->rotation == 0) {
			chip1 = { pos + glm::ivec3(0,  0,  0) };
			chip2 = { pos + glm::ivec3(1,  0,  0) };
			chip3 = { pos + glm::ivec3(2,  0,  0) };
			chip4 = { pos + glm::ivec3(3,  0,  0) };
			chip5 = { pos + glm::ivec3(4,  0,  0) };
			chip6 = { pos + glm::ivec3(5,  0,  0) };
			chip7 = { pos + glm::ivec3(6,  0,  0) };
			chip8 = { pos + glm::ivec3(7,  0,  0) };
			chip9 = { pos + glm::ivec3(8,  0,  0) };

			in1 = { pos + glm::ivec3(0,  0,  1) };
			in2 = { pos + glm::ivec3(1,  0,  1) };
			in3 = { pos + glm::ivec3(2,  0,  1) };
			in4 = { pos + glm::ivec3(3,  0,  1) };
			in5 = { pos + glm::ivec3(4,  0,  1) };
			in6 = { pos + glm::ivec3(5,  0,  1) };
			in7 = { pos + glm::ivec3(6,  0,  1) };
			in8 = { pos + glm::ivec3(7,  0,  1) };
			in9 = { pos + glm::ivec3(8,  0,  1) };

			in10 = { pos + glm::ivec3(0,  0,  -1) };
			out1 = { pos + glm::ivec3(1,  0,  -1) };
			out2 = { pos + glm::ivec3(2,  0,  -1) };
			out3 = { pos + glm::ivec3(3,  0,  -1) };
			out4 = { pos + glm::ivec3(4,  0,  -1) };
			out5 = { pos + glm::ivec3(5,  0,  -1) };
			out6 = { pos + glm::ivec3(6,  0,  -1) };
			out7 = { pos + glm::ivec3(7,  0,  -1) };
			out8 = { pos + glm::ivec3(8,  0,  -1) };
		}
		else if (this->rotation == 1) {
			chip1 = { pos + glm::ivec3(0,  0,   0) };
			chip2 = { pos + glm::ivec3(0,  0,  -1) };
			chip3 = { pos + glm::ivec3(0,  0,  -2) };
			chip4 = { pos + glm::ivec3(0,  0,  -3) };
			chip5 = { pos + glm::ivec3(0,  0,  -4) };
			chip6 = { pos + glm::ivec3(0,  0,  -5) };
			chip7 = { pos + glm::ivec3(0,  0,  -6) };
			chip8 = { pos + glm::ivec3(0,  0,  -7) };
			chip9 = { pos + glm::ivec3(0,  0,  -8) };

			in1 = { pos + glm::ivec3(1,  0,   0) };
			in2 = { pos + glm::ivec3(1,  0,  -1) };
			in3 = { pos + glm::ivec3(1,  0,  -2) };
			in4 = { pos + glm::ivec3(1,  0,  -3) };
			in5 = { pos + glm::ivec3(1,  0,  -4) };
			in6 = { pos + glm::ivec3(1,  0,  -5) };
			in7 = { pos + glm::ivec3(1,  0,  -6) };
			in8 = { pos + glm::ivec3(1,  0,  -7) };
			in9 = { pos + glm::ivec3(1,  0,  -8) };

			in10 = { pos + glm::ivec3(-1,  0,   0) };
			out1 = { pos + glm::ivec3(-1,  0,  -1) };
			out2 = { pos + glm::ivec3(-1,  0,  -2) };
			out3 = { pos + glm::ivec3(-1,  0,  -3) };
			out4 = { pos + glm::ivec3(-1,  0,  -4) };
			out5 = { pos + glm::ivec3(-1,  0,  -5) };
			out6 = { pos + glm::ivec3(-1,  0,  -6) };
			out7 = { pos + glm::ivec3(-1,  0,  -7) };
			out8 = { pos + glm::ivec3(-1,  0,  -8) };
			
		}
		else if (this->rotation == 2) {
			chip1 = { pos + glm::ivec3( 0,  0,  0) };
			chip2 = { pos + glm::ivec3(-1,  0,  0) };
			chip3 = { pos + glm::ivec3(-2,  0,  0) };
			chip4 = { pos + glm::ivec3(-3,  0,  0) };
			chip5 = { pos + glm::ivec3(-4,  0,  0) };
			chip6 = { pos + glm::ivec3(-5,  0,  0) };
			chip7 = { pos + glm::ivec3(-6,  0,  0) };
			chip8 = { pos + glm::ivec3(-7,  0,  0) };
			chip9 = { pos + glm::ivec3(-8,  0,  0) };

			in1 = { pos + glm::ivec3( 0,  0, -1) };
			in2 = { pos + glm::ivec3(-1,  0, -1) };
			in3 = { pos + glm::ivec3(-2,  0, -1) };
			in4 = { pos + glm::ivec3(-3,  0, -1) };
			in5 = { pos + glm::ivec3(-4,  0, -1) };
			in6 = { pos + glm::ivec3(-5,  0, -1) };
			in7 = { pos + glm::ivec3(-6,  0, -1) };
			in8 = { pos + glm::ivec3(-7,  0, -1) };
			in9 = { pos + glm::ivec3(-8,  0, -1) };

			in10 = { pos + glm::ivec3( 0,  0,  1) };
			out1 = { pos + glm::ivec3(-1,  0,  1) };
			out2 = { pos + glm::ivec3(-2,  0,  1) };
			out3 = { pos + glm::ivec3(-3,  0,  1) };
			out4 = { pos + glm::ivec3(-4,  0,  1) };
			out5 = { pos + glm::ivec3(-5,  0,  1) };
			out6 = { pos + glm::ivec3(-6,  0,  1) };
			out7 = { pos + glm::ivec3(-7,  0,  1) };
			out8 = { pos + glm::ivec3(-8,  0,  1) };
		}
		else if (this->rotation == 3) {
			chip1 = { pos + glm::ivec3(0,  0,  0) };
			chip2 = { pos + glm::ivec3(0,  0,  1) };
			chip3 = { pos + glm::ivec3(0,  0,  2) };
			chip4 = { pos + glm::ivec3(0,  0,  3) };
			chip5 = { pos + glm::ivec3(0,  0,  4) };
			chip6 = { pos + glm::ivec3(0,  0,  5) };
			chip7 = { pos + glm::ivec3(0,  0,  6) };
			chip8 = { pos + glm::ivec3(0,  0,  7) };
			chip9 = { pos + glm::ivec3(0,  0,  8) };

			in1 = { pos + glm::ivec3(-1,  0, 0) };
			in2 = { pos + glm::ivec3(-1,  0, 1) };
			in3 = { pos + glm::ivec3(-1,  0, 2) };
			in4 = { pos + glm::ivec3(-1,  0, 3) };
			in5 = { pos + glm::ivec3(-1,  0, 4) };
			in6 = { pos + glm::ivec3(-1,  0, 5) };
			in7 = { pos + glm::ivec3(-1,  0, 6) };
			in8 = { pos + glm::ivec3(-1,  0, 7) };
			in9 = { pos + glm::ivec3(-1,  0, 8) };

			in10 = { pos + glm::ivec3(1,  0,  0) };
			out1 = { pos + glm::ivec3(1,  0,  1) };
			out2 = { pos + glm::ivec3(1,  0,  2) };
			out3 = { pos + glm::ivec3(1,  0,  3) };
			out4 = { pos + glm::ivec3(1,  0,  4) };
			out5 = { pos + glm::ivec3(1,  0,  5) };
			out6 = { pos + glm::ivec3(1,  0,  6) };
			out7 = { pos + glm::ivec3(1,  0,  7) };
			out8 = { pos + glm::ivec3(1,  0,  8) };
		}
		else {
			return false;
		}


		// szukanie
		void* in1Ptr = NULL;
		void* in2Ptr = NULL;
		void* in3Ptr = NULL;
		void* in4Ptr = NULL;
		void* in5Ptr = NULL;
		void* in6Ptr = NULL;
		void* in7Ptr = NULL;
		void* in8Ptr = NULL;
		void* in9Ptr = NULL;
		void* in10Ptr = NULL;

		void* out1Ptr = NULL;
		void* out2Ptr = NULL;
		void* out3Ptr = NULL;
		void* out4Ptr = NULL;
		void* out5Ptr = NULL;
		void* out6Ptr = NULL;
		void* out7Ptr = NULL;
		void* out8Ptr = NULL;

		auto search = map->find(chip1);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip2);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip3);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip4);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip5);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip6);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip7);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip8);
		if (search != map->end()) {
			return false;
		}
		search = map->find(chip9);
		if (search != map->end()) {
			return false;
		}
		
		search = map->find(in1);
		if (search != map->end()) {
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
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in2Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in3);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in3Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in4);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in4Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in5);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in5Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in6);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in6Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in7);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in7Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in8);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in8Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in9);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in9Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(in10);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					in10Ptr = search->second[x].ptr;
				}
			}
		}
		
		search = map->find(out1);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out1Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out2);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out2Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out3);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out3Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out4);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out4Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out5);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out5Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out6);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out6Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out7);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out7Ptr = search->second[x].ptr;
				}
			}
		}
		search = map->find(out8);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					out8Ptr = search->second[x].ptr;
				}
			}
		}


		// jesli mo¿na stworzyc
		std::vector<What> c1{ What{ "chip REGISTER8", this } };
		std::vector<What> c2{ What{ "chip REGISTER8", this } };
		std::vector<What> c3{ What{ "chip REGISTER8", this } };
		std::vector<What> c4{ What{ "chip REGISTER8", this } };
		std::vector<What> c5{ What{ "chip REGISTER8", this } };
		std::vector<What> c6{ What{ "chip REGISTER8", this } };
		std::vector<What> c7{ What{ "chip REGISTER8", this } };
		std::vector<What> c8{ What{ "chip REGISTER8", this } };
		std::vector<What> c9{ What{ "chip REGISTER8", this } };

		std::vector<What> i1{ What{ "input", this->clk } };
		std::vector<What> i2{ What{ "input", this->d0 } };
		std::vector<What> i3{ What{ "input", this->d1 } };
		std::vector<What> i4{ What{ "input", this->d2 } };
		std::vector<What> i5{ What{ "input", this->d3 } };
		std::vector<What> i6{ What{ "input", this->d4 } };
		std::vector<What> i7{ What{ "input", this->d5 } };
		std::vector<What> i8{ What{ "input", this->d6 } };
		std::vector<What> i9{ What{ "input", this->d7 } };
		std::vector<What> i10{ What{ "input", this->mr } };

		std::vector<What> o1{ What{ "output", this->o0} };
		std::vector<What> o2{ What{ "output", this->o1} };
		std::vector<What> o3{ What{ "output", this->o2} };
		std::vector<What> o4{ What{ "output", this->o3} };
		std::vector<What> o5{ What{ "output", this->o4} };
		std::vector<What> o6{ What{ "output", this->o5} };
		std::vector<What> o7{ What{ "output", this->o6} };
		std::vector<What> o8{ What{ "output", this->o7} };

		if (in1Ptr != NULL) {
			i1.push_back(What{ "wire", in1Ptr });
			((Wire*)in1Ptr)->outputs.push_back(this->clk);
		}
		if (in2Ptr != NULL) {
			i2.push_back(What{ "wire", in2Ptr });
			((Wire*)in2Ptr)->outputs.push_back(this->d0);
		}
		if (in3Ptr != NULL) {
			i3.push_back(What{ "wire", in3Ptr });
			((Wire*)in3Ptr)->outputs.push_back(this->d1);
		}
		if (in4Ptr != NULL) {
			i4.push_back(What{ "wire", in4Ptr });
			((Wire*)in4Ptr)->outputs.push_back(this->d2);
		}
		if (in5Ptr != NULL) {
			i5.push_back(What{ "wire", in5Ptr });
			((Wire*)in5Ptr)->outputs.push_back(this->d3);
		}
		if (in6Ptr != NULL) {
			i6.push_back(What{ "wire", in6Ptr });
			((Wire*)in6Ptr)->outputs.push_back(this->d4);
		}
		if (in7Ptr != NULL) {
			i7.push_back(What{ "wire", in7Ptr });
			((Wire*)in7Ptr)->outputs.push_back(this->d5);
		}
		if (in8Ptr != NULL) {
			i8.push_back(What{ "wire", in8Ptr });
			((Wire*)in8Ptr)->outputs.push_back(this->d6);
		}
		if (in9Ptr != NULL) {
			i9.push_back(What{ "wire", in9Ptr });
			((Wire*)in9Ptr)->outputs.push_back(this->d7);
		}
		if (in10Ptr != NULL) {
			i10.push_back(What{ "wire", in10Ptr });
			((Wire*)in10Ptr)->outputs.push_back(this->mr);
		}

		if (out1Ptr != NULL) {
			o1.push_back(What{ "wire", out1Ptr });
			((Wire*)out1Ptr)->inputs.push_back(this->o0);
		}
		if (out2Ptr != NULL) {
			o2.push_back(What{ "wire", out2Ptr });
			((Wire*)out2Ptr)->inputs.push_back(this->o1);
		}
		if (out3Ptr != NULL) {
			o3.push_back(What{ "wire", out3Ptr });
			((Wire*)out3Ptr)->inputs.push_back(this->o2);
		}
		if (out4Ptr != NULL) {
			o4.push_back(What{ "wire", out4Ptr });
			((Wire*)out4Ptr)->inputs.push_back(this->o3);
		}
		if (out5Ptr != NULL) {
			o5.push_back(What{ "wire", out5Ptr });
			((Wire*)out5Ptr)->inputs.push_back(this->o4);
		}
		if (out6Ptr != NULL) {
			o6.push_back(What{ "wire", out6Ptr });
			((Wire*)out6Ptr)->inputs.push_back(this->o5);
		}
		if (out7Ptr != NULL) {
			o7.push_back(What{ "wire", out7Ptr });
			((Wire*)out7Ptr)->inputs.push_back(this->o6);
		}
		if (out8Ptr != NULL) {
			o8.push_back(What{ "wire", out8Ptr });
			((Wire*)out8Ptr)->inputs.push_back(this->o7);
		}

		map->insert_or_assign(chip1, c1);
		map->insert_or_assign(chip2, c2);
		map->insert_or_assign(chip3, c3);
		map->insert_or_assign(chip4, c4);
		map->insert_or_assign(chip5, c5);
		map->insert_or_assign(chip6, c6);
		map->insert_or_assign(chip7, c7);
		map->insert_or_assign(chip8, c8);
		map->insert_or_assign(chip9, c9);

		map->insert_or_assign(in1, i1);
		map->insert_or_assign(in2, i2);
		map->insert_or_assign(in3, i3);
		map->insert_or_assign(in4, i4);
		map->insert_or_assign(in5, i5);
		map->insert_or_assign(in6, i6);
		map->insert_or_assign(in7, i7);
		map->insert_or_assign(in8, i8);
		map->insert_or_assign(in9, i9);
		map->insert_or_assign(in10, i10);

		map->insert_or_assign(out1, o1);
		map->insert_or_assign(out2, o2);
		map->insert_or_assign(out3, o3);
		map->insert_or_assign(out4, o4);
		map->insert_or_assign(out5, o5);
		map->insert_or_assign(out6, o6);
		map->insert_or_assign(out7, o7);
		map->insert_or_assign(out8, o8);
		return true;
	}

	void draw() {
		this->chip->draw();

		this->clk->draw();
		this->d0->draw();
		this->d1->draw();
		this->d2->draw();
		this->d3->draw();
		this->d4->draw();
		this->d5->draw();
		this->d6->draw();
		this->d7->draw();

		this->mr->draw();
		this->o0->draw();
		this->o1->draw();
		this->o2->draw();
		this->o3->draw();
		this->o4->draw();
		this->o5->draw();
		this->o6->draw();
		this->o7->draw();
	}

	void update() {
		if (this->oldClk == false && this->clk->state == true) {
			this->o0->state = this->d0->state;
			this->o1->state = this->d1->state;
			this->o2->state = this->d2->state;
			this->o3->state = this->d3->state;
			this->o4->state = this->d4->state;
			this->o5->state = this->d5->state;
			this->o6->state = this->d6->state;
			this->o7->state = this->d7->state;
		}
		
		if (this->oldMr == false && this->mr->state == true) {
			this->o0->state = false;
			this->o1->state = false;
			this->o2->state = false;
			this->o3->state = false;
			this->o4->state = false;
			this->o5->state = false;
			this->o6->state = false;
			this->o7->state = false;
		}

		this->oldClk = this->clk->state;
		this->oldMr = this->mr->state;
	}

	~GateREGISTER8() {
		delete this->chip;

		delete this->clk;
		delete this->d0;
		delete this->d1;
		delete this->d2;
		delete this->d3;
		delete this->d4;
		delete this->d5;
		delete this->d6;
		delete this->d7;

		delete this->mr;
		delete this->o0;
		delete this->o1;
		delete this->o2;
		delete this->o3;
		delete this->o4;
		delete this->o5;
		delete this->o6;
		delete this->o7;
	}
};