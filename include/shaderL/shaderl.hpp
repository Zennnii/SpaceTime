#pragma once
#include <string>
#include <GL/glew.h>

class Shader {
    public:
        // Constructor loads, compiles, and links shaders from files
        Shader(const std::string& vertexPath, const std::string& fragmentPath);

        // Use the shader program
        void use() const;

        // Get the underlying program ID
        GLuint getID() const;

    private:
        GLuint ID;
};