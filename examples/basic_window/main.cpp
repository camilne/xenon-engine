#include "Engine.hpp"

int main(int argc, char* argv[]) {
    xe::Engine engine;

    engine.createWindow(1280, 720, "My Basic Window");

    // Set the clear color to a nice green
    glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

    engine.run();

    return 0;
}