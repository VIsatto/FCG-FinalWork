#include "rings.h"
#include "../Bezier/bezier.h"


Rings CreateRing(std::vector<glm::vec4> control_points) {
    Rings ring;
    ring.current_position = control_points[0];
    ring.curve_positions = BezierCurve(control_points);
    ring.animation_ind = 0.0f; 
    ring.angle_rot = 0.0f;
    return ring;
}

std::vector<Rings> InicializeRings(){

    std::vector<Rings> all_rings;
    std::vector<glm::vec4> control_points;

    control_points.push_back(glm::vec4(30.0f, 15.0f, 30.0f, 1.0f));
    control_points.push_back(glm::vec4(15.0f, 15.0f, 20.0f, 1.0f));
    control_points.push_back(glm::vec4(25.0f, 15.0f, 40.0f, 1.0f));
    control_points.push_back(glm::vec4(30.0f, 15.0f, 30.0f, 1.0f));
    all_rings.push_back(CreateRing(control_points));
    control_points.clear();

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


    return all_rings;
}