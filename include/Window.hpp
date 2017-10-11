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
        GLFWwindow* m_handle;
        int m_width;
        int m_height;
        std::string m_title;

        void init();
    };

}


#endif //XENON_WINDOW_HPP
