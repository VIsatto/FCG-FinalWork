#ifndef _BEZIER_H
#define _BEZIER_H

#include "glm/glm.hpp"
#include <vector>


void BezierPoint(std::vector<glm::vec4> &curve_points, float t, glm::vec4 p1, glm::vec4 p2);
std::vector<glm::vec4> TrdBezierCurve(std::vector<glm::vec4> ctrl_points, int degree, int t);

#endif // _BEZIER_H