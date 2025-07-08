#include "collision.h"



bool ColisionAABB(const AABB& a, const AABB& b) {
    // Verifica se há sobreposição em cada eixo
    bool over_X = (a.min.x <= b.max.x && a.max.x >= b.min.x);
    bool over_Y = (a.min.y <= b.max.y && a.max.y >= b.min.y);
    bool over_Z = (a.min.z <= b.max.z && a.max.z >= b.min.z);

    // Se houver sobreposição em TODOS os eixos, há colisão
    return over_X && over_Y && over_Z;
}

bool WallsCollision(glm::vec4* obj_position, float obj_half_size){
    // Limites do ambiente (ajuste conforme necessário)
    bool collision = false;
    float min_x = -50.0f + obj_half_size;
    float max_x =  50.0f - obj_half_size;
    float min_z = -50.0f + obj_half_size;
    float max_z =  50.0f - obj_half_size;

    // Checa e corrige colisão com as paredes
    if (obj_position->x < min_x) {
        obj_position->x = min_x;
        collision = true;
    }
    if (obj_position->x > max_x) {
        obj_position->x = max_x;
        collision = true;
    }
    if (obj_position->z < min_z) {
        obj_position->z = min_z;
        collision = true;}
    if (obj_position->z > max_z) {
        obj_position->z = max_z;
        collision = true;
    }
    return collision;
}

bool ProjectileCollision(glm::vec4 projectile_position ,float projectile_half_size, std::vector<Robotnik> &enemies) {
    AABB projec_aabb;
    projec_aabb.min = glm::vec3(projectile_position.x - 1.0f, projectile_position.y - 1.0f, projectile_position.z - 1.0f);
    projec_aabb.max = glm::vec3(projectile_position.x + 1.0f, projectile_position.y + 1.0f, projectile_position.z + 1.0f);
    for(int i=0; i < enemies.size(); i++) {
        if (ColisionAABB(projec_aabb, enemies[i].aabb)) {
            enemies[i].health -= 1; // Diminui a vida do inimigo
            return true;
        }
    }
    if (WallsCollision(&projectile_position, projectile_half_size)) {
        // Se a colisão for com as paredes, retornamos false
        return true;
    }
    return false;
}