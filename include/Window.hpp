#ifndef XENON_WINDOW_HPP
#define XENON_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <string>
#include <functional>

namespace xe {

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    static void setErrorCallback(GLFWerrorfun callback);
    void setKeyCallback(GLFWkeyfun callback);
    void setCursorPosCallback(GLFWcursorposfun callback);

    void setWindowUserPointer(void* pointer) const;

    bool shouldClose() const;
    void update() const;

    int getWidth() const;
    int getHeight() const;
private:
    GLFWwindow* handle_;
    int width_;
    int height_;
    std::string title_;

    void init();
    void createWindowHandle();
};

}


#endif //XENON_WINDOW_HPP
