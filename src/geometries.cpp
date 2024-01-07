#include "geometries.hpp"

bool Sphere::CheckCollision(glm::vec3 cameraPosition, glm::vec3 ray, float& t0, float& t1) const {
    float a = glm::dot(ray, ray);
    float b = 2 * (glm::dot(ray, cameraPosition) - glm::dot(ray, m_center));
    float c = glm::dot(cameraPosition, cameraPosition) - 2 * glm::dot(cameraPosition, m_center) + glm::dot(m_center, m_center) - m_radius * m_radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        return false;
    }
    else {
        t0 = (-b - glm::sqrt(discriminant)) / (2 * a);
        t1 = (-b + glm::sqrt(discriminant)) / (2 * a);
        return true;
    }
}
