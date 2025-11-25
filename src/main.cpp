#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window/window.hpp"
#include "shaderL/shaderl.hpp"
#include "renderer/renderer.hpp"

int main() {
    Window window(800, 600, "SpaceTime");

    if (!window.getGLFWwindow()) return -1;

    // Make context current before GLEW
    glfwMakeContextCurrent(window.getGLFWwindow());

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW!" << std::endl;
        return -1;
    }

    Renderer renderer;
    renderer.init(); // safe now, GL context exists

    int screenWidth, screenHeight;
    glfwGetWindowSize(window.getGLFWwindow(), &screenWidth, &screenHeight);
    std::cout << "Startup size: " << screenWidth << "x" << screenHeight << std::endl;

    while (!window.shouldClose()) {
        glfwGetWindowSize(window.getGLFWwindow(), &screenWidth, &screenHeight);

        glEnable(GL_DEPTH_TEST);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        renderer.draw(screenWidth, screenHeight);

        window.swapBuffers();
        window.pollEvents();
    }

    return 0;
}