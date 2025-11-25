#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp> 
#include "renderer/renderer.hpp"
#include "grid/grid.hpp"

Renderer::Renderer()
    : VAO(0), VBO(0), EBO(0),
      shader("shaders/vertex.glsl", "shaders/fragment.glsl"),
      N(25), SIZE(10.0f) // default grid parameters
{}

Renderer::~Renderer() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void Renderer::init() {
    // Setup the grid
    grid.setupGrid(VAO, VBO, EBO, N, SIZE);

    // Calculate number of indices (6 per cell)
    indexCount = N * N * 6;
    glEnable(GL_DEPTH_TEST);
}

void Renderer::draw(int screenWidth, int screenHeight) {
    shader.use();

    glm::mat4 proj = glm::perspective(glm::radians(45.0f),
                                  (float)screenWidth / screenHeight,
                                  0.1f, 100.0f);
    glm::mat4 view = glm::lookAt(glm::vec3(10.0f, 10.0f, 10.0f), // camera position
                                  glm::vec3(0.0f, 0.0f, 0.0f),    // target
                                  glm::vec3(0.0f, 1.0f, 0.0f));   // up vector
    glm::mat4 mvp = proj * view;
    GLint projLoc = glGetUniformLocation(shader.getID(), "projection");
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(mvp));

    // Draw the grid
    grid.drawGrid(VAO, indexCount);
}
