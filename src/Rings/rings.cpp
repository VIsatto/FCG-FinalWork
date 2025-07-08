#include "rings.h"
#include "../Bezier/bezier.h"

//Função de instanciação dos aneis
Rings CreateRing(std::vector<glm::vec4> control_points) {
    Rings ring;
    ring.current_position = control_points[0];
    ring.curve_positions = BezierCurve(control_points);
    ring.animation_ind = 0.0f; 
    ring.angle_rot = 0.0f;
    return ring;
}

//Função para definir os pontros de controles de cada anel que será posteriormente utilizado para descobrir a curva de bezier e animá-lo
std::vector<Rings> InicializeRings(){

    std::vector<Rings> all_rings;
    std::vector<glm::vec4> control_points;

    //Aqui inserimos pontos de ctronole manualmente
    control_points.push_back(glm::vec4(30.0f, 15.0f, 30.0f, 1.0f));
    control_points.push_back(glm::vec4(15.0f, 15.0f, 20.0f, 1.0f));
    control_points.push_back(glm::vec4(25.0f, 15.0f, 40.0f, 1.0f));
    control_points.push_back(glm::vec4(30.0f, 15.0f, 30.0f, 1.0f));
    //Criamos o anel com estes pontos de controles
    all_rings.push_back(CreateRing(control_points));
    //Limpamos o vetor
    control_points.clear();
    //Repetimos o processo mais 3 vezes
    control_points.push_back(glm::vec4(-30.0f, 15.0f, 30.0f, 1.0f));
    control_points.push_back(glm::vec4(-20.0f, 15.0f, 15.0f, 1.0f));
    control_points.push_back(glm::vec4(-40.0f, 15.0f, 25.0f, 1.0f));
    control_points.push_back(glm::vec4(-30.0f, 15.0f, 30.0f, 1.0f));
    all_rings.push_back(CreateRing(control_points));
    control_points.clear();


    control_points.push_back(glm::vec4(30.0f, 15.0f, -30.0f, 1.0f));
    control_points.push_back(glm::vec4(15.0f, 15.0f, -20.0f, 1.0f));
    control_points.push_back(glm::vec4(25.0f, 15.0f, -40.0f, 1.0f));
    control_points.push_back(glm::vec4(30.0f, 15.0f, -30.0f, 1.0f));
    all_rings.push_back(CreateRing(control_points));
    control_points.clear();

    control_points.push_back(glm::vec4(-30.0f, 15.0f, -30.0f, 1.0f));
    control_points.push_back(glm::vec4(-15.0f, 15.0f, -20.0f, 1.0f));
    control_points.push_back(glm::vec4(-25.0f, 15.0f, -40.0f, 1.0f));
    control_points.push_back(glm::vec4(-30.0f, 15.0f, -30.0f, 1.0f));
    all_rings.push_back(CreateRing(control_points));
    control_points.clear();

    //Retornamos o vetor com 4 aneis dentro
    return all_rings;
}