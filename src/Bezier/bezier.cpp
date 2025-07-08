#include "bezier.h"


void BezierPoint(std::vector<glm::vec4> &curve_points, float t, glm::vec4 p1, glm::vec4 p2) {
    // Calcula a posição do ponto na curva de Bézier cúbica
    glm::vec4 point = p1 + (p2 - p1) * t;
    curve_points.push_back(point);
}

std::vector<glm::vec4> BezierLoop(std::vector<glm::vec4> ctrl_points, int degree, float t) {
    std::vector<glm::vec4> curve_points;
    for (int i = 0; i < degree - 1; i++) {
        glm::vec4 p1 = ctrl_points[i];
        glm::vec4 p2 = ctrl_points[i + 1];
        BezierPoint(curve_points, t, p1, p2);
    }
    if(degree > 0)
        curve_points = BezierLoop(curve_points, degree - 1, t);
    return curve_points;
}

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
        std::vector<glm::vec4> segment_points = BezierLoop(ctrl_points, ctrl_points.size() - 1, t);
        point = segment_points[0]; // Pega o primeiro ponto do segmento
        curve_points.push_back(point);
    }
    return curve_points;
}
