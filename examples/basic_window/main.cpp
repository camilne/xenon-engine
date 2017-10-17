#include "Engine.hpp"
#include "Application.hpp"

int main(int argc, char* argv[]) {
    xe::Engine engine;

    engine.createWindow(1280, 720, "My Basic Window");
    engine.attachApplication(std::make_unique<Application>(1280, 720));
    engine.run();

    return 0;
}