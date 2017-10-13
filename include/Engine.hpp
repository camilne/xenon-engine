#ifndef XENON_ENGINE_HPP
#define XENON_ENGINE_HPP

namespace xe {

class Engine {
public:
    void setErrorCallback(std::function<void(int, const char*)>);
};

}

#endif //XENON_ENGINE_HPP
