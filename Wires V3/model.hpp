#pragma once
#ifndef MODEL_HPP
#define MODEL_HPP
#endif


class Model {
private:
    Shader shader;
    glm::mat4 model;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int texture;
    GLsizei verticesLen;
    bool isTexture;
    glm::vec3 pos;

    std::vector<std::string> split(std::string s, std::string delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        std::string token;
        std::vector<std::string> res;

        while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
            token = s.substr(pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back(token);
        }

        res.push_back(s.substr(pos_start));
        return res;
    }
public:
    glm::vec3 color;

    Model() {

    }

    Model(std::string modelPath) {
        this->shader = Shader("solid.vert", "solid.frag");
        this->color = glm::vec3(0.8f, 0.8f, 0.8f);
        this->pos = glm::vec3(0.0f, 0.0f, 0.0f);
        this->model = glm::mat4(1.0f);
        this->isTexture = false;

        std::vector<std::vector<float>> v;
        std::vector<std::vector<float>> vn;
        std::vector<float> vertices; // x, y, z, nx, ny, nz

        std::ifstream t(modelPath);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        std::vector<std::string> lines = this->split(str, "\n");
        for (size_t x = 0; x < lines.size(); x++) {
            std::vector<std::string> temp = this->split(lines[x], " ");
            if (temp[0] == "v") {
                // TODO check is float
                float px = std::stof(temp[1]);
                float py = std::stof(temp[2]);
                float pz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(px);
                cache.push_back(py);
                cache.push_back(pz + 1);
                v.push_back(cache);
            }
            else if (temp[0] == "vn") {
                // TODO check is float
                float nx = std::stof(temp[1]);
                float ny = std::stof(temp[2]);
                float nz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(nx);
                cache.push_back(ny);
                cache.push_back(nz);
                vn.push_back(cache);
            }
            else if (temp[0] == "f") {
                std::vector<std::string> a = this->split(temp[1], "//");
                std::vector<std::string> b = this->split(temp[2], "//");
                std::vector<std::string> c = this->split(temp[3], "//");
                int av = std::stoi(a[0]) - 1;
                int an = std::stoi(a[1]) - 1;
                int bv = std::stoi(b[0]) - 1;
                int bn = std::stoi(b[1]) - 1;
                int cv = std::stoi(c[0]) - 1;
                int cn = std::stoi(c[1]) - 1;

                vertices.push_back(v[av][0]);  // a vx
                vertices.push_back(v[av][1]);  // a vy
                vertices.push_back(v[av][2]);  // a vz
                vertices.push_back(vn[an][0]); // a nx
                vertices.push_back(vn[an][1]); // a ny
                vertices.push_back(vn[an][2]); // a nz

                vertices.push_back(v[bv][0]);  // b vx
                vertices.push_back(v[bv][1]);  // b vy
                vertices.push_back(v[bv][2]);  // b vz
                vertices.push_back(vn[bn][0]); // b nx
                vertices.push_back(vn[bn][1]); // b ny
                vertices.push_back(vn[bn][2]); // b nz

                vertices.push_back(v[cv][0]);  // c vx
                vertices.push_back(v[cv][1]);  // c vy
                vertices.push_back(v[cv][2]);  // c vz
                vertices.push_back(vn[cn][0]); // c nx
                vertices.push_back(vn[cn][1]); // c ny
                vertices.push_back(vn[cn][2]); // c nz
            }
        }

        this->verticesLen = vertices.size() / 6;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    Model(std::string modelPath, glm::vec3 color, bool flippedIO = false) {
        this->shader = Shader("solid.vert", "solid.frag");
        this->pos = glm::vec3(0.0f, 0.0f, 0.0f);
        this->model = glm::mat4(1.0f);
        this->isTexture = false;
        this->color = color;

        std::vector<std::vector<float>> v;
        std::vector<std::vector<float>> vn;
        std::vector<float> vertices; // x, y, z, nx, ny, nz

        std::ifstream t(modelPath);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        std::vector<std::string> lines = this->split(str, "\n");
        for (size_t x = 0; x < lines.size(); x++) {
            std::vector<std::string> temp = this->split(lines[x], " ");
            if (temp[0] == "v") {
                // TODO check is float
                float px = std::stof(temp[1]);
                float py = std::stof(temp[2]);
                float pz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(px);
                cache.push_back(py);
                if (!flippedIO) {
                    cache.push_back(pz + 1);
                }
                else {
                    cache.push_back(-pz);
                }
                v.push_back(cache);
            }
            else if (temp[0] == "vn") {
                // TODO check is float
                float nx = std::stof(temp[1]);
                float ny = std::stof(temp[2]);
                float nz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(nx);
                cache.push_back(ny);
                if (!flippedIO) {
                    cache.push_back(nz);
                }
                else {
                    cache.push_back(-nz);
                }
                vn.push_back(cache);
            }
            else if (temp[0] == "f") {
                std::vector<std::string> a = this->split(temp[1], "//");
                std::vector<std::string> b = this->split(temp[2], "//");
                std::vector<std::string> c = this->split(temp[3], "//");
                int av = std::stoi(a[0]) - 1;
                int an = std::stoi(a[1]) - 1;
                int bv = std::stoi(b[0]) - 1;
                int bn = std::stoi(b[1]) - 1;
                int cv = std::stoi(c[0]) - 1;
                int cn = std::stoi(c[1]) - 1;

                vertices.push_back(v[av][0]);  // a vx
                vertices.push_back(v[av][1]);  // a vy
                vertices.push_back(v[av][2]);  // a vz
                vertices.push_back(vn[an][0]); // a nx
                vertices.push_back(vn[an][1]); // a ny
                vertices.push_back(vn[an][2]); // a nz

                vertices.push_back(v[bv][0]);  // b vx
                vertices.push_back(v[bv][1]);  // b vy
                vertices.push_back(v[bv][2]);  // b vz
                vertices.push_back(vn[bn][0]); // b nx
                vertices.push_back(vn[bn][1]); // b ny
                vertices.push_back(vn[bn][2]); // b nz

                vertices.push_back(v[cv][0]);  // c vx
                vertices.push_back(v[cv][1]);  // c vy
                vertices.push_back(v[cv][2]);  // c vz
                vertices.push_back(vn[cn][0]); // c nx
                vertices.push_back(vn[cn][1]); // c ny
                vertices.push_back(vn[cn][2]); // c nz
            }
        }

        this->verticesLen = vertices.size() / 6;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    Model(std::string modelPath, std::string texturePath) {
        this->color = glm::vec3(0.8f, 0.8f, 0.8f);
        this->pos = glm::vec3(0.0f, 0.0f, 0.0f);
        this->model = glm::mat4(1.0f);
        this->isTexture = true;

        std::vector<std::vector<float>> v;
        std::vector<std::vector<float>> vt;
        std::vector<std::vector<float>> vn;
        std::vector<float> vertices; // x, y, z, nx, ny, nz, tx, ty

        std::ifstream t(modelPath);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        std::vector<std::string> lines = this->split(str, "\n");
        for (size_t x = 0; x < lines.size(); x++) {
            std::vector<std::string> temp = this->split(lines[x], " ");
            if (temp[0] == "v") {
                // TODO check is float
                float px = std::stof(temp[1]);
                float py = std::stof(temp[2]);
                float pz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(px);
                cache.push_back(py);
                cache.push_back(pz + 1);
                v.push_back(cache);
            }
            else if (temp[0] == "vn") {
                // TODO check is float
                float nx = std::stof(temp[1]);
                float ny = std::stof(temp[2]);
                float nz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(nx);
                cache.push_back(ny);
                cache.push_back(nz);
                vn.push_back(cache);
            }
            else if (temp[0] == "vt") {
                // TODO check is float
                float tx = std::stof(temp[1]);
                float ty = std::stof(temp[2]);

                std::vector<float> cache;
                cache.push_back(tx);
                cache.push_back(ty);
                vt.push_back(cache);
            }
            else if (temp[0] == "f") {
                std::vector<std::string> a = this->split(temp[1], "/");
                std::vector<std::string> b = this->split(temp[2], "/");
                std::vector<std::string> c = this->split(temp[3], "/");
                int av = std::stoi(a[0]) - 1;
                int at = std::stoi(a[1]) - 1;
                int an = std::stoi(a[2]) - 1;
                int bv = std::stoi(b[0]) - 1;
                int bt = std::stoi(b[1]) - 1;
                int bn = std::stoi(b[2]) - 1;
                int cv = std::stoi(c[0]) - 1;
                int ct = std::stoi(c[1]) - 1;
                int cn = std::stoi(c[2]) - 1;

                vertices.push_back(v[av][0]);  // a vx
                vertices.push_back(v[av][1]);  // a vy
                vertices.push_back(v[av][2]);  // a vz
                vertices.push_back(vn[an][0]); // a nx
                vertices.push_back(vn[an][1]); // a ny
                vertices.push_back(vn[an][2]); // a nz
                vertices.push_back(vt[at][0]); // a tx
                vertices.push_back(vt[at][1]); // a ty

                vertices.push_back(v[bv][0]);  // b vx
                vertices.push_back(v[bv][1]);  // b vy
                vertices.push_back(v[bv][2]);  // b vz
                vertices.push_back(vn[bn][0]); // b nx
                vertices.push_back(vn[bn][1]); // b ny
                vertices.push_back(vn[bn][2]); // b nz
                vertices.push_back(vt[bt][0]); // b tx
                vertices.push_back(vt[bt][1]); // b ty

                vertices.push_back(v[cv][0]);  // c vx
                vertices.push_back(v[cv][1]);  // c vy
                vertices.push_back(v[cv][2]);  // c vz
                vertices.push_back(vn[cn][0]); // c nx
                vertices.push_back(vn[cn][1]); // c ny
                vertices.push_back(vn[cn][2]); // c nz
                vertices.push_back(vt[ct][0]); // c tx
                vertices.push_back(vt[ct][1]); // c ty
            }
        }

        this->verticesLen = vertices.size() / 8;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            if (nrChannels == 3) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                this->shader = Shader("solidTex.vert", "solidTex.frag");
            }
            else if (nrChannels == 4) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                this->shader = Shader("solidTexA.vert", "solidTexA.frag");
            }
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }

