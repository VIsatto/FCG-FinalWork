#ifndef _COLISSION_H
#define _COLISSION_H

#include "glm/glm.hpp"
#include <vector>
#include "../Structures/structures.h"




bool ColisionAABB(const AABB& a, const AABB& b);
bool WallsCollision(glm::vec4* obj_position, float obj_half_size = 1.0);
bool ProjectileCollision(glm::vec4 projectile_position ,float projectile_half_size, std::vector<Robotnik> &enemies);
bool EnemyColission(std::vector<Robotnik> &enemies, int ind);

#endif 