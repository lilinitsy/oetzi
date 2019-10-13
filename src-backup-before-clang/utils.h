#ifndef UTILS_H
#define UTILS_H

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtx/string_cast.hpp"

glm::mat4 setModel(glm::vec3 translation, glm::vec3 scale, float rotationRadians, glm::vec3 rotate)
{
    glm::mat4 model;
    model = glm::translate(model, translation);
    model = glm::scale(model, scale);
    model = glm::rotate(model, rotationRadians, rotate);

    return model;
}


#endif
