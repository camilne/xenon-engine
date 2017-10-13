#ifndef XENON_RENDERER_HPP
#define XENON_RENDERER_HPP

#include <glad/glad.h>

namespace xe {

class Renderer {
public:
    GLint getFrame();
private:
    GLint frameBuffer_;
};

}

#endif //XENON_RENDERER_HPP
