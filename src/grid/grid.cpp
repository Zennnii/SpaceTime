#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "renderer/renderer.hpp"
#include "grid/grid.hpp"

struct Vertex {
    glm::vec3 position;
};

// Generate verticies
void Grid::generateGridVertices(std::vector<Vertex>& vertices, int N, float SIZE) {
    float HALF = SIZE / 2.0f;
    for (int z = 0; z <= N; z++) {
        for (int x = 0; x <= N; x++) {
            float xpos = ((float)x / N) * SIZE - HALF;
            float zpos = ((float)z / N) * SIZE - HALF;
            float ypos = 0.0f;
            vertices.push_back({ glm::vec3(xpos, ypos, zpos) });
        }
    }
}

// Generate indices for triangles
void Grid::generateGridLineIndices(std::vector<unsigned int>& indices, int N) {
    // horizontal lines
    for (int z = 0; z <= N; z++) {
        for (int x = 0; x < N; x++) {
            int start = z * (N + 1) + x;
            indices.push_back(start);
            indices.push_back(start + 1);
        }
    }

    // vertical lines
    for (int x = 0; x <= N; x++) {
        for (int z = 0; z < N; z++) {
            int start = z * (N + 1) + x;
            indices.push_back(start);
            indices.push_back(start + (N + 1));
        }
    }
}
// Initialize VAO, VBO, and EBO
void Grid::setupGrid(GLuint &VAO, GLuint &VBO, GLuint &EBO, int N, float SIZE) {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    generateGridVertices(vertices, N, SIZE);
    generateGridLineIndices(indices, N);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    // Vertex buffer
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

    // Element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    // Vertex attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}

// Draw the grid
void Grid::drawGrid(GLuint VAO, int indexCount) {
    glBindVertexArray(VAO);
    glDrawElements(GL_LINES, indexCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}