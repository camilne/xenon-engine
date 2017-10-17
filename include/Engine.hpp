#ifndef XENON_ENGINE_HPP
#define XENON_ENGINE_HPP

#include <memory>
#include <glad/glad.h>
#include "Window.hpp"
#include "IRenderer.hpp"
#include "IApplication.hpp"

namespace xe {

class Engine {
public:
    Engine();

    void createWindow(int width, int height, std::string title);
    void attachApplication(std::unique_ptr<IApplication> application);
    void run();
private:
    std::unique_ptr<Window> window_;
    std::unique_ptr<IApplication> application_;

    static void kDefaultErrorFun(int error, const char* description);
};

}

#endif //XENON_ENGINE_HPP
