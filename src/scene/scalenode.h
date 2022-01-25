#ifndef SCALENODE_H
#define SCALENODE_H

#include "node.h"

class ScaleNode : public Node
{
private:
    float sx;
    float sy;

public:
    ScaleNode();
    ScaleNode(QString name, float sx, float sy);
    virtual ~ScaleNode();

    float getsx();
    float getsy();

    void setScale(float sx, float sy);

    glm::mat3 transform() override;
};

#endif // SCALENODE_H
