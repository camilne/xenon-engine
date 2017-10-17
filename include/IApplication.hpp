#ifndef XENON_IAPPLICATION_HPP
#define XENON_IAPPLICATION_HPP

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Input.hpp"
#include <iostream>

namespace xe {

class IApplication {
    friend class Engine;
public:
    IApplication(int width, int height);

    GLuint getFrame() const;
    void preRender() const;
    void postRender() const;
protected:
    int width_;
    int height_;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void keyPressed(int key, int mods) {}
    virtual void keyReleased(int key, int mods) {}
private:
    GLuint frameBuffer_;
    GLuint renderedTexture_;

    void initFramebuffer();

    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

}

#endif //XENON_IAPPLICATION_HPP
