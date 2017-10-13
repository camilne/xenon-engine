#ifndef XENON_WINDOW_HPP
#define XENON_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <string>

namespace xe {

class Window {
public:
    Window(int width, int height, const std::string& title);
    ~Window();

    bool shouldClose() const;
    void update() const;
private:
    GLFWwindow* handle_;
    int width_;
    int height_;
    std::string title_;

    void init();
};

}


#endif //XENON_WINDOW_HPP
