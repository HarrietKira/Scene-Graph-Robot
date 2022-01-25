#include "translatenode.h"

// constructors
TranslateNode::TranslateNode()
             : Node("translate node")
{}
TranslateNode::TranslateNode(QString name, float tx, float ty)
             : Node(name), tx(tx), ty(ty)
{}
TranslateNode::~TranslateNode()
{}

// get member values
float TranslateNode::gettx()
{
    return this->tx;
}
float TranslateNode::getty()
{
    return this->ty;
}
// set translation parameters
void TranslateNode::setTranslate(float tx, float ty)
{
    this->tx = tx;
    this->ty = ty;
}

// override transformation matrix
glm::mat3 TranslateNode::transform()
{
    glm::mat3 m = glm::mat3(1, 0, 0,
                            0, 1, 0,
                            this->tx, this->ty, 1);
    return m;
}

