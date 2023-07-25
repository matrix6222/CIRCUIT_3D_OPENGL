class Output {
private:
	Model* model;
public:
	bool state = false;
	glm::ivec3 pos;

	Output() {
		this->model = new Model("Models3D/Output/model.obj", glm::vec3(0.9f, 0.9f, 0.0f));
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
	~Output() {
		delete this->model;
	}
};