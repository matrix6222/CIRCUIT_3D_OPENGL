class GateADDER8BIT : public Gate {
private:
	Model* chip;

	Input* a0;
	Input* a1;
	Input* a2;
	Input* a3;
	Input* a4;
	Input* a5;
	Input* a6;
	Input* a7;

	Input* b0;
	Input* b1;
	Input* b2;
	Input* b3;
	Input* b4;
	Input* b5;
	Input* b6;
	Input* b7;

	Output* o0;
	Output* o1;
	Output* o2;
	Output* o3;
	Output* o4;
	Output* o5;
	Output* o6;
	Output* o7;

	Input* cin;
	Output* cout;

	glm::ivec3 oldPos;
	int oldRotation;
public:
	glm::ivec3 pos;
	int rotation;

	GateADDER8BIT(glm::ivec3 pos, int rotation) {
		this->chip = new Model("Models3D/chipADDER8BIT/model.obj", glm::vec3(0.1f, 0.1f, 0.1f));

		this->a0 = new Input();
		this->a1 = new Input();
		this->a2 = new Input();
		this->a3 = new Input();
		this->a4 = new Input();
		this->a5 = new Input();
		this->a6 = new Input();
		this->a7 = new Input();

		this->b0 = new Input();
		this->b1 = new Input();
		this->b2 = new Input();
		this->b3 = new Input();
		this->b4 = new Input();
		this->b5 = new Input();
		this->b6 = new Input();
		this->b7 = new Input();

		this->o0 = new Output();
		this->o1 = new Output();
		this->o2 = new Output();
		this->o3 = new Output();
		this->o4 = new Output();
		this->o5 = new Output();
		this->o6 = new Output();
		this->o7 = new Output();

		this->cin = new Input();
		this->cout = new Output();

		this->pos = pos;
		this->rotation = rotation;

		this->chip->moveAbsolute(glm::vec3(pos));
		this->cin->moveAbsolute(pos + glm::ivec3(0, 0, 1));
		this->a0->moveAbsolute(pos + glm::ivec3(1, 0, 1));
		this->a1->moveAbsolute(pos + glm::ivec3(2, 0, 1));
		this->a2->moveAbsolute(pos + glm::ivec3(3, 0, 1));
		this->a3->moveAbsolute(pos + glm::ivec3(4, 0, 1));
		this->a4->moveAbsolute(pos + glm::ivec3(5, 0, 1));
		this->a5->moveAbsolute(pos + glm::ivec3(6, 0, 1));
		this->a6->moveAbsolute(pos + glm::ivec3(7, 0, 1));
		this->a7->moveAbsolute(pos + glm::ivec3(8, 0, 1));
		this->b0->moveAbsolute(pos + glm::ivec3(9, 0, 1));
		this->b1->moveAbsolute(pos + glm::ivec3(10, 0, 1));
		this->b2->moveAbsolute(pos + glm::ivec3(11, 0, 1));
		this->b3->moveAbsolute(pos + glm::ivec3(12, 0, 1));
		this->b4->moveAbsolute(pos + glm::ivec3(13, 0, 1));
		this->b5->moveAbsolute(pos + glm::ivec3(14, 0, 1));
		this->b6->moveAbsolute(pos + glm::ivec3(15, 0, 1));
		this->b7->moveAbsolute(pos + glm::ivec3(16, 0, 1));

		this->o0->moveAbsolute(pos + glm::ivec3(1, 0, -1));
		this->o1->moveAbsolute(pos + glm::ivec3(2, 0, -1));
		this->o2->moveAbsolute(pos + glm::ivec3(3, 0, -1));
		this->o3->moveAbsolute(pos + glm::ivec3(4, 0, -1));
		this->o4->moveAbsolute(pos + glm::ivec3(5, 0, -1));
		this->o5->moveAbsolute(pos + glm::ivec3(6, 0, -1));
		this->o6->moveAbsolute(pos + glm::ivec3(7, 0, -1));
		this->o7->moveAbsolute(pos + glm::ivec3(8, 0, -1));
		this->cout->moveAbsolute(pos + glm::ivec3(16, 0, -1));

		float angle = 1.5707963267948966f * rotation;

		this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, 0.5f));

		this->cin->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f, -0.5f));
		this->a0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, -0.5f));
		this->a1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, -0.5f));
		this->a2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, -0.5f));
		this->a3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, -0.5f));
		this->a4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, -0.5f));
		this->a5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, -0.5f));
		this->a6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, -0.5f));
		this->a7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, -0.5f));
		this->b0->rotateByPointAbsolute(angle, glm::vec3(-8.5f, 0.0f, -0.5f));
		this->b1->rotateByPointAbsolute(angle, glm::vec3(-9.5f, 0.0f, -0.5f));
		this->b2->rotateByPointAbsolute(angle, glm::vec3(-10.5f, 0.0f, -0.5f));
		this->b3->rotateByPointAbsolute(angle, glm::vec3(-11.5f, 0.0f, -0.5f));
		this->b4->rotateByPointAbsolute(angle, glm::vec3(-12.5f, 0.0f, -0.5f));
		this->b5->rotateByPointAbsolute(angle, glm::vec3(-13.5f, 0.0f, -0.5f));
		this->b6->rotateByPointAbsolute(angle, glm::vec3(-14.5f, 0.0f, -0.5f));
		this->b7->rotateByPointAbsolute(angle, glm::vec3(-15.5f, 0.0f, -0.5f));

		this->o0->rotateByPointAbsolute(angle, glm::vec3(-0.5f, 0.0f, 1.5f));
		this->o1->rotateByPointAbsolute(angle, glm::vec3(-1.5f, 0.0f, 1.5f));
		this->o2->rotateByPointAbsolute(angle, glm::vec3(-2.5f, 0.0f, 1.5f));
		this->o3->rotateByPointAbsolute(angle, glm::vec3(-3.5f, 0.0f, 1.5f));
		this->o4->rotateByPointAbsolute(angle, glm::vec3(-4.5f, 0.0f, 1.5f));
		this->o5->rotateByPointAbsolute(angle, glm::vec3(-5.5f, 0.0f, 1.5f));
		this->o6->rotateByPointAbsolute(angle, glm::vec3(-6.5f, 0.0f, 1.5f));
		this->o7->rotateByPointAbsolute(angle, glm::vec3(-7.5f, 0.0f, 1.5f));
		this->cout->rotateByPointAbsolute(angle, glm::vec3(-15.5f, 0.0f, 1.5f));

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}

	void moveAbsolute(glm::ivec3 pos, int rotation) {
		this->pos = pos;
		this->rotation = rotation;

		if (this->oldRotation != this->rotation || this->oldPos != this->pos) {
			this->chip->moveAbsolute(glm::vec3(pos));
			this->cin->moveAbsolute(pos  + glm::ivec3( 0, 0, 1));
			this->a0->moveAbsolute(pos   + glm::ivec3( 1, 0, 1));
			this->a1->moveAbsolute(pos   + glm::ivec3( 2, 0, 1));
			this->a2->moveAbsolute(pos   + glm::ivec3( 3, 0, 1));
			this->a3->moveAbsolute(pos   + glm::ivec3( 4, 0, 1));
			this->a4->moveAbsolute(pos   + glm::ivec3( 5, 0, 1));
			this->a5->moveAbsolute(pos   + glm::ivec3( 6, 0, 1));
			this->a6->moveAbsolute(pos   + glm::ivec3( 7, 0, 1));
			this->a7->moveAbsolute(pos   + glm::ivec3( 8, 0, 1));
			this->b0->moveAbsolute(pos   + glm::ivec3( 9, 0, 1));
			this->b1->moveAbsolute(pos   + glm::ivec3(10, 0, 1));
			this->b2->moveAbsolute(pos   + glm::ivec3(11, 0, 1));
			this->b3->moveAbsolute(pos   + glm::ivec3(12, 0, 1));
			this->b4->moveAbsolute(pos   + glm::ivec3(13, 0, 1));
			this->b5->moveAbsolute(pos   + glm::ivec3(14, 0, 1));
			this->b6->moveAbsolute(pos   + glm::ivec3(15, 0, 1));
			this->b7->moveAbsolute(pos   + glm::ivec3(16, 0, 1));

			this->o0->moveAbsolute(pos   + glm::ivec3( 1, 0, -1));
			this->o1->moveAbsolute(pos   + glm::ivec3( 2, 0, -1));
			this->o2->moveAbsolute(pos   + glm::ivec3( 3, 0, -1));
			this->o3->moveAbsolute(pos   + glm::ivec3( 4, 0, -1));
			this->o4->moveAbsolute(pos   + glm::ivec3( 5, 0, -1));
			this->o5->moveAbsolute(pos   + glm::ivec3( 6, 0, -1));
			this->o6->moveAbsolute(pos   + glm::ivec3( 7, 0, -1));
			this->o7->moveAbsolute(pos   + glm::ivec3( 8, 0, -1));
			this->cout->moveAbsolute(pos + glm::ivec3(16, 0, -1));

			float angle = 1.5707963267948966f * rotation;

			this->chip->rotateByPointAbsolute(angle, glm::vec3(0.5f, 0.0f,  0.5f));

			this->cin->rotateByPointAbsolute(angle,  glm::vec3(  0.5f, 0.0f, -0.5f));
			this->a0->rotateByPointAbsolute(angle,   glm::vec3( -0.5f, 0.0f, -0.5f));
			this->a1->rotateByPointAbsolute(angle,   glm::vec3( -1.5f, 0.0f, -0.5f));
			this->a2->rotateByPointAbsolute(angle,   glm::vec3( -2.5f, 0.0f, -0.5f));
			this->a3->rotateByPointAbsolute(angle,   glm::vec3( -3.5f, 0.0f, -0.5f));
			this->a4->rotateByPointAbsolute(angle,   glm::vec3( -4.5f, 0.0f, -0.5f));
			this->a5->rotateByPointAbsolute(angle,   glm::vec3( -5.5f, 0.0f, -0.5f));
			this->a6->rotateByPointAbsolute(angle,   glm::vec3( -6.5f, 0.0f, -0.5f));
			this->a7->rotateByPointAbsolute(angle,   glm::vec3( -7.5f, 0.0f, -0.5f));
			this->b0->rotateByPointAbsolute(angle,   glm::vec3( -8.5f, 0.0f, -0.5f));
			this->b1->rotateByPointAbsolute(angle,   glm::vec3( -9.5f, 0.0f, -0.5f));
			this->b2->rotateByPointAbsolute(angle,   glm::vec3(-10.5f, 0.0f, -0.5f));
			this->b3->rotateByPointAbsolute(angle,   glm::vec3(-11.5f, 0.0f, -0.5f));
			this->b4->rotateByPointAbsolute(angle,   glm::vec3(-12.5f, 0.0f, -0.5f));
			this->b5->rotateByPointAbsolute(angle,   glm::vec3(-13.5f, 0.0f, -0.5f));
			this->b6->rotateByPointAbsolute(angle,   glm::vec3(-14.5f, 0.0f, -0.5f));
			this->b7->rotateByPointAbsolute(angle,   glm::vec3(-15.5f, 0.0f, -0.5f));

			
			this->o0->rotateByPointAbsolute(angle,   glm::vec3( -0.5f, 0.0f,  1.5f));
			this->o1->rotateByPointAbsolute(angle,   glm::vec3( -1.5f, 0.0f,  1.5f));
			this->o2->rotateByPointAbsolute(angle,   glm::vec3( -2.5f, 0.0f,  1.5f));
			this->o3->rotateByPointAbsolute(angle,   glm::vec3( -3.5f, 0.0f,  1.5f));
			this->o4->rotateByPointAbsolute(angle,   glm::vec3( -4.5f, 0.0f,  1.5f));
			this->o5->rotateByPointAbsolute(angle,   glm::vec3( -5.5f, 0.0f,  1.5f));
			this->o6->rotateByPointAbsolute(angle,   glm::vec3( -6.5f, 0.0f,  1.5f));
			this->o7->rotateByPointAbsolute(angle,   glm::vec3( -7.5f, 0.0f,  1.5f));
			this->cout->rotateByPointAbsolute(angle, glm::vec3(-15.5f, 0.0f,  1.5f));
		}

		this->oldPos = this->pos;
		this->oldRotation = this->rotation;
	}
	
	bool connect(std::map<Pos, std::vector<What>>* map) {
		Pos chip01;
		Pos chip02;
		Pos chip03;
		Pos chip04;
		Pos chip05;
		Pos chip06;
		Pos chip07;
		Pos chip08;
		Pos chip09;
		Pos chip10;
		Pos chip11;
		Pos chip12;
		Pos chip13;
		Pos chip14;
		Pos chip15;
		Pos chip16;
		Pos chip17;

		Pos in01;
		Pos in02;
		Pos in03;
		Pos in04;
		Pos in05;
		Pos in06;
		Pos in07;
		Pos in08;
		Pos in09;
		Pos in10;
		Pos in11;
		Pos in12;
		Pos in13;
		Pos in14;
		Pos in15;
		Pos in16;
		Pos in17;

		Pos out1;
		Pos out2;
		Pos out3;
		Pos out4;
		Pos out5;
		Pos out6;
		Pos out7;
		Pos out8;
		Pos out9;


		// pukty do sprawdzenia
		if (this->rotation == 0) {
			chip01 = { pos + glm::ivec3( 0, 0,  0) };
			chip02 = { pos + glm::ivec3( 1, 0,  0) };
			chip03 = { pos + glm::ivec3( 2, 0,  0) };
			chip04 = { pos + glm::ivec3( 3, 0,  0) };
			chip05 = { pos + glm::ivec3( 4, 0,  0) };
			chip06 = { pos + glm::ivec3( 5, 0,  0) };
			chip07 = { pos + glm::ivec3( 6, 0,  0) };
			chip08 = { pos + glm::ivec3( 7, 0,  0) };
			chip09 = { pos + glm::ivec3( 8, 0,  0) };
			chip10 = { pos + glm::ivec3( 9, 0,  0) };
			chip11 = { pos + glm::ivec3(10, 0,  0) };
			chip12 = { pos + glm::ivec3(11, 0,  0) };
			chip13 = { pos + glm::ivec3(12, 0,  0) };
			chip14 = { pos + glm::ivec3(13, 0,  0) };
			chip15 = { pos + glm::ivec3(14, 0,  0) };
			chip16 = { pos + glm::ivec3(15, 0,  0) };
			chip17 = { pos + glm::ivec3(16, 0,  0) };

			in01   = { pos + glm::ivec3( 0, 0,  1) };
			in02   = { pos + glm::ivec3( 1, 0,  1) };
			in03   = { pos + glm::ivec3( 2, 0,  1) };
			in04   = { pos + glm::ivec3( 3, 0,  1) };
			in05   = { pos + glm::ivec3( 4, 0,  1) };
			in06   = { pos + glm::ivec3( 5, 0,  1) };
			in07   = { pos + glm::ivec3( 6, 0,  1) };
			in08   = { pos + glm::ivec3( 7, 0,  1) };
			in09   = { pos + glm::ivec3( 8, 0,  1) };
			in10   = { pos + glm::ivec3( 9, 0,  1) };
			in11   = { pos + glm::ivec3(10, 0,  1) };
			in12   = { pos + glm::ivec3(11, 0,  1) };
			in13   = { pos + glm::ivec3(12, 0,  1) };
			in14   = { pos + glm::ivec3(13, 0,  1) };
			in15   = { pos + glm::ivec3(14, 0,  1) };
			in16   = { pos + glm::ivec3(15, 0,  1) };
			in17   = { pos + glm::ivec3(16, 0,  1) };

			out1   = { pos + glm::ivec3( 1, 0, -1) };
			out2   = { pos + glm::ivec3( 2, 0, -1) };
			out3   = { pos + glm::ivec3( 3, 0, -1) };
			out4   = { pos + glm::ivec3( 4, 0, -1) };
			out5   = { pos + glm::ivec3( 5, 0, -1) };
			out6   = { pos + glm::ivec3( 6, 0, -1) };
			out7   = { pos + glm::ivec3( 7, 0, -1) };
			out8   = { pos + glm::ivec3( 8, 0, -1) };
			out9   = { pos + glm::ivec3(16, 0, -1) };
		}
		else if (this->rotation == 1) {
			chip01 = { pos + glm::ivec3( 0, 0,   0) };
			chip02 = { pos + glm::ivec3( 0, 0,  -1) };
			chip03 = { pos + glm::ivec3( 0, 0,  -2) };
			chip04 = { pos + glm::ivec3( 0, 0,  -3) };
			chip05 = { pos + glm::ivec3( 0, 0,  -4) };
			chip06 = { pos + glm::ivec3( 0, 0,  -5) };
			chip07 = { pos + glm::ivec3( 0, 0,  -6) };
			chip08 = { pos + glm::ivec3( 0, 0,  -7) };
			chip09 = { pos + glm::ivec3( 0, 0,  -8) };
			chip10 = { pos + glm::ivec3( 0, 0,  -9) };
			chip11 = { pos + glm::ivec3( 0, 0, -10) };
			chip12 = { pos + glm::ivec3( 0, 0, -11) };
			chip13 = { pos + glm::ivec3( 0, 0, -12) };
			chip14 = { pos + glm::ivec3( 0, 0, -13) };
			chip15 = { pos + glm::ivec3( 0, 0, -14) };
			chip16 = { pos + glm::ivec3( 0, 0, -15) };
			chip17 = { pos + glm::ivec3( 0, 0, -16) };

			in01   = { pos + glm::ivec3( 1, 0,   0) };
			in02   = { pos + glm::ivec3( 1, 0,  -1) };
			in03   = { pos + glm::ivec3( 1, 0,  -2) };
			in04   = { pos + glm::ivec3( 1, 0,  -3) };
			in05   = { pos + glm::ivec3( 1, 0,  -4) };
			in06   = { pos + glm::ivec3( 1, 0,  -5) };
			in07   = { pos + glm::ivec3( 1, 0,  -6) };
			in08   = { pos + glm::ivec3( 1, 0,  -7) };
			in09   = { pos + glm::ivec3( 1, 0,  -8) };
			in10   = { pos + glm::ivec3( 1, 0,  -9) };
			in11   = { pos + glm::ivec3( 1, 0, -10) };
			in12   = { pos + glm::ivec3( 1, 0, -11) };
			in13   = { pos + glm::ivec3( 1, 0, -12) };
			in14   = { pos + glm::ivec3( 1, 0, -13) };
			in15   = { pos + glm::ivec3( 1, 0, -14) };
			in16   = { pos + glm::ivec3( 1, 0, -15) };
			in17   = { pos + glm::ivec3( 1, 0, -16) };

			out1   = { pos + glm::ivec3(-1, 0,  -1) };
			out2   = { pos + glm::ivec3(-1, 0,  -2) };
			out3   = { pos + glm::ivec3(-1, 0,  -3) };
			out4   = { pos + glm::ivec3(-1, 0,  -4) };
			out5   = { pos + glm::ivec3(-1, 0,  -5) };
			out6   = { pos + glm::ivec3(-1, 0,  -6) };
			out7   = { pos + glm::ivec3(-1, 0,  -7) };
			out8   = { pos + glm::ivec3(-1, 0,  -8) };
			out9   = { pos + glm::ivec3(-1, 0, -16) };
		}
		else if (this->rotation == 2) {
			chip01 = { pos + glm::ivec3(  0, 0,  0) };
			chip02 = { pos + glm::ivec3( -1, 0,  0) };
			chip03 = { pos + glm::ivec3( -2, 0,  0) };
			chip04 = { pos + glm::ivec3( -3, 0,  0) };
			chip05 = { pos + glm::ivec3( -4, 0,  0) };
			chip06 = { pos + glm::ivec3( -5, 0,  0) };
			chip07 = { pos + glm::ivec3( -6, 0,  0) };
			chip08 = { pos + glm::ivec3( -7, 0,  0) };
			chip09 = { pos + glm::ivec3( -8, 0,  0) };
			chip10 = { pos + glm::ivec3( -9, 0,  0) };
			chip11 = { pos + glm::ivec3(-10, 0,  0) };
			chip12 = { pos + glm::ivec3(-11, 0,  0) };
			chip13 = { pos + glm::ivec3(-12, 0,  0) };
			chip14 = { pos + glm::ivec3(-13, 0,  0) };
			chip15 = { pos + glm::ivec3(-14, 0,  0) };
			chip16 = { pos + glm::ivec3(-15, 0,  0) };
			chip17 = { pos + glm::ivec3(-16, 0,  0) };

			in01 = { pos + glm::ivec3(  0, 0,  -1) };
			in02 = { pos + glm::ivec3( -1, 0,  -1) };
			in03 = { pos + glm::ivec3( -2, 0,  -1) };
			in04 = { pos + glm::ivec3( -3, 0,  -1) };
			in05 = { pos + glm::ivec3( -4, 0,  -1) };
			in06 = { pos + glm::ivec3( -5, 0,  -1) };
			in07 = { pos + glm::ivec3( -6, 0,  -1) };
			in08 = { pos + glm::ivec3( -7, 0,  -1) };
			in09 = { pos + glm::ivec3( -8, 0,  -1) };
			in10 = { pos + glm::ivec3( -9, 0,  -1) };
			in11 = { pos + glm::ivec3(-10, 0,  -1) };
			in12 = { pos + glm::ivec3(-11, 0,  -1) };
			in13 = { pos + glm::ivec3(-12, 0,  -1) };
			in14 = { pos + glm::ivec3(-13, 0,  -1) };
			in15 = { pos + glm::ivec3(-14, 0,  -1) };
			in16 = { pos + glm::ivec3(-15, 0,  -1) };
			in17 = { pos + glm::ivec3(-16, 0,  -1) };

			out1 = { pos + glm::ivec3( -1, 0, 1) };
			out2 = { pos + glm::ivec3( -2, 0, 1) };
			out3 = { pos + glm::ivec3( -3, 0, 1) };
			out4 = { pos + glm::ivec3( -4, 0, 1) };
			out5 = { pos + glm::ivec3( -5, 0, 1) };
			out6 = { pos + glm::ivec3( -6, 0, 1) };
			out7 = { pos + glm::ivec3( -7, 0, 1) };
			out8 = { pos + glm::ivec3( -8, 0, 1) };
			out9 = { pos + glm::ivec3(-16, 0, 1) };
		}
		else if (this->rotation == 3) {
			chip01 = { pos + glm::ivec3(0, 0,  0) };
			chip02 = { pos + glm::ivec3(0, 0,  1) };
			chip03 = { pos + glm::ivec3(0, 0,  2) };
			chip04 = { pos + glm::ivec3(0, 0,  3) };
			chip05 = { pos + glm::ivec3(0, 0,  4) };
			chip06 = { pos + glm::ivec3(0, 0,  5) };
			chip07 = { pos + glm::ivec3(0, 0,  6) };
			chip08 = { pos + glm::ivec3(0, 0,  7) };
			chip09 = { pos + glm::ivec3(0, 0,  8) };
			chip10 = { pos + glm::ivec3(0, 0,  9) };
			chip11 = { pos + glm::ivec3(0, 0, 10) };
			chip12 = { pos + glm::ivec3(0, 0, 11) };
			chip13 = { pos + glm::ivec3(0, 0, 12) };
			chip14 = { pos + glm::ivec3(0, 0, 13) };
			chip15 = { pos + glm::ivec3(0, 0, 14) };
			chip16 = { pos + glm::ivec3(0, 0, 15) };
			chip17 = { pos + glm::ivec3(0, 0, 16) };
			
			in01 = { pos + glm::ivec3(-1, 0,  0) };
			in02 = { pos + glm::ivec3(-1, 0,  1) };
			in03 = { pos + glm::ivec3(-1, 0,  2) };
			in04 = { pos + glm::ivec3(-1, 0,  3) };
			in05 = { pos + glm::ivec3(-1, 0,  4) };
			in06 = { pos + glm::ivec3(-1, 0,  5) };
			in07 = { pos + glm::ivec3(-1, 0,  6) };
			in08 = { pos + glm::ivec3(-1, 0,  7) };
			in09 = { pos + glm::ivec3(-1, 0,  8) };
			in10 = { pos + glm::ivec3(-1, 0,  9) };
			in11 = { pos + glm::ivec3(-1, 0, 10) };
			in12 = { pos + glm::ivec3(-1, 0, 11) };
			in13 = { pos + glm::ivec3(-1, 0, 12) };
			in14 = { pos + glm::ivec3(-1, 0, 13) };
			in15 = { pos + glm::ivec3(-1, 0, 14) };
			in16 = { pos + glm::ivec3(-1, 0, 15) };
			in17 = { pos + glm::ivec3(-1, 0, 16) };
			
			out1 = { pos + glm::ivec3(1, 0,  1) };
			out2 = { pos + glm::ivec3(1, 0,  2) };
			out3 = { pos + glm::ivec3(1, 0,  3) };
			out4 = { pos + glm::ivec3(1, 0,  4) };
			out5 = { pos + glm::ivec3(1, 0,  5) };
			out6 = { pos + glm::ivec3(1, 0,  6) };
			out7 = { pos + glm::ivec3(1, 0,  7) };
			out8 = { pos + glm::ivec3(1, 0,  8) };
			out9 = { pos + glm::ivec3(1, 0, 16) };
		}
		else {
			return false;
		}


		// szukanie
		void* in01Ptr = NULL;
		void* in02Ptr = NULL;
		void* in03Ptr = NULL;
		void* in04Ptr = NULL;
		void* in05Ptr = NULL;
		void* in06Ptr = NULL;
		void* in07Ptr = NULL;
		void* in08Ptr = NULL;
		void* in09Ptr = NULL;
		void* in10Ptr = NULL;
		void* in11Ptr = NULL;
		void* in12Ptr = NULL;
		void* in13Ptr = NULL;
		void* in14Ptr = NULL;
		void* in15Ptr = NULL;
		void* in16Ptr = NULL;
		void* in17Ptr = NULL;
		void* out1Ptr = NULL;
		void* out2Ptr = NULL;
		void* out3Ptr = NULL;
		void* out4Ptr = NULL;
		void* out5Ptr = NULL;
		void* out6Ptr = NULL;
		void* out7Ptr = NULL;
		void* out8Ptr = NULL;
		void* out9Ptr = NULL;
		if (this->foundSomething(map, &chip01)) { return false; }
		if (this->foundSomething(map, &chip02)) { return false; }
		if (this->foundSomething(map, &chip03)) { return false; }
		if (this->foundSomething(map, &chip04)) { return false; }
		if (this->foundSomething(map, &chip05)) { return false; }
		if (this->foundSomething(map, &chip06)) { return false; }
		if (this->foundSomething(map, &chip07)) { return false; }
		if (this->foundSomething(map, &chip08)) { return false; }
		if (this->foundSomething(map, &chip09)) { return false; }
		if (this->foundSomething(map, &chip10)) { return false; }
		if (this->foundSomething(map, &chip11)) { return false; }
		if (this->foundSomething(map, &chip12)) { return false; }
		if (this->foundSomething(map, &chip13)) { return false; }
		if (this->foundSomething(map, &chip14)) { return false; }
		if (this->foundSomething(map, &chip15)) { return false; }
		if (this->foundSomething(map, &chip16)) { return false; }
		if (this->foundSomething(map, &chip17)) { return false; }
		if (!this->foundWire(map, &in01, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in02, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in03, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in04, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in05, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in06, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in07, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in08, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in09, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in10, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in11, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in12, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in13, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in14, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in15, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in16, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &in17, &in01Ptr)) { return false; }
		if (!this->foundWire(map, &out1, &out1Ptr)) { return false; }
		if (!this->foundWire(map, &out2, &out2Ptr)) { return false; }
		if (!this->foundWire(map, &out3, &out3Ptr)) { return false; }
		if (!this->foundWire(map, &out4, &out4Ptr)) { return false; }
		if (!this->foundWire(map, &out5, &out5Ptr)) { return false; }
		if (!this->foundWire(map, &out6, &out6Ptr)) { return false; }
		if (!this->foundWire(map, &out7, &out7Ptr)) { return false; }
		if (!this->foundWire(map, &out8, &out8Ptr)) { return false; }
		if (!this->foundWire(map, &out9, &out9Ptr)) { return false; }


		// jesli mo¿na stworzyc
		std::vector<What> c01{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c02{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c03{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c04{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c05{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c06{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c07{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c08{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c09{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c10{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c11{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c12{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c13{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c14{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c15{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c16{ What{ "chip ADDER8BIT", this } };
		std::vector<What> c17{ What{ "chip ADDER8BIT", this } };
		std::vector<What> i01{ What{ "input", this->cin } };
		std::vector<What> i02{ What{ "input", this->a0 } };
		std::vector<What> i03{ What{ "input", this->a1 } };
		std::vector<What> i04{ What{ "input", this->a2 } };
		std::vector<What> i05{ What{ "input", this->a3 } };
		std::vector<What> i06{ What{ "input", this->a4 } };
		std::vector<What> i07{ What{ "input", this->a5 } };
		std::vector<What> i08{ What{ "input", this->a6 } };
		std::vector<What> i09{ What{ "input", this->a7 } };
		std::vector<What> i10{ What{ "input", this->b0 } };
		std::vector<What> i11{ What{ "input", this->b1 } };
		std::vector<What> i12{ What{ "input", this->b2 } };
		std::vector<What> i13{ What{ "input", this->b3 } };
		std::vector<What> i14{ What{ "input", this->b4 } };
		std::vector<What> i15{ What{ "input", this->b5 } };
		std::vector<What> i16{ What{ "input", this->b6 } };
		std::vector<What> i17{ What{ "input", this->b7 } };
		std::vector<What> o1{ What{ "output", this->o0 } };
		std::vector<What> o2{ What{ "output", this->o1 } };
		std::vector<What> o3{ What{ "output", this->o2 } };
		std::vector<What> o4{ What{ "output", this->o3 } };
		std::vector<What> o5{ What{ "output", this->o4 } };
		std::vector<What> o6{ What{ "output", this->o5 } };
		std::vector<What> o7{ What{ "output", this->o6 } };
		std::vector<What> o8{ What{ "output", this->o7 } };
		std::vector<What> o9{ What{ "output", this->cout } };

		if (in01Ptr != NULL) {
			i01.push_back(What{ "wire", in01Ptr });
			((Wire*)in01Ptr)->outputs.push_back(this->cin);
		}
		if (in02Ptr != NULL) {
			i02.push_back(What{ "wire", in02Ptr });
			((Wire*)in02Ptr)->outputs.push_back(this->a0);
		}
		if (in03Ptr != NULL) {
			i03.push_back(What{ "wire", in03Ptr });
			((Wire*)in03Ptr)->outputs.push_back(this->a1);
		}
		if (in04Ptr != NULL) {
			i04.push_back(What{ "wire", in04Ptr });
			((Wire*)in04Ptr)->outputs.push_back(this->a2);
		}
		if (in05Ptr != NULL) {
			i05.push_back(What{ "wire", in05Ptr });
			((Wire*)in05Ptr)->outputs.push_back(this->a3);
		}
		if (in06Ptr != NULL) {
			i06.push_back(What{ "wire", in06Ptr });
			((Wire*)in06Ptr)->outputs.push_back(this->a4);
		}
		if (in07Ptr != NULL) {
			i07.push_back(What{ "wire", in07Ptr });
			((Wire*)in07Ptr)->outputs.push_back(this->a5);
		}
		if (in08Ptr != NULL) {
			i08.push_back(What{ "wire", in08Ptr });
			((Wire*)in08Ptr)->outputs.push_back(this->a6);
		}
		if (in09Ptr != NULL) {
			i09.push_back(What{ "wire", in09Ptr });
			((Wire*)in09Ptr)->outputs.push_back(this->a7);
		}
		if (in10Ptr != NULL) {
			i10.push_back(What{ "wire", in10Ptr });
			((Wire*)in10Ptr)->outputs.push_back(this->b0);
		}
		if (in11Ptr != NULL) {
			i11.push_back(What{ "wire", in11Ptr });
			((Wire*)in11Ptr)->outputs.push_back(this->b1);
		}
		if (in12Ptr != NULL) {
			i12.push_back(What{ "wire", in12Ptr });
			((Wire*)in12Ptr)->outputs.push_back(this->b2);
		}
		if (in13Ptr != NULL) {
			i13.push_back(What{ "wire", in13Ptr });
			((Wire*)in13Ptr)->outputs.push_back(this->b3);
		}
		if (in14Ptr != NULL) {
			i14.push_back(What{ "wire", in14Ptr });
			((Wire*)in14Ptr)->outputs.push_back(this->b4);
		}
		if (in15Ptr != NULL) {
			i15.push_back(What{ "wire", in15Ptr });
			((Wire*)in15Ptr)->outputs.push_back(this->b5);
		}
		if (in16Ptr != NULL) {
			i16.push_back(What{ "wire", in16Ptr });
			((Wire*)in16Ptr)->outputs.push_back(this->b6);
		}
		if (in17Ptr != NULL) {
			i17.push_back(What{ "wire", in17Ptr });
			((Wire*)in17Ptr)->outputs.push_back(this->b7);
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
			o1.push_back(What{ "wire", out8Ptr });
			((Wire*)out8Ptr)->inputs.push_back(this->o7);
		}
		if (out9Ptr != NULL) {
			o9.push_back(What{ "wire", out9Ptr });
			((Wire*)out9Ptr)->inputs.push_back(this->cout);
		}

		map->insert_or_assign(chip01, c01);
		map->insert_or_assign(chip02, c02);
		map->insert_or_assign(chip03, c03);
		map->insert_or_assign(chip04, c04);
		map->insert_or_assign(chip05, c05);
		map->insert_or_assign(chip06, c06);
		map->insert_or_assign(chip07, c07);
		map->insert_or_assign(chip08, c08);
		map->insert_or_assign(chip09, c09);
		map->insert_or_assign(chip10, c10);
		map->insert_or_assign(chip11, c11);
		map->insert_or_assign(chip12, c12);
		map->insert_or_assign(chip13, c13);
		map->insert_or_assign(chip14, c14);
		map->insert_or_assign(chip15, c15);
		map->insert_or_assign(chip16, c16);
		map->insert_or_assign(chip17, c17);

		map->insert_or_assign(in01, i01);
		map->insert_or_assign(in02, i02);
		map->insert_or_assign(in03, i03);
		map->insert_or_assign(in04, i04);
		map->insert_or_assign(in05, i05);
		map->insert_or_assign(in06, i06);
		map->insert_or_assign(in07, i07);
		map->insert_or_assign(in08, i08);
		map->insert_or_assign(in09, i09);
		map->insert_or_assign(in10, i10);
		map->insert_or_assign(in11, i11);
		map->insert_or_assign(in12, i12);
		map->insert_or_assign(in13, i13);
		map->insert_or_assign(in14, i14);
		map->insert_or_assign(in15, i15);
		map->insert_or_assign(in16, i16);
		map->insert_or_assign(in17, i17);

		map->insert_or_assign(out1, o1);
		map->insert_or_assign(out2, o2);
		map->insert_or_assign(out3, o3);
		map->insert_or_assign(out4, o4);
		map->insert_or_assign(out5, o5);
		map->insert_or_assign(out6, o6);
		map->insert_or_assign(out7, o7);
		map->insert_or_assign(out8, o8);
		map->insert_or_assign(out9, o9);

		return true;
	}

	void update() {
		int a = 0;
		if (this->a0->state) {
			a = a + 128;
		}
		if (this->a1->state) {
			a = a + 64;
		}
		if (this->a2->state) {
			a = a + 32;
		}
		if (this->a3->state) {
			a = a + 16;
		}
		if (this->a4->state) {
			a = a + 8;
		}
		if (this->a5->state) {
			a = a + 4;
		}
		if (this->a6->state) {
			a = a + 2;
		}
		if (this->a7->state) {
			a = a + 1;
		}

		int b = 0;
		if (this->b0->state) {
			b = b + 128;
		}
		if (this->b1->state) {
			b = b + 64;
		}
		if (this->b2->state) {
			b = b + 32;
		}
		if (this->b3->state) {
			b = b + 16;
		}
		if (this->b4->state) {
			b = b + 8;
		}
		if (this->b5->state) {
			b = b + 4;
		}
		if (this->b6->state) {
			b = b + 2;
		}
		if (this->b7->state) {
			b = b + 1;
		}

		int c = 0;
		if (this->cin->state) {
			c = c + 1;
		}

		int res = a + b + c;

		this->o7->state = false;
		this->o6->state = false;
		this->o5->state = false;
		this->o4->state = false;
		this->o3->state = false;
		this->o2->state = false;
		this->o1->state = false;
		this->o0->state = false;
		this->cout->state = false;
		if (res % 2 == 1) {
			this->o7->state = true;
		}
		if ((res / 2) % 2) {
			this->o6->state = true;
		}
		if ((res / 4) % 2) {
			this->o5->state = true;
		}
		if ((res / 8) % 2) {
			this->o4->state = true;
		}
		if ((res / 16) % 2) {
			this->o3->state = true;
		}
		if ((res / 32) % 2) {
			this->o2->state = true;
		}
		if ((res / 64) % 2) {
			this->o1->state = true;
		}
		if ((res / 128) % 2) {
			this->o0->state = true;
		}
		if ((res / 256) % 2) {
			this->cout->state = true;
		}
	}

	void draw() {
		this->chip->draw();

		this->a0->draw();
		this->a1->draw();
		this->a2->draw();
		this->a3->draw();
		this->a4->draw();
		this->a5->draw();
		this->a6->draw();
		this->a7->draw();

		this->b0->draw();
		this->b1->draw();
		this->b2->draw();
		this->b3->draw();
		this->b4->draw();
		this->b5->draw();
		this->b6->draw();
		this->b7->draw();

		this->o0->draw();
		this->o1->draw();
		this->o2->draw();
		this->o3->draw();
		this->o4->draw();
		this->o5->draw();
		this->o6->draw();
		this->o7->draw();

		this->cin->draw();
		this->cout->draw();
	}

	~GateADDER8BIT() {
		delete this->chip;

		delete this->a0;
		delete this->a1;
		delete this->a2;
		delete this->a3;
		delete this->a4;
		delete this->a5;
		delete this->a6;
		delete this->a7;

		delete this->b0;
		delete this->b1;
		delete this->b2;
		delete this->b3;
		delete this->b4;
		delete this->b5;
		delete this->b6;
		delete this->b7;

		delete this->o0;
		delete this->o1;
		delete this->o2;
		delete this->o3;
		delete this->o4;
		delete this->o5;
		delete this->o6;
		delete this->o7;

		delete this->cin;
		delete this->cout;
	}
};