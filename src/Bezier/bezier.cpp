#include "bezier.h"

std::vector<glm::vec4> BezierCurve(std::vector<glm::vec4> ctrl_points) {
    int values = 100;
    std::vector<float> t_values;
    std::vector<glm::vec4> curve_points;
    glm::vec4 point;

    if (ctrl_points.size() < 2) {
        return curve_points; // Retorna um vetor vazio se não houver pontos suficientes
    }
    
    for(int i =0; i< values; i++){
        t_values.push_back(i);
    }
    for (int i = 0; i < t_values.size(); i++) {
        t_values[i] /= (values - 1); // Normaliza os valores de t entre 0 e 1
    }

    for (float t : t_values) {
        point = static_cast<float>(std::pow(1 - t, 3)) * ctrl_points[0] + 
                static_cast<float>(3 * t * std::pow(1 - t, 2)) * ctrl_points[1] + 
                static_cast<float>(3 * std::pow(t, 2) * (1 - t)) * ctrl_points[2] + 
                static_cast<float>(std::pow(t, 3)) * ctrl_points[3];
        curve_points.push_back(point);
    }
    return curve_points;
}
