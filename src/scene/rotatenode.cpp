#include "rotatenode.h"

RotateNode::RotateNode()
          : Node("rotate node")
{}
RotateNode::RotateNode(QString name, float angle)
          : Node(name), angle(angle)
{}
RotateNode::~RotateNode()
{}

float RotateNode::getangle()
{
    return this->angle;
}

void RotateNode::setangle(float angle)
{
    this->angle = angle;
}

glm::mat3 RotateNode::transform()
{
    float angle_rad = glm::radians(this->angle);
    glm::mat3 m = glm::mat3(cos(angle_rad), sin(angle_rad), 0,
                            - sin(angle_rad), cos(angle_rad), 0,
                            0, 0, 1);
    return m;
}
