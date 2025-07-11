#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include "glm/glm.hpp"


struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

struct Robotnik{
    glm::vec4 position; // Posição do Robotnik
    float angle; // Ângulo de rotação do Robotnik
    AABB aabb; //Hitbot do Robotnik
    int health = 3; // Número de vidas do Robotnik
};

struct Projectile {
    glm::vec4 position; // Posição do projétil
    glm::vec4 direction; // Direção do projétil
    bool shot; // Velocidade do projétil
    float rotation; //Angulo para operações de rotação com o projétil
};

struct Rings{
    std::vector<glm::vec4> curve_positions; // Posições da curva de bezier
    glm::vec4 current_position; // Posição atual do anel
    float animation_ind; //Indice para controlar a animação
    float angle_rot; //Angulo para operações de rotação com o anel
};

#endif // _STRUCTURES_H