#ifndef XENON_WINDOW_HPP
#define XENON_WINDOW_HPP

#include <GLFW/glfw3.h>
#include <string>
#include <functional>

namespace xe {

class Window {
public:
    Window();
    Window(int width, int height, const std::string& title);
    ~Window();

    static void setErrorCallback(GLFWerrorfun callback);

    static void init();

    bool shouldClose() const;
    void update() const;

    int getWidth() const;
    int getHeight() const;
private:
    const int kDefaultWidth = 640;
    const int kDefaultHeight = 480;
    const std::string kDefaultTitle = "";

    GLFWwindow* handle_;
    int width_;
    int height_;
    std::string title_;

    void createWindowHandle();
};

}


#endif //XENON_WINDOW_HPP
