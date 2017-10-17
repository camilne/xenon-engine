#include "Engine.hpp"
#include "Renderer.hpp"

int main(int argc, char* argv[]) {
    xe::Engine engine;

    engine.createWindow(1280, 720, "My Basic Window");
    engine.attachRenderer(std::make_unique<Renderer>(1280, 720));
    engine.run([](){});

    return 0;
}