#ifndef OPENGL_DEMO_DEMO_H
#define OPENGL_DEMO_DEMO_H

#include "engine/camera.h"

class Demo {
public:
    explicit Demo(Camera* camera);
    virtual ~Demo() = default;

    virtual void render() = 0;
    virtual void update(float delta_seconds) = 0;

protected:
    Camera* camera_;
};

#endif //OPENGL_DEMO_DEMO_H
