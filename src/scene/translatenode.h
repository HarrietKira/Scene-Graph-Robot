#ifndef TRANSLATENODE_H
#define TRANSLATENODE_H

#include "node.h"

class TranslateNode : public Node
{
private:
    float tx;
    float ty;

public:
    // constructors
    TranslateNode();
    TranslateNode(QString name, float tx, float ty);
    virtual ~TranslateNode();

    // get member values
    float gettx();
    float getty();

    // set translation parameters
    void setTranslate(float tx, float ty);

    // override transformation matrix
    glm::mat3 transform() override;
};

#endif // TRANSLATENODE_H