    Model(std::string modelPath, std::string texturePath, glm::vec3 color) {
        this->pos = glm::vec3(0.0f, 0.0f, 0.0f);
        this->model = glm::mat4(1.0f);
        this->isTexture = true;
        this->color = color;

        std::vector<std::vector<float>> v;
        std::vector<std::vector<float>> vt;
        std::vector<std::vector<float>> vn;
        std::vector<float> vertices; // x, y, z, nx, ny, nz, tx, ty

        std::ifstream t(modelPath);
        std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());
        std::vector<std::string> lines = this->split(str, "\n");
        for (size_t x = 0; x < lines.size(); x++) {
            std::vector<std::string> temp = this->split(lines[x], " ");
            if (temp[0] == "v") {
                // TODO check is float
                float px = std::stof(temp[1]);
                float py = std::stof(temp[2]);
                float pz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(px);
                cache.push_back(py);
                cache.push_back(pz + 1);
                v.push_back(cache);
            }
            else if (temp[0] == "vn") {
                // TODO check is float
                float nx = std::stof(temp[1]);
                float ny = std::stof(temp[2]);
                float nz = std::stof(temp[3]);

                std::vector<float> cache;
                cache.push_back(nx);
                cache.push_back(ny);
                cache.push_back(nz);
                vn.push_back(cache);
            }
            else if (temp[0] == "vt") {
                // TODO check is float
                float tx = std::stof(temp[1]);
                float ty = std::stof(temp[2]);

                std::vector<float> cache;
                cache.push_back(tx);
                cache.push_back(ty);
                vt.push_back(cache);
            }
            else if (temp[0] == "f") {
                std::vector<std::string> a = this->split(temp[1], "/");
                std::vector<std::string> b = this->split(temp[2], "/");
                std::vector<std::string> c = this->split(temp[3], "/");
                int av = std::stoi(a[0]) - 1;
                int at = std::stoi(a[1]) - 1;
                int an = std::stoi(a[2]) - 1;
                int bv = std::stoi(b[0]) - 1;
                int bt = std::stoi(b[1]) - 1;
                int bn = std::stoi(b[2]) - 1;
                int cv = std::stoi(c[0]) - 1;
                int ct = std::stoi(c[1]) - 1;
                int cn = std::stoi(c[2]) - 1;

                vertices.push_back(v[av][0]);  // a vx
                vertices.push_back(v[av][1]);  // a vy
                vertices.push_back(v[av][2]);  // a vz
                vertices.push_back(vn[an][0]); // a nx
                vertices.push_back(vn[an][1]); // a ny
                vertices.push_back(vn[an][2]); // a nz
                vertices.push_back(vt[at][0]); // a tx
                vertices.push_back(vt[at][1]); // a ty

                vertices.push_back(v[bv][0]);  // b vx
                vertices.push_back(v[bv][1]);  // b vy
                vertices.push_back(v[bv][2]);  // b vz
                vertices.push_back(vn[bn][0]); // b nx
                vertices.push_back(vn[bn][1]); // b ny
                vertices.push_back(vn[bn][2]); // b nz
                vertices.push_back(vt[bt][0]); // b tx
                vertices.push_back(vt[bt][1]); // b ty

                vertices.push_back(v[cv][0]);  // c vx
                vertices.push_back(v[cv][1]);  // c vy
                vertices.push_back(v[cv][2]);  // c vz
                vertices.push_back(vn[cn][0]); // c nx
                vertices.push_back(vn[cn][1]); // c ny
                vertices.push_back(vn[cn][2]); // c nz
                vertices.push_back(vt[ct][0]); // c tx
                vertices.push_back(vt[ct][1]); // c ty
            }
        }

