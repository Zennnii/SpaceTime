#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

class Grid {
    public:

        struct Vertex {
            glm::vec3 position;
        };

        void generateGridVertices(std::vector<Vertex>& vertices, int N, float SIZE);
        void generateGridLineIndices(std::vector<unsigned int>& indices, int N);
        void setupGrid(GLuint &VAO, GLuint &VBO, GLuint &EBO, int N, float SIZE);
        void drawGrid(GLuint VAO, int indexCount);
};
