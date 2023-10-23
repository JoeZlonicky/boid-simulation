#ifndef IK_DEMO_INVERSE_KINEMATICS_H
#define IK_DEMO_INVERSE_KINEMATICS_H

#include <vector>
#include "limb.h"


namespace inverse_kinematics {
    void perform(std::vector<Limb>& limbs, float time);
}

#endif
