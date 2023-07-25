class Gate {
private:
protected:
	bool foundSomething(std::map<Pos, std::vector<What>>* map, Pos* pos) {
		auto search = map->find(*pos);
		if (search != map->end()) {
			return true;
		}
		return false;
	}
	bool foundWire(std::map<Pos, std::vector<What>>* map, Pos* pos, void** wirePtr) {
		auto search = map->find(*pos);
		if (search != map->end()) {
			for (size_t x = 0; x < search->second.size(); x++) {
				if (search->second[x].name != "wire") {
					return false;
				}
				else {
					*wirePtr = search->second[x].ptr;
					return true;
				}
			}
		}
		return true;
	}
public:
	Gate() {

	}

	virtual bool connect(std::map<Pos, std::vector<What>>* map) {
		return false;
	}

	virtual void update() {

	}

	virtual void draw() {

	}
};