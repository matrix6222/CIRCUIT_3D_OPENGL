class Input {
private:
	Model* model;
public:
	bool state = false;
	glm::ivec3 pos;

	Input(bool flippedIO = false) {
		this->model = new Model("Models3D/Input/model.obj", glm::vec3(0.9f, 0.9f, 0.9f), flippedIO);
	}
	void draw() {
		this->model->draw();
	}
	void moveAbsolute(glm::ivec3 pos) {
		this->pos = pos;
		this->model->moveAbsolute(pos);
	}
	void rotateByPointAbsolute(float angle, glm::vec3 point) {
		this->model->rotateByPointAbsolute(angle, point);
	}
	~Input() {
		delete this->model;
	}
};