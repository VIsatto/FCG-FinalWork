#include "bezier.h"

void BezierPoint(std::vector<glm::vec4> &curve_points, float t, glm::vec4 p1, glm::vec4 p2) {
    // Calcula a posição do ponto na curva de Bézier cúbica
    glm::vec4 point = p1 + (p2 - p1) * t;
    curve_points.push_back(point);
}

std::vector<glm::vec4> TrdBezierCurve(std::vector<glm::vec4> ctrl_points, int degree, int t) {
    std::vector<glm::vec4> final_points;
    for (int i = 0; i < degree - 1; i++) {
        glm::vec4 p1 = ctrl_points[i];
        glm::vec4 p2 = ctrl_points[i + 1];
        BezierPoint(final_points, t, p1, p2);
    }
    if(degree > 1)
        final_points = TrdBezierCurve(final_points, degree - 1, t);
    return final_points;
}
