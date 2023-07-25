class Gate7SEGMENT4BIT : public Gate{
private:
	Model* chip;
	Model* segA;
	Model* segB;
	Model* segC;
	Model* segD;
	Model* segE;
	Model* segF;
	Model* segG;

	Input* in0;
	Input* in1;
	Input* in2;
	Input* in3;

	glm::ivec3 oldPos;
	int oldRotation;
public:
	glm::ivec3 pos;
	int rotation;

	Gate7SEGMENT4BIT(glm::ivec3 pos, int rotation) {
		this->chip = new Model("Models3D/chip7SEGMENT4BIT/main.obj", glm::vec3(0.1f, 0.1f, 0.1f));

		this->segA = new Model("Models3D/chip7SEGMENT4BIT/horizontalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segB = new Model("Models3D/chip7SEGMENT4BIT/verticalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segC = new Model("Models3D/chip7SEGMENT4BIT/verticalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segD = new Model("Models3D/chip7SEGMENT4BIT/horizontalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segE = new Model("Models3D/chip7SEGMENT4BIT/verticalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segF = new Model("Models3D/chip7SEGMENT4BIT/verticalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));
		this->segG = new Model("Models3D/chip7SEGMENT4BIT/horizontalLED.obj", glm::vec3(1.0f, 0.0f, 0.0f));

		this->in0 = new Input();
		this->in1 = new Input();
		this->in2 = new Input();
		this->in3 = new Input();

		this->pos = pos;
		this->rotation = rotation;

		this->chip->moveAbsolute(glm::vec3(pos));
		this->segA->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 6.1f, 0.0f));
		this->segB->moveAbsolute(glm::vec3(pos) + glm::vec3(0.7f, 6.0f, 0.0f));
		this->segC->moveAbsolute(glm::vec3(pos) + glm::vec3(0.7f, 3.4f, 0.0f));
		this->segD->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 0.9f, 0.0f));
		this->segE->moveAbsolute(glm::vec3(pos) + glm::vec3(3.3f, 3.4f, 0.0f));
		this->segF->moveAbsolute(glm::vec3(pos) + glm::vec3(3.3f, 6.0f, 0.0f));
		this->segG->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 3.5f, 0.0f));
		this->in0->moveAbsolute(pos + glm::ivec3(0, 0, 1));
		this->in1->moveAbsolute(pos + glm::ivec3(1, 0, 1));
		this->in2->moveAbsolute(pos + glm::ivec3(2, 0, 1));
		this->in3->moveAbsolute(pos + glm::ivec3(3, 0, 1));

		float angle = 1.5707963267948966f * rotation;
		this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));
		this->segA->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
		this->segB->rotateByPointAbsolute(angle, glm::vec3(-0.2f, 0.0f, 0.5f));
		this->segC->rotateByPointAbsolute(angle, glm::vec3(-0.2f, 0.0f, 0.5f));
		this->segD->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
		this->segE->rotateByPointAbsolute(angle, glm::vec3(-2.8f, 0.0f, 0.5f));
		this->segF->rotateByPointAbsolute(angle, glm::vec3(-2.8f, 0.0f, 0.5f));
		this->segG->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
		this->in0->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
		this->in1->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
		this->in2->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, -0.5f));
		this->in3->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, -0.5f));

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->chip->moveAbsolute(glm::vec3(pos));
			this->segA->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 6.1f, 0.0f));
			this->segB->moveAbsolute(glm::vec3(pos) + glm::vec3(0.7f, 6.0f, 0.0f));
			this->segC->moveAbsolute(glm::vec3(pos) + glm::vec3(0.7f, 3.4f, 0.0f));
			this->segD->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 0.9f, 0.0f));
			this->segE->moveAbsolute(glm::vec3(pos) + glm::vec3(3.3f, 3.4f, 0.0f));
			this->segF->moveAbsolute(glm::vec3(pos) + glm::vec3(3.3f, 6.0f, 0.0f));
			this->segG->moveAbsolute(glm::vec3(pos) + glm::vec3(0.8f, 3.5f, 0.0f));
			this->in0->moveAbsolute(pos + glm::ivec3(0, 0, 1));
			this->in1->moveAbsolute(pos + glm::ivec3(1, 0, 1));
			this->in2->moveAbsolute(pos + glm::ivec3(2, 0, 1));
			this->in3->moveAbsolute(pos + glm::ivec3(3, 0, 1));

			float angle = 1.5707963267948966f * rotation;
			this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));
			this->segA->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
			this->segB->rotateByPointAbsolute(angle, glm::vec3(-0.2f, 0.0f, 0.5f));
			this->segC->rotateByPointAbsolute(angle, glm::vec3(-0.2f, 0.0f, 0.5f));
			this->segD->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
			this->segE->rotateByPointAbsolute(angle, glm::vec3(-2.8f, 0.0f, 0.5f));
			this->segF->rotateByPointAbsolute(angle, glm::vec3(-2.8f, 0.0f, 0.5f));
			this->segG->rotateByPointAbsolute(angle, glm::vec3(-0.3f, 0.0f, 0.5f));
			this->in0->rotateByPointAbsolute(angle, glm::vec3( 0.5f, 0.0f, -0.5f));
			this->in1->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
			this->in2->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, -0.5f));
			this->in3->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, -0.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip11;
		Pos chip12;
		Pos chip13;
		Pos chip14;
		Pos chip15;
		Pos chip16;
		Pos chip17;
		Pos chip21;
		Pos chip22;
		Pos chip23;
		Pos chip24;
		Pos chip25;
		Pos chip26;
		Pos chip27;
		Pos chip31;
		Pos chip32;
		Pos chip33;
		Pos chip34;
		Pos chip35;
		Pos chip36;
		Pos chip37;
		Pos chip41;
		Pos chip42;
		Pos chip43;
		Pos chip44;
		Pos chip45;
		Pos chip46;
		Pos chip47;

		Pos led11;
		Pos led12;
		Pos led13;
		Pos led14;
		Pos led15;
		Pos led16;
		Pos led17;
		Pos led21;
		Pos led22;
		Pos led23;
		Pos led24;
		Pos led25;
		Pos led26;
		Pos led27;
		Pos led31;
		Pos led32;
		Pos led33;
		Pos led34;
		Pos led35;
		Pos led36;
		Pos led37;
		Pos led41;
		Pos led42;
		Pos led43;
		Pos led44;
		Pos led45;
		Pos led46;
		Pos led47;

		Pos in1;
		Pos in2;
		Pos in3;
		Pos in4;


		// pukty do sprawdzenia
		if (this->rotation == 0) {
			chip11 = { pos + glm::ivec3(0, 0, 0) };
			chip12 = { pos + glm::ivec3(0, 1, 0) };
			chip13 = { pos + glm::ivec3(0, 2, 0) };
			chip14 = { pos + glm::ivec3(0, 3, 0) };
			chip15 = { pos + glm::ivec3(0, 4, 0) };
			chip16 = { pos + glm::ivec3(0, 5, 0) };
			chip17 = { pos + glm::ivec3(0, 6, 0) };
			chip21 = { pos + glm::ivec3(1, 0, 0) };
			chip22 = { pos + glm::ivec3(1, 1, 0) };
			chip23 = { pos + glm::ivec3(1, 2, 0) };
			chip24 = { pos + glm::ivec3(1, 3, 0) };
			chip25 = { pos + glm::ivec3(1, 4, 0) };
			chip26 = { pos + glm::ivec3(1, 5, 0) };
			chip27 = { pos + glm::ivec3(1, 6, 0) };
			chip31 = { pos + glm::ivec3(2, 0, 0) };
			chip32 = { pos + glm::ivec3(2, 1, 0) };
			chip33 = { pos + glm::ivec3(2, 2, 0) };
			chip34 = { pos + glm::ivec3(2, 3, 0) };
			chip35 = { pos + glm::ivec3(2, 4, 0) };
			chip36 = { pos + glm::ivec3(2, 5, 0) };
			chip37 = { pos + glm::ivec3(2, 6, 0) };
			chip41 = { pos + glm::ivec3(3, 0, 0) };
			chip42 = { pos + glm::ivec3(3, 1, 0) };
			chip43 = { pos + glm::ivec3(3, 2, 0) };
			chip44 = { pos + glm::ivec3(3, 3, 0) };
			chip45 = { pos + glm::ivec3(3, 4, 0) };
			chip46 = { pos + glm::ivec3(3, 5, 0) };
			chip47 = { pos + glm::ivec3(3, 6, 0) };

			led11 = { pos + glm::ivec3(0, 0, -1) };
			led12 = { pos + glm::ivec3(0, 1, -1) };
			led13 = { pos + glm::ivec3(0, 2, -1) };
			led14 = { pos + glm::ivec3(0, 3, -1) };
			led15 = { pos + glm::ivec3(0, 4, -1) };
			led16 = { pos + glm::ivec3(0, 5, -1) };
			led17 = { pos + glm::ivec3(0, 6, -1) };
			led21 = { pos + glm::ivec3(1, 0, -1) };
			led22 = { pos + glm::ivec3(1, 1, -1) };
			led23 = { pos + glm::ivec3(1, 2, -1) };
			led24 = { pos + glm::ivec3(1, 3, -1) };
			led25 = { pos + glm::ivec3(1, 4, -1) };
			led26 = { pos + glm::ivec3(1, 5, -1) };
			led27 = { pos + glm::ivec3(1, 6, -1) };
			led31 = { pos + glm::ivec3(2, 0, -1) };
			led32 = { pos + glm::ivec3(2, 1, -1) };
			led33 = { pos + glm::ivec3(2, 2, -1) };
			led34 = { pos + glm::ivec3(2, 3, -1) };
			led35 = { pos + glm::ivec3(2, 4, -1) };
			led36 = { pos + glm::ivec3(2, 5, -1) };
			led37 = { pos + glm::ivec3(2, 6, -1) };
			led41 = { pos + glm::ivec3(3, 0, -1) };
			led42 = { pos + glm::ivec3(3, 1, -1) };
			led43 = { pos + glm::ivec3(3, 2, -1) };
			led44 = { pos + glm::ivec3(3, 3, -1) };
			led45 = { pos + glm::ivec3(3, 4, -1) };
			led46 = { pos + glm::ivec3(3, 5, -1) };
			led47 = { pos + glm::ivec3(3, 6, -1) };

			in1 = { pos + glm::ivec3(0,  0, 1) };
			in2 = { pos + glm::ivec3(1,  0, 1) };
			in3 = { pos + glm::ivec3(2,  0, 1) };
			in4 = { pos + glm::ivec3(3,  0, 1) };
		}
		else if (this->rotation == 1) {
			chip11 = { pos + glm::ivec3(0, 0,  0) };
			chip12 = { pos + glm::ivec3(0, 1,  0) };
			chip13 = { pos + glm::ivec3(0, 2,  0) };
			chip14 = { pos + glm::ivec3(0, 3,  0) };
			chip15 = { pos + glm::ivec3(0, 4,  0) };
			chip16 = { pos + glm::ivec3(0, 5,  0) };
			chip17 = { pos + glm::ivec3(0, 6,  0) };
			chip21 = { pos + glm::ivec3(0, 0, -1) };
			chip22 = { pos + glm::ivec3(0, 1, -1) };
			chip23 = { pos + glm::ivec3(0, 2, -1) };
			chip24 = { pos + glm::ivec3(0, 3, -1) };
			chip25 = { pos + glm::ivec3(0, 4, -1) };
			chip26 = { pos + glm::ivec3(0, 5, -1) };
			chip27 = { pos + glm::ivec3(0, 6, -1) };
			chip31 = { pos + glm::ivec3(0, 0, -2) };
			chip32 = { pos + glm::ivec3(0, 1, -2) };
			chip33 = { pos + glm::ivec3(0, 2, -2) };
			chip34 = { pos + glm::ivec3(0, 3, -2) };
			chip35 = { pos + glm::ivec3(0, 4, -2) };
			chip36 = { pos + glm::ivec3(0, 5, -2) };
			chip37 = { pos + glm::ivec3(0, 6, -2) };
			chip41 = { pos + glm::ivec3(0, 0, -3) };
			chip42 = { pos + glm::ivec3(0, 1, -3) };
			chip43 = { pos + glm::ivec3(0, 2, -3) };
			chip44 = { pos + glm::ivec3(0, 3, -3) };
			chip45 = { pos + glm::ivec3(0, 4, -3) };
			chip46 = { pos + glm::ivec3(0, 5, -3) };
			chip47 = { pos + glm::ivec3(0, 6, -3) };

			led11 = { pos + glm::ivec3(-1, 0,  0) };
			led12 = { pos + glm::ivec3(-1, 1,  0) };
			led13 = { pos + glm::ivec3(-1, 2,  0) };
			led14 = { pos + glm::ivec3(-1, 3,  0) };
			led15 = { pos + glm::ivec3(-1, 4,  0) };
			led16 = { pos + glm::ivec3(-1, 5,  0) };
			led17 = { pos + glm::ivec3(-1, 6,  0) };
			led21 = { pos + glm::ivec3(-1, 0, -1) };
			led22 = { pos + glm::ivec3(-1, 1, -1) };
			led23 = { pos + glm::ivec3(-1, 2, -1) };
			led24 = { pos + glm::ivec3(-1, 3, -1) };
			led25 = { pos + glm::ivec3(-1, 4, -1) };
			led26 = { pos + glm::ivec3(-1, 5, -1) };
			led27 = { pos + glm::ivec3(-1, 6, -1) };
			led31 = { pos + glm::ivec3(-1, 0, -2) };
			led32 = { pos + glm::ivec3(-1, 1, -2) };
			led33 = { pos + glm::ivec3(-1, 2, -2) };
			led34 = { pos + glm::ivec3(-1, 3, -2) };
			led35 = { pos + glm::ivec3(-1, 4, -2) };
			led36 = { pos + glm::ivec3(-1, 5, -2) };
			led37 = { pos + glm::ivec3(-1, 6, -2) };
			led41 = { pos + glm::ivec3(-1, 0, -3) };
			led42 = { pos + glm::ivec3(-1, 1, -3) };
			led43 = { pos + glm::ivec3(-1, 2, -3) };
			led44 = { pos + glm::ivec3(-1, 3, -3) };
			led45 = { pos + glm::ivec3(-1, 4, -3) };
			led46 = { pos + glm::ivec3(-1, 5, -3) };
			led47 = { pos + glm::ivec3(-1, 6, -3) };

			in1 = { pos + glm::ivec3(1,  0,  0) };
			in2 = { pos + glm::ivec3(1,  0, -1) };
			in3 = { pos + glm::ivec3(1,  0, -2) };
			in4 = { pos + glm::ivec3(1,  0, -3) };
		}
		else if (this->rotation == 2) {
			chip11 = { pos + glm::ivec3( 0, 0, 0) };
			chip12 = { pos + glm::ivec3( 0, 1, 0) };
			chip13 = { pos + glm::ivec3( 0, 2, 0) };
			chip14 = { pos + glm::ivec3( 0, 3, 0) };
			chip15 = { pos + glm::ivec3( 0, 4, 0) };
			chip16 = { pos + glm::ivec3( 0, 5, 0) };
			chip17 = { pos + glm::ivec3( 0, 6, 0) };
			chip21 = { pos + glm::ivec3(-1, 0, 0) };
			chip22 = { pos + glm::ivec3(-1, 1, 0) };
			chip23 = { pos + glm::ivec3(-1, 2, 0) };
			chip24 = { pos + glm::ivec3(-1, 3, 0) };
			chip25 = { pos + glm::ivec3(-1, 4, 0) };
			chip26 = { pos + glm::ivec3(-1, 5, 0) };
			chip27 = { pos + glm::ivec3(-1, 6, 0) };
			chip31 = { pos + glm::ivec3(-2, 0, 0) };
			chip32 = { pos + glm::ivec3(-2, 1, 0) };
			chip33 = { pos + glm::ivec3(-2, 2, 0) };
			chip34 = { pos + glm::ivec3(-2, 3, 0) };
			chip35 = { pos + glm::ivec3(-2, 4, 0) };
			chip36 = { pos + glm::ivec3(-2, 5, 0) };
			chip37 = { pos + glm::ivec3(-2, 6, 0) };
			chip41 = { pos + glm::ivec3(-3, 0, 0) };
			chip42 = { pos + glm::ivec3(-3, 1, 0) };
			chip43 = { pos + glm::ivec3(-3, 2, 0) };
			chip44 = { pos + glm::ivec3(-3, 3, 0) };
			chip45 = { pos + glm::ivec3(-3, 4, 0) };
			chip46 = { pos + glm::ivec3(-3, 5, 0) };
			chip47 = { pos + glm::ivec3(-3, 6, 0) };

			led11 = { pos + glm::ivec3( 0, 0, 1) };
			led12 = { pos + glm::ivec3( 0, 1, 1) };
			led13 = { pos + glm::ivec3( 0, 2, 1) };
			led14 = { pos + glm::ivec3( 0, 3, 1) };
			led15 = { pos + glm::ivec3( 0, 4, 1) };
			led16 = { pos + glm::ivec3( 0, 5, 1) };
			led17 = { pos + glm::ivec3( 0, 6, 1) };
			led21 = { pos + glm::ivec3(-1, 0, 1) };
			led22 = { pos + glm::ivec3(-1, 1, 1) };
			led23 = { pos + glm::ivec3(-1, 2, 1) };
			led24 = { pos + glm::ivec3(-1, 3, 1) };
			led25 = { pos + glm::ivec3(-1, 4, 1) };
			led26 = { pos + glm::ivec3(-1, 5, 1) };
			led27 = { pos + glm::ivec3(-1, 6, 1) };
			led31 = { pos + glm::ivec3(-2, 0, 1) };
			led32 = { pos + glm::ivec3(-2, 1, 1) };
			led33 = { pos + glm::ivec3(-2, 2, 1) };
			led34 = { pos + glm::ivec3(-2, 3, 1) };
			led35 = { pos + glm::ivec3(-2, 4, 1) };
			led36 = { pos + glm::ivec3(-2, 5, 1) };
			led37 = { pos + glm::ivec3(-2, 6, 1) };
			led41 = { pos + glm::ivec3(-3, 0, 1) };
			led42 = { pos + glm::ivec3(-3, 1, 1) };
			led43 = { pos + glm::ivec3(-3, 2, 1) };
			led44 = { pos + glm::ivec3(-3, 3, 1) };
			led45 = { pos + glm::ivec3(-3, 4, 1) };
			led46 = { pos + glm::ivec3(-3, 5, 1) };
			led47 = { pos + glm::ivec3(-3, 6, 1) };

			in1 = { pos + glm::ivec3( 0,  0, -1) };
			in2 = { pos + glm::ivec3(-1,  0, -1) };
			in3 = { pos + glm::ivec3(-2,  0, -1) };
			in4 = { pos + glm::ivec3(-3,  0, -1) };
		}
		else if (this->rotation == 3) {
			chip11 = { pos + glm::ivec3(0, 0, 0) };
			chip12 = { pos + glm::ivec3(0, 1, 0) };
			chip13 = { pos + glm::ivec3(0, 2, 0) };
			chip14 = { pos + glm::ivec3(0, 3, 0) };
			chip15 = { pos + glm::ivec3(0, 4, 0) };
			chip16 = { pos + glm::ivec3(0, 5, 0) };
			chip17 = { pos + glm::ivec3(0, 6, 0) };
			chip21 = { pos + glm::ivec3(0, 0, 1) };
			chip22 = { pos + glm::ivec3(0, 1, 1) };
			chip23 = { pos + glm::ivec3(0, 2, 1) };
			chip24 = { pos + glm::ivec3(0, 3, 1) };
			chip25 = { pos + glm::ivec3(0, 4, 1) };
			chip26 = { pos + glm::ivec3(0, 5, 1) };
			chip27 = { pos + glm::ivec3(0, 6, 1) };
			chip31 = { pos + glm::ivec3(0, 0, 2) };
			chip32 = { pos + glm::ivec3(0, 1, 2) };
			chip33 = { pos + glm::ivec3(0, 2, 2) };
			chip34 = { pos + glm::ivec3(0, 3, 2) };
			chip35 = { pos + glm::ivec3(0, 4, 2) };
			chip36 = { pos + glm::ivec3(0, 5, 2) };
			chip37 = { pos + glm::ivec3(0, 6, 2) };
			chip41 = { pos + glm::ivec3(0, 0, 3) };
			chip42 = { pos + glm::ivec3(0, 1, 3) };
			chip43 = { pos + glm::ivec3(0, 2, 3) };
			chip44 = { pos + glm::ivec3(0, 3, 3) };
			chip45 = { pos + glm::ivec3(0, 4, 3) };
			chip46 = { pos + glm::ivec3(0, 5, 3) };
			chip47 = { pos + glm::ivec3(0, 6, 3) };

			led11 = { pos + glm::ivec3(1, 0, 0) };
			led12 = { pos + glm::ivec3(1, 1, 0) };
			led13 = { pos + glm::ivec3(1, 2, 0) };
			led14 = { pos + glm::ivec3(1, 3, 0) };
			led15 = { pos + glm::ivec3(1, 4, 0) };
			led16 = { pos + glm::ivec3(1, 5, 0) };
			led17 = { pos + glm::ivec3(1, 6, 0) };
			led21 = { pos + glm::ivec3(1, 0, 1) };
			led22 = { pos + glm::ivec3(1, 1, 1) };
			led23 = { pos + glm::ivec3(1, 2, 1) };
			led24 = { pos + glm::ivec3(1, 3, 1) };
			led25 = { pos + glm::ivec3(1, 4, 1) };
			led26 = { pos + glm::ivec3(1, 5, 1) };
			led27 = { pos + glm::ivec3(1, 6, 1) };
			led31 = { pos + glm::ivec3(1, 0, 2) };
			led32 = { pos + glm::ivec3(1, 1, 2) };
			led33 = { pos + glm::ivec3(1, 2, 2) };
			led34 = { pos + glm::ivec3(1, 3, 2) };
			led35 = { pos + glm::ivec3(1, 4, 2) };
			led36 = { pos + glm::ivec3(1, 5, 2) };
			led37 = { pos + glm::ivec3(1, 6, 2) };
			led41 = { pos + glm::ivec3(1, 0, 3) };
			led42 = { pos + glm::ivec3(1, 1, 3) };
			led43 = { pos + glm::ivec3(1, 2, 3) };
			led44 = { pos + glm::ivec3(1, 3, 3) };
			led45 = { pos + glm::ivec3(1, 4, 3) };
			led46 = { pos + glm::ivec3(1, 5, 3) };
			led47 = { pos + glm::ivec3(1, 6, 3) };

			in1 = { pos + glm::ivec3(-1,  0, 0) };
			in2 = { pos + glm::ivec3(-1,  0, 1) };
			in3 = { pos + glm::ivec3(-1,  0, 2) };
			in4 = { pos + glm::ivec3(-1,  0, 3) };
		}
		else {
			return false;
		}


		// szukanie
		void* in1Ptr = NULL;
		void* in2Ptr = NULL;
		void* in3Ptr = NULL;
		void* in4Ptr = NULL;
		if (this->foundSomething(map, &chip11)) { return false; }
		if (this->foundSomething(map, &chip12)) { return false; }
		if (this->foundSomething(map, &chip13)) { return false; }
		if (this->foundSomething(map, &chip14)) { return false; }
		if (this->foundSomething(map, &chip15)) { return false; }
		if (this->foundSomething(map, &chip16)) { return false; }
		if (this->foundSomething(map, &chip17)) { return false; }
		if (this->foundSomething(map, &chip21)) { return false; }
		if (this->foundSomething(map, &chip22)) { return false; }
		if (this->foundSomething(map, &chip23)) { return false; }
		if (this->foundSomething(map, &chip24)) { return false; }
		if (this->foundSomething(map, &chip25)) { return false; }
		if (this->foundSomething(map, &chip26)) { return false; }
		if (this->foundSomething(map, &chip27)) { return false; }
		if (this->foundSomething(map, &chip31)) { return false; }
		if (this->foundSomething(map, &chip32)) { return false; }
		if (this->foundSomething(map, &chip33)) { return false; }
		if (this->foundSomething(map, &chip34)) { return false; }
		if (this->foundSomething(map, &chip35)) { return false; }
		if (this->foundSomething(map, &chip36)) { return false; }
		if (this->foundSomething(map, &chip37)) { return false; }
		if (this->foundSomething(map, &chip41)) { return false; }
		if (this->foundSomething(map, &chip42)) { return false; }
		if (this->foundSomething(map, &chip43)) { return false; }
		if (this->foundSomething(map, &chip44)) { return false; }
		if (this->foundSomething(map, &chip45)) { return false; }
		if (this->foundSomething(map, &chip46)) { return false; }
		if (this->foundSomething(map, &chip47)) { return false; }
		if (this->foundSomething(map, &led11)) { return false; }
		if (this->foundSomething(map, &led12)) { return false; }
		if (this->foundSomething(map, &led13)) { return false; }
		if (this->foundSomething(map, &led14)) { return false; }
		if (this->foundSomething(map, &led15)) { return false; }
		if (this->foundSomething(map, &led16)) { return false; }
		if (this->foundSomething(map, &led17)) { return false; }
		if (this->foundSomething(map, &led21)) { return false; }
		if (this->foundSomething(map, &led22)) { return false; }
		if (this->foundSomething(map, &led23)) { return false; }
		if (this->foundSomething(map, &led24)) { return false; }
		if (this->foundSomething(map, &led25)) { return false; }
		if (this->foundSomething(map, &led26)) { return false; }
		if (this->foundSomething(map, &led27)) { return false; }
		if (this->foundSomething(map, &led31)) { return false; }
		if (this->foundSomething(map, &led32)) { return false; }
		if (this->foundSomething(map, &led33)) { return false; }
		if (this->foundSomething(map, &led34)) { return false; }
		if (this->foundSomething(map, &led35)) { return false; }
		if (this->foundSomething(map, &led36)) { return false; }
		if (this->foundSomething(map, &led37)) { return false; }
		if (this->foundSomething(map, &led41)) { return false; }
		if (this->foundSomething(map, &led42)) { return false; }
		if (this->foundSomething(map, &led43)) { return false; }
		if (this->foundSomething(map, &led44)) { return false; }
		if (this->foundSomething(map, &led45)) { return false; }
		if (this->foundSomething(map, &led46)) { return false; }
		if (this->foundSomething(map, &led47)) { return false; }
		if (!this->foundWire(map, &in1, &in1Ptr)) { return false; }
		if (!this->foundWire(map, &in2, &in2Ptr)) { return false; }
		if (!this->foundWire(map, &in3, &in3Ptr)) { return false; }
		if (!this->foundWire(map, &in4, &in4Ptr)) { return false; }


		// jesli mo¿na stworzyc
		std::vector<What> c11{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c12{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c13{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c14{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c15{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c16{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c17{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c21{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c22{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c23{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c24{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c25{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c26{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c27{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c31{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c32{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c33{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c34{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c35{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c36{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c37{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c41{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c42{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c43{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c44{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c45{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c46{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> c47{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l11{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l12{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l13{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l14{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l15{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l16{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l17{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l21{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l22{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l23{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l24{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l25{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l26{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l27{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l31{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l32{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l33{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l34{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l35{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l36{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l37{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l41{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l42{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l43{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l44{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l45{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l46{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> l47{ What{ "chip 7SEGMENT4BIT", this } };
		std::vector<What> i1{ What{ "input", this->in0 } };
		std::vector<What> i2{ What{ "input", this->in1 } };
		std::vector<What> i3{ What{ "input", this->in2 } };
		std::vector<What> i4{ What{ "input", this->in3 } };
		if (in1Ptr != NULL) {
			i1.push_back(What{ "wire", in1Ptr });
			((Wire*)in1Ptr)->outputs.push_back(this->in0);
		}
		if (in2Ptr != NULL) {
			i2.push_back(What{ "wire", in2Ptr });
			((Wire*)in2Ptr)->outputs.push_back(this->in1);
		}
		if (in3Ptr != NULL) {
			i3.push_back(What{ "wire", in3Ptr });
			((Wire*)in3Ptr)->outputs.push_back(this->in2);
		}
		if (in4Ptr != NULL) {
			i4.push_back(What{ "wire", in4Ptr });
			((Wire*)in4Ptr)->outputs.push_back(this->in3);
		}
		map->insert_or_assign(chip11, c11);
		map->insert_or_assign(chip12, c12);
		map->insert_or_assign(chip13, c13);
		map->insert_or_assign(chip14, c14);
		map->insert_or_assign(chip15, c15);
		map->insert_or_assign(chip16, c16);
		map->insert_or_assign(chip17, c17);
		map->insert_or_assign(chip21, c21);
		map->insert_or_assign(chip22, c22);
		map->insert_or_assign(chip23, c23);
		map->insert_or_assign(chip24, c24);
		map->insert_or_assign(chip25, c25);
		map->insert_or_assign(chip26, c26);
		map->insert_or_assign(chip27, c27);
		map->insert_or_assign(chip31, c31);
		map->insert_or_assign(chip32, c32);
		map->insert_or_assign(chip33, c33);
		map->insert_or_assign(chip34, c34);
		map->insert_or_assign(chip35, c35);
		map->insert_or_assign(chip36, c36);
		map->insert_or_assign(chip37, c37);
		map->insert_or_assign(chip41, c41);
		map->insert_or_assign(chip42, c42);
		map->insert_or_assign(chip43, c43);
		map->insert_or_assign(chip44, c44);
		map->insert_or_assign(chip45, c45);
		map->insert_or_assign(chip46, c46);
		map->insert_or_assign(chip47, c47);
		map->insert_or_assign(led11, l11);
		map->insert_or_assign(led12, l12);
		map->insert_or_assign(led13, l13);
		map->insert_or_assign(led14, l14);
		map->insert_or_assign(led15, l15);
		map->insert_or_assign(led16, l16);
		map->insert_or_assign(led17, l17);
		map->insert_or_assign(led21, l21);
		map->insert_or_assign(led22, l22);
		map->insert_or_assign(led23, l23);
		map->insert_or_assign(led24, l24);
		map->insert_or_assign(led25, l25);
		map->insert_or_assign(led26, l26);
		map->insert_or_assign(led27, l27);
		map->insert_or_assign(led31, l31);
		map->insert_or_assign(led32, l32);
		map->insert_or_assign(led33, l33);
		map->insert_or_assign(led34, l34);
		map->insert_or_assign(led35, l35);
		map->insert_or_assign(led36, l36);
		map->insert_or_assign(led37, l37);
		map->insert_or_assign(led41, l41);
		map->insert_or_assign(led42, l42);
		map->insert_or_assign(led43, l43);
		map->insert_or_assign(led44, l44);
		map->insert_or_assign(led45, l45);
		map->insert_or_assign(led46, l46);
		map->insert_or_assign(led47, l47);
		map->insert_or_assign(in1, i1);
		map->insert_or_assign(in2, i2);
		map->insert_or_assign(in3, i3);
		map->insert_or_assign(in4, i4);
		return true;
	}

	void update() {
		int res = 0;
		if (this->in3->state) {
			res = res + 1;
		}
		if (this->in2->state) {
			res = res + 2;
		}
		if (this->in1->state) {
			res = res + 4;
		}
		if (this->in0->state) {
			res = res + 8;
		}
		
		if (res == 0) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLORON;
			this->segF->color = COLORON;
			this->segG->color = COLOROFF;
		}
		else if (res == 1) {
			this->segA->color = COLOROFF;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 2) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLOROFF;
			this->segD->color = COLORON;
			this->segE->color = COLORON;
			this->segF->color = COLOROFF;
			this->segG->color = COLORON;
		}
		else if (res == 3) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLORON;
		}
		else if (res == 4) {
			this->segA->color = COLOROFF;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLORON;
			this->segG->color = COLORON;
		}
		else if (res == 5) {
			this->segA->color = COLORON;
			this->segB->color = COLOROFF;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLOROFF;
			this->segF->color = COLORON;
			this->segG->color = COLORON;
		}
		else if (res == 6) {
			this->segA->color = COLORON;
			this->segB->color = COLOROFF;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLORON;
			this->segF->color = COLORON;
			this->segG->color = COLORON;
		}
		else if (res == 7) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 8) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLORON;
			this->segF->color = COLORON;
			this->segG->color = COLORON;
		}
		else if (res == 9) {
			this->segA->color = COLORON;
			this->segB->color = COLORON;
			this->segC->color = COLORON;
			this->segD->color = COLORON;
			this->segE->color = COLOROFF;
			this->segF->color = COLORON;
			this->segG->color = COLORON;
		}
		else if (res == 10) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 11) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 12) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 13) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 14) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}
		else if (res == 15) {
			this->segA->color = COLOROFF;
			this->segB->color = COLOROFF;
			this->segC->color = COLOROFF;
			this->segD->color = COLOROFF;
			this->segE->color = COLOROFF;
			this->segF->color = COLOROFF;
			this->segG->color = COLOROFF;
		}

	}

	void draw() {
		this->chip->draw();

		this->segA->draw();
		this->segB->draw();
		this->segC->draw();
		this->segD->draw();
		this->segE->draw();
		this->segF->draw();
		this->segG->draw();

		this->in0->draw();
		this->in1->draw();
		this->in2->draw();
		this->in3->draw();
	}

	~Gate7SEGMENT4BIT() {
		delete this->chip;
		delete this->segA;
		delete this->segB;
		delete this->segC;
		delete this->segD;
		delete this->segE;
		delete this->segF;
		delete this->segG;

		delete this->in0;
		delete this->in1;
		delete this->in2;
		delete this->in3;
	}
};