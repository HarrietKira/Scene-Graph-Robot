#include "scalenode.h"

ScaleNode::ScaleNode()
         : Node("scale node")
{}
ScaleNode::ScaleNode(QString name, float sx, float sy)
         : Node(name), sx(sx), sy(sy)
{}
ScaleNode::~ScaleNode()
{}

float ScaleNode::getsx()
{
    return this->sx;
}
float ScaleNode::getsy()
{
    return this->sy;
}

void ScaleNode::setScale(float sx, float sy)
{
    this->sx = sx;
    this->sy = sy;
}

glm::mat3 ScaleNode::transform()
{
    glm::mat3 m = glm::mat3(this->sx, 0, 0,
                            0, this->sy, 0,
                            0, 0, 1);
    return m;
}
