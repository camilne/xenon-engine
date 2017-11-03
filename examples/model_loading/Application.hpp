#ifndef XENON_APPLICATION_HPP
#define XENON_APPLICATION_HPP

#include <IApplication.hpp>
#include <Shader.hpp>
#include <glm/glm.hpp>
#include <Camera.hpp>
#include <Mesh.hpp>
#include <Model.hpp>

class Application : public xe::IApplication {
public:
    Application(int width, int height);
protected:
    virtual void init();
    virtual void update();
    virtual void render();
private:
    std::unique_ptr<Model> model_;
    xe::Shader shader_;
    xe::Camera camera_;
};


#endif //XENON_APPLICATION_HPP
