#include "Engine.hpp"

void render();

int main(int argc, char* argv[]) {
    xe::Engine engine;

    engine.createWindow(1280, 720, "My Basic Window");
    engine.attachRenderer(render);
    engine.run();

    return 0;
}

void render() {
    
}