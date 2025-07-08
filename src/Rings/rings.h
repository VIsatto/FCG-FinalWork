#ifndef _RINGS_H
#define _RINGS_H

#include <vector>
#include "../Structures/structures.h"

std::vector<Rings> InicializeRings();
Rings CreateRing(std::vector<glm::vec4> control_points);

#endif //_RINGS_H