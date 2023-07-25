#ifdef __cplusplus
extern "C" {
#endif

    __declspec(dllexport) unsigned int NvOptimusEnablement = 1;
    __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;

#ifdef __cplusplus
}
#endif

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
//#include <chrono>

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

unsigned int steps = 1;
void print(std::string str, glm::ivec3 vec) {
    std::cout << str << ": " << vec.x << " " << vec.y << " " << vec.z << std::endl;
}

// 1 - clickable
// 2 - wire
// 3 - button
// 4 - lamp
// 5 - AND gate
// 6 - NOT gate
// 7 - REGISTER8 gate
// 8 - 7SEGMENT4BIT gate
// 9 - ADDER8BIT gate
int mode = 0;
int rotation = 0;
glm::mat4 proj;
glm::mat4 view;

#include "window.hpp"
#include "shader.hpp"
#include "player.hpp"

Window windowObj = Window(1280, 720);
GLFWwindow* window = windowObj.window;
Player player = Player(window);

struct Pos {
    glm::ivec3 pos;

    bool operator<(const Pos& other) const {
        if (pos.x < other.pos.x) return true;
        if (pos.x > other.pos.x) return false;
        if (pos.y < other.pos.y) return true;
        if (pos.y > other.pos.y) return false;
        return pos.z < other.pos.z;
    }
};
struct What {
    std::string name;
    void* ptr;
};
std::map<Pos, std::vector<What>> map;

#include "model.hpp"

const glm::vec3 COLORON  = glm::vec3(1.0f, 0.0f, 0.0f);
const glm::vec3 COLOROFF = glm::vec3(0.5f, 0.0f, 0.0f);
#include "input.hpp"
#include "output.hpp"
#include "wire.hpp"
#include "cube.hpp"
#include "button.hpp"
#include "lamp.hpp"
#include "gate.hpp"
#include "gateNOT.hpp"
#include "gateAND.hpp"
#include "gateREGISTER8.hpp"
#include "gate7SEGMENT4BIT.hpp"
#include "gateADDER8BIT.hpp"


Button buttonObj = Button(glm::ivec3(0, 0, 0), 0);
Lamp lampObj = Lamp(glm::ivec3(0, 0, 0), 0);
GateAND gateAND = GateAND(glm::ivec3(0, 0, 0), 0);
GateNOT gateNOT = GateNOT(glm::ivec3(0, 0, 0), 0);
GateREGISTER8 gateREGISTER8 = GateREGISTER8(glm::ivec3(0, 0, 0), 0);
Gate7SEGMENT4BIT gate7SEGMENT4BIT = Gate7SEGMENT4BIT(glm::ivec3(0, 0, 0), 0);
GateADDER8BIT gateADDER8BIT = GateADDER8BIT(glm::ivec3(0, 0, 0), 0);
Wire wireObj = Wire(glm::ivec3(0, 0, 0));
int wireState = 0;
std::vector<Gate*> gates;
std::vector<Button*> buttons;
std::vector<Lamp*> lamps;
std::vector<Wire*> wires;