        this->verticesLen = vertices.size() / 8;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glGenTextures(1, &this->texture);
        glBindTexture(GL_TEXTURE_2D, this->texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        int width, height, nrChannels;
        stbi_set_flip_vertically_on_load(true);
        unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            if (nrChannels == 3) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
                this->shader = Shader("solidTex.vert", "solidTex.frag");
            }
            else if (nrChannels == 4) {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                this->shader = Shader("solidTexA.vert", "solidTexA.frag");
            }
            glGenerateMipmap(GL_TEXTURE_2D);
        }
        else {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
    }

    //void move(glm::vec3 vec) {
    //    this->model = glm::translate(this->model, vec);
    //    this->pos = this->pos + vec;
    //}

    void moveAbsolute(glm::vec3 newPos) {
        //this->model = glm::translate(this->model, -this->pos);
        //this->model = glm::translate(this->model, newPos);
        //this->pos = newPos;

        this->model = glm::translate(glm::mat4(1.0f), newPos);
        this->pos = newPos;
    }

    //void rotateByPoint(float angle, glm::vec3 point) {
    //    this->model = glm::translate(this->model, point);
    //    this->model = glm::rotate(this->model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
    //    this->model = glm::translate(this->model, -point);
    //}

    void rotateByPointAbsolute(float angle, glm::vec3 point) {
        //this->model = glm::translate(glm::mat4(1.0f), this->pos);
        //this->model = glm::translate(this->model, point);
        //this->model = glm::rotate(this->model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
        //this->model = glm::translate(this->model, -point);

        this->model = glm::translate(glm::mat4(1.0f), this->pos);
        this->model = glm::translate(this->model, point);
        this->model = glm::rotate(this->model, angle, glm::vec3(0.0f, 1.0f, 0.0f));
        this->model = glm::translate(this->model, -point);
    }

    void draw() {
        glBindVertexArray(VAO);
        if (this->isTexture) {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texture);
        }
        glUseProgram(shader.shaderProgram);
        if (this->isTexture) {
            glUniform1i(glGetUniformLocation(shader.shaderProgram, "texture1"), 0);
        }
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glUniformMatrix4fv(glGetUniformLocation(shader.shaderProgram, "proj"), 1, GL_FALSE, glm::value_ptr(proj));
        glUniform3fv(glGetUniformLocation(shader.shaderProgram, "objectColor"), 1, glm::value_ptr(color));
        glUniform3fv(glGetUniformLocation(shader.shaderProgram, "viewPos"), 1, glm::value_ptr(player.pos));
        glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirX"), player.angleX);
        glUniform1f(glGetUniformLocation(shader.shaderProgram, "viewDirY"), player.angleY);

        glDrawArrays(GL_TRIANGLES, 0, this->verticesLen);
    }

    ~Model() {
        glDeleteVertexArrays(1, &this->VAO);
        glDeleteBuffers(1, &this->VBO);
        if (this->isTexture) {
            glDeleteTextures(1, &this->texture);
        }
    }
};