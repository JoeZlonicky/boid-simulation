#include "inverse_kinematics.h"


namespace inverse_kinematics {
    void perform(std::vector<Limb>& limbs, float time) {
        if (limbs.empty()) {
            return;
        }

        const Limb* previous = &limbs.at(0);
        const float rotation_increment = std::sin(time * 2.f) * 15.f;
        float rotation = rotation_increment;
        for (int i = 1; i < limbs.size(); ++i) {
            Limb& current = limbs.at(i);
            current.getTransform().setPos(previous->getEnd());
            current.getTransform().setRotation({{0, 0, 1}, rotation});
            previous = &current;
            rotation += rotation_increment;
        }
    }
}