void window_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    windowObj.resX = width;
    windowObj.resY = height;
    windowObj.calcProj();
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, true);
        }

        else if (key == GLFW_KEY_R) {
            rotation = (rotation + 1) % 4;
        }

        else if (key == GLFW_KEY_0) {
            mode = 0;
            wireState = 0;
        }
        else if (key == GLFW_KEY_1) {
            mode = 1;
            wireState = 0;
        }
        else if (key == GLFW_KEY_2) {
            mode = 2;
            wireState = 0;
        }
        else if (key == GLFW_KEY_3) {
            mode = 3;
            wireState = 0;
        }
        else if (key == GLFW_KEY_4) {
            mode = 4;
            wireState = 0;
        }
        else if (key == GLFW_KEY_5) {
            mode = 5;
            wireState = 0;
        }
        else if (key == GLFW_KEY_6) {
            mode = 6;
            wireState = 0;
        }
        else if (key == GLFW_KEY_7) {
            mode = 7;
            wireState = 0;
        }
        else if (key == GLFW_KEY_8) {
            mode = 8;
            wireState = 0;
        }
        else if (key == GLFW_KEY_9) {
            mode = 9;
            wireState = 0;
        }

        else if (key == GLFW_KEY_KP_ADD) {
            steps++;
        }
        else if (key == GLFW_KEY_KP_SUBTRACT) {
            steps--;
            if (steps < 1) {
                steps = 1;
            }
        }
    }
}
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    // clickable
    if (mode == 1) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            std::cout << "click at: " << player.posBlockLookAt.x << " " << player.posBlockLookAt.y << " " << player.posBlockLookAt.z << ": ";
            //std::cout << std::endl;
            Pos pos = { player.posBlockLookAt };
            auto search = map.find(pos);
            if (search != map.end()) {
                std::vector<What> whats = search->second;
                for (size_t x = 0; x < whats.size(); x++) {
                    if (whats[x].name == "chip button") {
                        ((Button*)(whats[x].ptr))->click();
                    }
                    std::cout << whats[x].name << " ";
                }
                std::cout << std::endl;
            }
        }
    }
    
    // wire creation
    else if (mode == 2) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && wireState == 0) {
            wireState = 1;
            wireObj = Wire(player.posBlockLookAt);
        }
        else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS && wireState == 1) {
            wireState = 0;
            Wire* wir = new Wire(glm::ivec3(0, 0, 0));
            wir->lines = wireObj.lines;
            wir->genBuffer();
            if (wir->connect(&map, &wires)) {
                wires.push_back(wir);
            }
            else {
                delete wir;
            }
        }
    }

    // button creation
    else if (mode == 3) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Button* butt = new Button(buttonObj.pos, rotation);
            if (butt->connect(&map)) {
                buttons.push_back(butt);
            }
            else {
                delete butt;
            }
        }
    }
    
    // lamp creation
    else if (mode == 4) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Lamp* lamp = new Lamp(lampObj.pos, rotation);
            if (lamp->connect(&map)) {
                lamps.push_back(lamp);
            }
            else {
                delete lamp;
            }
        }
    }
    
    // gate AND creation
    else if (mode == 5) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Gate* gate = new GateAND(gateAND.pos, rotation);
            if (gate->connect(&map)) {
                gates.push_back(gate);
            }
            else {
                delete gate;
            }
        }
    }
    
    // gate NOT creation
    else if (mode == 6) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Gate* gate = new GateNOT(gateNOT.pos, rotation);
            if (gate->connect(&map)) {
                gates.push_back(gate);
            }
            else {
                delete gate;
            }
        }
    }

    // gate REGISTER8 creation
    else if (mode == 7) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Gate* gate = new GateREGISTER8(gateREGISTER8.pos, rotation);
            if (gate->connect(&map)) {
                gates.push_back(gate);
            }
            else {
                delete gate;
            }
        }
    }

    // gate 7SEGMENT4BIT creation
    else if (mode == 8) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Gate* gate = new Gate7SEGMENT4BIT(gate7SEGMENT4BIT.pos, rotation);
            if (gate->connect(&map)) {
                gates.push_back(gate);
            }
            else {
                delete gate;
            }
        }
    }

    // gate ADDER8BIT creation
    else if (mode == 9) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            Gate* gate = new GateADDER8BIT(gateADDER8BIT.pos, rotation);
            if (gate->connect(&map)) {
                gates.push_back(gate);
            }
            else {
                delete gate;
            }
        }
    }
}

int main(int argc, char** argv) {
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);
    glfwSetKeyCallback(window, key_callback);

    while (!glfwWindowShouldClose(window)) {
        player.update();


        for (int y = 0; y < steps; y++) {
            // circut update
            for (size_t x = 0; x < wires.size(); x++) {
                wires[x]->update();
            }
            for (size_t x = 0; x < lamps.size(); x++) {
                lamps[x]->update();
            }
            for (size_t x = 0; x < gates.size(); x++) {
                gates[x]->update();
            }
        }

        //glClearColor(0.13f, 0.13f, 0.13f, 1.0f);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        //glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        player.draw();

        // creation
        if (mode == 2 && wireState == 1) {
            wireObj.setEndPos(player.posBlockLookAt);
            wireObj.draw();
        }
        else if (mode == 3) {
            buttonObj.moveAbsolute(player.posBlockLookAt, rotation);
            buttonObj.draw();
        }
        else if (mode == 4) {
            lampObj.moveAbsolute(player.posBlockLookAt, rotation);
            lampObj.draw();
        }
        else if (mode == 5) {
            gateAND.moveAbsolute(player.posBlockLookAt, rotation);
            gateAND.draw();
        }
        else if (mode == 6) {
            gateNOT.moveAbsolute(player.posBlockLookAt, rotation);
            gateNOT.draw();
        }
        else if (mode == 7) {
            gateREGISTER8.moveAbsolute(player.posBlockLookAt, rotation);
            gateREGISTER8.draw();
        }
        else if (mode == 8) {
            gate7SEGMENT4BIT.moveAbsolute(player.posBlockLookAt, rotation);
            gate7SEGMENT4BIT.draw();
        }
        else if (mode == 9) {
            gateADDER8BIT.moveAbsolute(player.posBlockLookAt, rotation);
            gateADDER8BIT.draw();
        }


        // draw
        for (size_t x = 0; x < gates.size(); x++) {
            gates[x]->draw();
        }
        for (size_t x = 0; x < buttons.size(); x++) {
            buttons[x]->draw();
        }
        for (size_t x = 0; x < lamps.size(); x++) {
            lamps[x]->draw();
        }
        for (size_t x = 0; x < wires.size(); x++) {
            wires[x]->draw();
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    // delete
    // std::vector<Gate*> gates;
    // std::vector<Button*> buttons;
    // std::vector<Lamp*> lamps;
    // std::vector<Wire*> wires;
    for (size_t x = 0; x < gates.size(); x++) {
        delete gates[x];
    }
    for (size_t x = 0; x < buttons.size(); x++) {
        delete buttons[x];
    }
    for (size_t x = 0; x < lamps.size(); x++) {
        delete lamps[x];
    }
    for (size_t x = 0; x < wires.size(); x++) {
        delete wires[x];
    }

    glfwTerminate();
    return 0;
}