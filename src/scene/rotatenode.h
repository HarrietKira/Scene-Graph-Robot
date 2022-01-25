#ifndef ROTATENODE_H
#define ROTATENODE_H

#include "node.h"

class RotateNode : public Node
{
private:
    float angle;
public:
    RotateNode();
    RotateNode(QString name, float angle);
    virtual ~RotateNode();

    float getangle();

    void setangle(float angle);

    glm::mat3 transform() override;
};

#endif // ROTATENODE_H
