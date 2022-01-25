#include "node.h"

Node::Node()
    : QTreeWidgetItem(), name(), polygon(nullptr), color(), children()
{
    this->QTreeWidgetItem::setText(0, this->name);
}
Node::Node(QString name)
    : QTreeWidgetItem(), name(name), polygon(nullptr), color(), children()
{
    this->QTreeWidgetItem::setText(0, this->name);
}
Node::~Node()
{}

Polygon2D* Node::getPolygon()
{
    return this->polygon;
}
glm::vec3 Node::getColor()
{
    return this->color;
}
QString Node::getName()
{
    return this->name;
}


void Node::setColor(glm::vec3 color)
{
    this->color[0] = color[0];
    this->color[1] = color[1];
    this->color[2] = color[2];
}
void Node::setPolygon(Polygon2D &polygon)
{
    this->polygon = &polygon;
}

Node& Node::addChild(uPtr<Node> node)
{
    Node& ref = *node;
    this->children.push_back(std::move(node));
    QTreeWidgetItem::addChild(&ref);
    return ref;
}












