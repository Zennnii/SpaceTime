#pragma once
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "shaderL/shaderl.hpp"
#include "grid/grid.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();
        
        void init();
        void draw(int screenWidth, int screenHeight);

        std::vector<Grid::Vertex> vertices;
        std::vector<unsigned int> indices;

        int numVertices;
        unsigned int indexCount;

    private:
        GLuint VAO, VBO, EBO;
        Shader shader;
        Grid grid;

        int N;
        float SIZE;
};