#include "collision.h"


//Função para checagem de colisão AABB
bool ColisionAABB(const AABB& a, const AABB& b) {
    // Verifica se há sobreposição em cada eixo
    bool over_X = (a.min.x <= b.max.x && a.max.x >= b.min.x);
    bool over_Y = (a.min.y <= b.max.y && a.max.y >= b.min.y);
    bool over_Z = (a.min.z <= b.max.z && a.max.z >= b.min.z);

    // Se houver sobreposição em TODOS os eixos, há colisão
    return over_X && over_Y && over_Z;
}

bool ColisionPointAABB(glm::vec4 pos, const AABB& a) {
    // Verifica se há sobreposição em cada eixo
    bool over_X = (pos.x <= a.max.x && pos.x >= a.min.x);
    bool over_Y = (pos.y <= a.max.y && pos.y >= a.min.y);
    bool over_Z = (pos.z <= a.max.z && pos.z >= a.min.z);

    // Se houver sobreposição em TODOS os eixos, há colisão
    return over_X && over_Y && over_Z;
}
//Função para checagem de colisão com os muros
bool WallsCollision(glm::vec4* obj_position, float obj_half_size){
    // Limites do ambiente (ajuste conforme necessário)
    bool collision = false;
    float min_x = -100.0f + obj_half_size;
    float max_x =  100.0f - obj_half_size;
    float min_z = -100.0f + obj_half_size;
    float max_z =  100.0f - obj_half_size;

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
//Função de checagem da colisão do projétil
bool ProjectileCollision(glm::vec4 projectile_position ,float projectile_half_size, std::vector<Robotnik> &enemies) {
    for(int i=0; i < enemies.size(); i++) {
        //Caso tiver colisão com um inimigo, retornamos true
        if (ColisionPointAABB(projectile_position, enemies[i].aabb)) {
            enemies[i].health -= 1; // Diminui a vida do inimigo
            return true; 
        }
    }
    // Se a colisão for com as paredes, retornamos true
    if (WallsCollision(&projectile_position, projectile_half_size)) {
        return true;
    }
    return false;
}

//Função de checagem de colisão de inimigos entre si
bool EnemyColission(std::vector<Robotnik> &enemies, int ind) {
    bool collision = false;
    for (int i = 0; i < enemies.size(); i++) {
        if( i != ind && enemies[i].health != 0) 
            if (ColisionAABB(enemies[ind].aabb, enemies[i].aabb)) collision = true;
}   //Retorna true em caso de colisão
    return collision;
}