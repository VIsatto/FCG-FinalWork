#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include "glm/glm.hpp"


struct AABB {
    glm::vec3 min;
    glm::vec3 max;
};

// Definimos uma estrutura que armazenará dados necessários para renderizar
// cada objeto da cena virtu
struct Robotnik{
    glm::vec4 position; // Posição do Robotnik
    float angle; // Ângulo de rotação do Robotnik
    AABB aabb;
    int health = 3; // Número de vidas do Robotnik
};

struct Projectile {
    glm::vec4 position; // Posição do projétil
    glm::vec4 direction; // Direção do projétil
    bool shot; // Velocidade do projétil
    float rotation;
};

struct Rings{
    std::vector<glm::vec4> curve_positions; // Posições dos anéis
    glm::vec4 current_position;
    float animation_ind; // Posição do anel
    float angle_rot;
};

#endif // _STRUCTURES_H